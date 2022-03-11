/// \file h5hep/io.hxx
/// \author Javier Lopez-Gomez <j.lopez@cern.ch>
/// \date 2021-11-05
///
/// \brief Header-only library to read/write high-energy physics data in HDF5.
/// For benchmark purposes only; do NOT use in production.

#ifndef _H5HEP_IO_HXX
#define _H5HEP_IO_HXX

#include <h5hep/common.hxx>
#include <h5hep/schema.hxx>

#include <hdf5.h>

#include <cstring>
#include <memory>
#include <numeric>
#include <stdexcept>
#include <string_view>
#include <vector>

namespace h5hep {

  namespace internal {
    /// \brief Given `extents`, determine the minimum dataset size required to satisfy a R/W operation
    static inline size_t GetMinimumDatasetSize(const std::vector<Span> &extents) {
      return std::accumulate(extents.begin(), extents.end(), 0,
			     [] (size_t a, const Span &b) { return std::max(a, (b.offset + b.len)); });
    }

    static inline hsize_t GetDataspaceSize(hid_t spaceId) {
      hsize_t ret;
      H5Sget_simple_extent_dims(spaceId, &ret, NULL);
      return ret;
    }

    /// \brief Reference implementation of `ReadExtents()`. Column models may call this as part of
    /// `XxxNode::ReadExtents()`. Data for each entry in `extents` is copied contiguously in `buf`.
    static inline size_t SimpleReadExtents(const std::vector<Span> &extents, void *buf,
					   hid_t datasetId, hid_t spaceId, hid_t typeId) {
      const size_t dataspaceSize = GetDataspaceSize(spaceId);
      auto p = reinterpret_cast<unsigned char*>(buf);
      size_t count = 0;
      size_t sz = H5Tget_size(typeId);

      for (const auto &E : extents) {
	hsize_t start[] = {E.offset};
	hsize_t block[] = {E.len};
	if (E.offset >= dataspaceSize)
	  continue;
	if (E.offset + E.len > dataspaceSize)
	  block[0] = dataspaceSize - E.offset;

	auto mspace = H5Screate_simple(1, block, NULL);
	H5Sselect_hyperslab(spaceId, H5S_SELECT_SET, start, /*stride=*/internal::one,
			    /*count=*/internal::one, block);
	H5Dread(datasetId, typeId, mspace, spaceId, H5P_DEFAULT, p);
	H5Sclose(mspace);
	p += (block[0] * sz);
	count += block[0];
      }
      return count;
    }

    /// \brief Reference implementation of `WriteExtents()`. Column models may call this as part of
    /// `XxxNode::WriteExtents()`.
    static inline size_t SimpleWriteExtents(const std::vector<Span> &extents, const void *buf,
					    hid_t datasetId, hid_t &spaceId, hid_t typeId) {
      const auto requiredSize = GetMinimumDatasetSize(extents);
      auto p = reinterpret_cast<const unsigned char*>(buf);
      size_t count = 0;
      size_t sz = H5Tget_size(typeId);

      if (requiredSize > GetDataspaceSize(spaceId)) {
	hsize_t newSize[] = {requiredSize};
	H5Sclose(spaceId);
	H5Dset_extent(datasetId, newSize);
	spaceId = H5Dget_space(datasetId);
      }

      for (const auto &E : extents) {
	hsize_t start[] = {E.offset};
	hsize_t block[] = {E.len};

	auto mspace = H5Screate_simple(1, block, NULL);
	H5Sselect_hyperslab(spaceId, H5S_SELECT_SET, start, /*stride=*/internal::one,
			    /*count=*/internal::one, block);
	H5Dwrite(datasetId, typeId, mspace, spaceId, H5P_DEFAULT, p);
	H5Sclose(mspace);
	p += (block[0] * sz);
	count += block[0];
      }
      return count;
    }

    /// \brief Copies `n` elements of size `sz` from `src` to `dest`. The strides that separate
    /// elements in `dest` and `src` is given by `stride_dest` and `stride_src`, respectively.
    /// This function is mostly used to copy to/from column buffers.
    static inline void CopyElements(void *__restrict dest, const void *__restrict src, size_t n,
				    size_t sz, size_t stride_dest, size_t stride_src) {
      auto _dest = reinterpret_cast<unsigned char*>(dest);
      auto _src = reinterpret_cast<const unsigned char*>(src);
      for (size_t i = 0; i < n; ++i) {
	memcpy(_dest, _src, sz);
	_dest += stride_dest;
	_src += stride_src;
      }
    }
  } // namespace internal

  class H5Location {
  protected:
    hid_t hid = H5I_INVALID_HID;
    H5Location(hid_t hid) : hid(hid) {}
  public:
    hid_t GetHandle() const { return hid; }
  };

  class H5File : public H5Location {
    hid_t accessPlist;

    H5File(hid_t hid) : H5Location(hid) { accessPlist = H5Fget_access_plist(hid); }
  public:
    H5File() = delete;
    ~H5File() {
      H5Pclose(accessPlist);
      H5Fclose(hid);
    }

    /// \brief Set HDF5 chunk cache parameters. For the specific meaning of each parameter, see
    /// https://support.hdfgroup.org/HDF5/doc1.8/RM/RM_H5P.html
    void SetCache(size_t rdcc_nbytes, size_t rdcc_nslots = 521, double rdcc_w0 = 0.75)
    { H5Pset_cache(accessPlist, /*mdc_nelmts=*/0, rdcc_nbytes, rdcc_nslots, rdcc_w0); }

    static std::shared_ptr<H5Location> Create(std::string_view path, unsigned flags = H5F_ACC_TRUNC) {
      auto fileId = H5Fcreate(path.data(), flags, H5P_DEFAULT, H5P_DEFAULT);
      if (fileId == H5I_INVALID_HID)
	throw std::runtime_error("H5Fcreate error");
      return std::shared_ptr<H5Location>(new H5File(fileId));
    }

    static std::shared_ptr<H5Location> Open(std::string_view path, unsigned flags = H5F_ACC_RDONLY) {
      auto fileId = H5Fopen(path.data(), flags, H5P_DEFAULT);
      if (fileId == H5I_INVALID_HID)
	throw std::runtime_error("H5Fopen error");
      return std::shared_ptr<H5Location>(new H5File(fileId));
    }
  };

  /// \brief Properties used by `ReaderWriter` to generate HDF5 datasets
  class WriteProperties {
    size_t chunkSize = 10000;
    unsigned compressionLevel = 0;
  public:
    WriteProperties() = default;
    WriteProperties(const WriteProperties &) = default;
    WriteProperties(size_t s, unsigned l) : chunkSize(s), compressionLevel(l) {}

    size_t GetChunkSize() const { return chunkSize; }
    void SetChunkSize(const size_t val) { chunkSize = val; }

    unsigned GetCompressionLevel() const { return compressionLevel; }
    void SetCompressionLevel(const unsigned val) { compressionLevel = val; }
  };

  class ReaderWriter {
  protected:
    std::shared_ptr<H5Location> location;
    std::shared_ptr<schema::NodeBase> root; /// \brief Root node of the schema
    std::vector<size_t> collectionIdxs; /// \brief Indices of top-level collections in `root`
    WriteProperties props;
    hid_t dcpl = H5I_INVALID_HID; /// \brief Dataset creation property list built from `props`

    /// Dataspace and dataset identifiers, if the column model uses a single dataset
    hid_t spaceId = H5I_INVALID_HID;
    hid_t datasetId = H5I_INVALID_HID;

    void RealizeSchema(void *privateData = nullptr) {
      for (size_t i = 0; i < root->children.size(); ++i) {
	if (root->children[i]->kind == schema::NodeKind::COLLECTION)
	  collectionIdxs.push_back(i);
      }
      root->Realize(*this, privateData);
    }

    /// \brief Initialize top-level collections in the row group pointed to by `buf`. This should
    /// trigger the recursive deallocation of owned `hvl_t` buffers.
    virtual void InitializeCollections(const std::vector<Span> &extents, void *buf) const {
      auto p = reinterpret_cast<unsigned char*>(buf);
      for_each_row_in_extentlist(extents, E, i) {
	for (size_t j : collectionIdxs) {
	  const auto &C = root->children[j];
	  C->InitializeValue(p + C->offset);
	}
	p += root->size;
      }
    }

  public:
    ReaderWriter(std::shared_ptr<H5Location> location, std::shared_ptr<schema::NodeBase> schemaRoot)
      : location(location), root(schemaRoot->Clone()) {}
    ReaderWriter(std::shared_ptr<H5Location> location, std::shared_ptr<schema::NodeBase> schemaRoot,
		 const WriteProperties &props)
      : location(location), root(schemaRoot->Clone()), props(props) {}
    virtual ~ReaderWriter() {}

    std::shared_ptr<schema::NodeBase> GetSchemaRoot() const { return root; }
    const WriteProperties &GetWriteProperties() const { return props; }

    /// \brief Get the number of entries in this n-tuple
    virtual size_t GetNEntries() const = 0;

    /// \brief Get the number of chunks (row groups)
    size_t GetNChunks() const {
      const auto chunkSize = props.GetChunkSize();
      return (GetNEntries() + chunkSize - 1) / chunkSize;
    }

    /// \brief For column models using a single dataset, return the dataspace identifier
    hid_t GetSpaceId() const { return spaceId; }
    hid_t GetDatasetId() const { return datasetId; }

    virtual size_t ReadExtents(const std::vector<Span> &extents, void *buf)
    { return root->ReadExtents(extents, buf); }
    virtual size_t WriteExtents(const std::vector<Span> &extents, const void *buf)
    { return root->WriteExtents(extents, buf); }

    size_t ReadChunk(size_t n, void *buf)
    { return ReadExtents(std::vector<Span>{{n * props.GetChunkSize(), props.GetChunkSize()}}, buf); }

    size_t WriteChunk(size_t n, void *buf, size_t size)
    { return WriteExtents(std::vector<Span>{{n * props.GetChunkSize(), size}}, buf); }
    size_t WriteChunk(size_t n, void *buf)
    { return WriteChunk(n, buf, props.GetChunkSize()); }
  };

} // namespace h5hep

#endif // _H5HEP_IO_HXX
