/// \file h5hep/model_columnarfnal.hxx
/// \author Javier Lopez-Gomez <j.lopez@cern.ch>
/// \date 2021-11-08
///
/// \brief Header-only library to read/write high-energy physics data in HDF5.
/// For benchmark purposes only; do NOT use in production.
///
/// A (restricted) column model that uses one HDF5 dataset per primitive column. It is compliant with
/// https://inspirehep.net/files/e048b0cd122919dc9a009793983a81e0.

#ifndef _H5HEP_MODEL_COLUMNARFNAL_HXX
#define _H5HEP_MODEL_COLUMNARFNAL_HXX

#include <h5hep/io.hxx>
#include <h5hep/schema.hxx>

#include <hdf5.h>

#include <algorithm>
#include <optional>

namespace h5hep {

  namespace schema {
    template <>
    class Node<ColumnModel::COLUMNAR_FNAL> : public NodeBase {
    protected:
      /// \brief The dataspace and dataset identifiers for this column
      mutable hid_t spaceId = H5I_INVALID_HID;
      hid_t datasetId = H5I_INVALID_HID;

    public:
      struct RealizePrivateData {
	hid_t parentGroup; /// \brief Where to create/access the dataset for this column 
	hid_t dcpl; /// \brief If the schema is being initialized, the dataset creation property list
      };

      using NodePtr_t = std::shared_ptr<Node<ColumnModel::COLUMNAR_FNAL>>;
      using MemberList_t = std::vector<NodePtr_t>;

      Node(NodeKind k, std::string_view name, size_t offset, size_t size, hid_t tid = H5I_INVALID_HID)
	: NodeBase(k, name, offset, size, tid) {}
      Node(const Node &) = default;
      virtual ~Node() {
	if (datasetId != H5I_INVALID_HID) H5Dclose(datasetId);
	if (spaceId != H5I_INVALID_HID) H5Sclose(spaceId);
      }

      hsize_t GetDataspaceSize() { return internal::GetDataspaceSize(spaceId); }
    };

    template <typename T>
    class PrimitiveNode<ColumnModel::COLUMNAR_FNAL, T> : public Node<ColumnModel::COLUMNAR_FNAL> {
    public:
      using Value_t = T;

      PrimitiveNode(std::string_view name, size_t offset)
	: Node(NodeKind::PRIMITIVE, name, offset, sizeof(T), GetH5TypeId<T>()) {}
      PrimitiveNode(const PrimitiveNode &) = default;

      void Realize(ReaderWriter &rw, void *privateData) override {
	const auto &info = *reinterpret_cast<RealizePrivateData*>(privateData);

	if (info.dcpl != H5I_INVALID_HID) {
	  spaceId = H5Screate_simple(1, /*dims=*/internal::zero, /*maxdims=*/internal::unlimited);
	  datasetId = H5Dcreate(info.parentGroup, name.c_str(), typeId, spaceId,
			    H5P_DEFAULT, info.dcpl, H5P_DEFAULT);
	} else {
	  datasetId = H5Dopen(info.parentGroup, name.c_str(), H5P_DEFAULT);
	  spaceId = H5Dget_space(datasetId);
	}
      }

      size_t ReadExtents(const std::vector<Span> &extents, void *buf) override {
	return internal::SimpleReadExtents(extents, buf, datasetId, spaceId, typeId);
      }

      size_t WriteExtents(const std::vector<Span> &extents, const void *buf) override {
	return internal::SimpleWriteExtents(extents, buf, datasetId, spaceId, typeId);
      }

      std::shared_ptr<NodeBase> Clone() const override {
	return std::make_shared<typename std::decay<decltype(*this)>::type>(*this);
      }
    };

    template <typename T>
    class StructNode<ColumnModel::COLUMNAR_FNAL, T> : public Node<ColumnModel::COLUMNAR_FNAL> {
    public:
      using Value_t = T;

      StructNode(std::string_view name, size_t offset, const MemberList_t &v)
	: Node(NodeKind::STRUCT, name, offset, sizeof(T))
      {
	for (auto &I : v)
	  children.push_back(std::static_pointer_cast<NodeBase>(I));
      }
      StructNode(const StructNode &) = default;

      size_t ReadExtents(const std::vector<Span> &extents, void *buf) override {
	size_t nElements = std::accumulate(extents.begin(), extents.end(), 0,
					   [](size_t a, const Span &b) { return a + b.len; });
	size_t largestT = std::accumulate(children.begin(), children.end(), 0,
					  [](size_t a, const auto b) { return std::max(a, b->size); });
	size_t count = 0;

	auto columnBuffer = std::make_unique<unsigned char[]>(nElements * largestT);
	for (const auto &I : children) {
	  auto c = I->ReadExtents(extents, columnBuffer.get());
	  // For collections, we unpack an array of `hvl_t[]` from `columnBuffer`
	  internal::CopyElements(reinterpret_cast<unsigned char*>(buf) + I->offset,
				 columnBuffer.get(),
				 c, I->size, size, I->size);
	  if (I->kind != NodeKind::COLLECTION) // FIXME:
	    count = std::max(count, c);
	}
	return count;
      }

      size_t WriteExtents(const std::vector<Span> &extents, const void *buf) override {
	size_t nElements = std::accumulate(extents.begin(), extents.end(), 0,
					   [](size_t a, const Span &b) { return a + b.len; });
	size_t largestT = std::accumulate(children.begin(), children.end(), 0,
					  [](size_t a, const auto b) { return std::max(a, b->size); });

	auto columnBuffer = std::make_unique<unsigned char[]>(nElements * largestT);
	for (const auto &I : children) {
	  // For collections, we pack an array of `hvl_t[]` into `columnBuffer`
	  internal::CopyElements(columnBuffer.get(),
				 reinterpret_cast<const unsigned char*>(buf) + I->offset,
				 nElements, I->size, I->size, size);
	  I->WriteExtents(extents, columnBuffer.get());
	}
	return nElements;
      }

      std::shared_ptr<NodeBase> Clone() const override {
	MemberList_t v;
	for (auto &I : children)
	  v.push_back(std::reinterpret_pointer_cast<NodePtr_t::element_type>(I->Clone()));
	return std::make_shared<typename std::decay<decltype(*this)>::type>(name, offset, v);
      }
    };

    template <typename T>
    class CollectionNode<ColumnModel::COLUMNAR_FNAL, T> : public Node<ColumnModel::COLUMNAR_FNAL> {
      template <typename U>
      struct SequentialColumnReader {
	PrimitiveNode<ColumnModel::COLUMNAR_FNAL, U> &column;
	size_t chunkSize;
	std::unique_ptr<U[]> chunk;
	size_t nEltsInChunk{};
	size_t offset{};

	SequentialColumnReader(PrimitiveNode<ColumnModel::COLUMNAR_FNAL, U> &c, size_t chunkSize)
	  : column(c), chunkSize(chunkSize) {}

	void ReadNextChunk() {
	  nEltsInChunk = column.ReadExtents(std::vector<Span>{{offset, chunkSize}}, chunk.get());
	}

	std::optional<U> operator*() {
	  if (unlikely(!chunk.get())) {
	    chunk = std::make_unique<U[]>(chunkSize);
	    ReadNextChunk();
	  }
	  return nEltsInChunk == 0 ? std::optional<U>() : std::optional<U>(chunk[offset % chunkSize]);
	}

	SequentialColumnReader &operator++(int) {
	  if ((++offset % chunkSize) == 0)
	    ReadNextChunk();
	  return *this;
	}
      };

      using IndexColumnValue_t = unsigned long;
      /// \brief A column used to identify elements in the collection
      std::unique_ptr<PrimitiveNode<ColumnModel::COLUMNAR_FNAL, IndexColumnValue_t>> indexColumn;
      /// \brief Sequential reader used in `LookupElements()`
      std::unique_ptr<SequentialColumnReader<IndexColumnValue_t>> indexColumnReader;
      static constexpr size_t defaultChunkSize = (512 * 1024) / sizeof(IndexColumnValue_t);

      void ThrowIfNestedCollections(std::shared_ptr<NodeBase> inner) {
	if (inner->kind == NodeKind::COLLECTION)
	  throw std::runtime_error("This column model doesn't support nested collections");
	for (auto &I : inner->children)
	  ThrowIfNestedCollections(I);
      }

      /// \brief For each entry described in `in`, add to `out` the corresponding extent for elements in the
      /// collection.
      /// \return Total number of elements
      ///
      /// This naive implementation only allows sequential access to the collection. Also, although incompatible
      /// with the original publication, collections are better encoded using an index column of type
      /// `h5hep::H5Span` (or a VL type of it).
      size_t LookupElements(const std::vector<Span> &in, std::vector<Span> &out) {
	size_t count = 0;
	for_each_row_in_extentlist(in, E, i) {
	  const auto entryIdx = E.offset + i;
	  Span extent{(size_t)-1, 0};

	  while (auto idx = *(*indexColumnReader)) {
	    if (extent.offset == (size_t)-1 && idx == entryIdx)
	      extent.offset = indexColumnReader->offset;
	    if (idx > entryIdx)
	      break;
	    (*indexColumnReader)++;
	  }
	  if (extent.offset != (size_t)-1)
	    extent.len = (indexColumnReader->offset - extent.offset);

	  out.push_back(extent);
	  count += extent.len;
	}
	return count;
      }

    public:
      using Value_t = T;

      CollectionNode(std::string_view name, size_t offset, NodePtr_t inner)
	: Node(NodeKind::COLLECTION, name, offset, sizeof(hvl_t))
      {
	ThrowIfNestedCollections(std::static_pointer_cast<NodeBase>(inner));

	children = {std::static_pointer_cast<NodeBase>(inner)};
	indexColumn = std::make_unique<typename decltype(indexColumn)::element_type>("Event ID", 0);
	indexColumnReader = std::make_unique<SequentialColumnReader<IndexColumnValue_t>>
	  (*indexColumn.get(), defaultChunkSize);
      }
      CollectionNode(const CollectionNode &) = default;

      void Realize(ReaderWriter &rw, void *privateData) override {
	const auto &info = *reinterpret_cast<RealizePrivateData*>(privateData);

	hid_t group = (info.dcpl != H5I_INVALID_HID)
	  ? H5Gcreate(info.parentGroup, name.c_str(), H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT)
	  : H5Gopen(info.parentGroup, name.c_str(), H5P_DEFAULT);

	RealizePrivateData newInfo{group, info.dcpl};
	indexColumn->Realize(rw, &newInfo);
	NodeBase::Realize(rw, &newInfo);
      }

      void InitializeValue(void *p) override {
	reinterpret_cast<CollectionBase*>(p)->assign({},
		   [](void *p, void *data) { delete[] reinterpret_cast<T*>(p); });
      }

      size_t ReadExtents(const std::vector<Span> &extents, void *buf) override {
	auto hvls = reinterpret_cast<hvl_t*>(buf);
	size_t nElements = std::accumulate(extents.begin(), extents.end(), 0,
					   [](size_t a, const Span &b) { return a + b.len; });
	std::vector<Span> eltExts;
	LookupElements(extents, eltExts);

	size_t hvl_i = 0;
	for (const auto &E : eltExts) {
	  auto &hvl = hvls[hvl_i++];

	  if (E.offset == (size_t)-1) {
	    hvl = {};
	    continue;
	  }

	  hvl.len = E.len;
	  hvl.p = new T[E.len];
	  children.back()->ReadExtents(std::vector<Span>{{E.offset, E.len}}, hvl.p);
	}
	return nElements;
      }

      size_t WriteExtents(const std::vector<Span> &extents, const void *buf) override {
	auto hvls = reinterpret_cast<const hvl_t*>(buf);
	size_t nElements = std::accumulate(extents.begin(), extents.end(), 0,
					   [](size_t a, const Span &b) { return a + b.len; });
	size_t szLargestCollection = std::accumulate(hvls, hvls + nElements, 0,
						     [](size_t a, const hvl_t &b) { return std::max(a, b.len); });
	auto bufIdxColumn = std::make_unique<IndexColumnValue_t[]>(szLargestCollection);

	hsize_t offset = indexColumn->GetDataspaceSize();
	size_t hvl_i = 0;
	for_each_row_in_extentlist(extents, E, i) {
	  auto &hvl = hvls[hvl_i++];
	  const auto rowIdx = E.offset + i;

	  // Write a stride of `rowIdx` values in the index column
	  std::fill(bufIdxColumn.get(), bufIdxColumn.get() + hvl.len, rowIdx);
	  indexColumn->WriteExtents(std::vector<Span>{{offset, hvl.len}}, bufIdxColumn.get());

	  children.back()->WriteExtents(std::vector<Span>{{offset, hvl.len}}, hvl.p);
	  offset += hvl.len;
	}
	return nElements;
      }

      std::shared_ptr<NodeBase> Clone() const override {
	auto inner = std::reinterpret_pointer_cast<NodePtr_t::element_type>(children.back()->Clone());
	return std::make_shared<typename std::decay<decltype(*this)>::type>(name, offset, inner);
      }
    };
  } //namespace schema

  template <>
  class ReaderWriterSpec<ColumnModel::COLUMNAR_FNAL> : public ReaderWriter {
    using Node_t = schema::Node<ColumnModel::COLUMNAR_FNAL>;

    struct Metadata_t {
      static constexpr const char *attrName = "$Metadata";
      unsigned long attrs[2]{};
      hid_t spaceId;
      hid_t attrId;

      Metadata_t(hid_t location) {
	attrId = H5Aopen(location, attrName, H5P_DEFAULT);
	spaceId = H5Aget_space(attrId);
	H5Aread(attrId, H5T_NATIVE_LONG, attrs);
      }
      Metadata_t(hid_t location, const WriteProperties &props)
	: attrs{props.GetChunkSize(), 0U}
      {
	hsize_t sz = std::extent<decltype(attrs)>::value;
	spaceId = H5Screate_simple(1, &sz, NULL);
	attrId = H5Acreate(location, attrName, H5T_NATIVE_ULONG, spaceId, H5P_DEFAULT, H5P_DEFAULT);
	H5Awrite(attrId, H5T_NATIVE_ULONG, attrs);
      }
      ~Metadata_t() {
	if (attrId != H5I_INVALID_HID) H5Aclose(attrId);
	if (spaceId != H5I_INVALID_HID) H5Sclose(spaceId);
      }

      // TODO: should the compression level be also stored in `attrs`?
      WriteProperties GetWriteProperties() const { return WriteProperties{attrs[0], 0U}; }

      size_t GetNEntries() const { return attrs[1]; }
      void SetNEntries(size_t n) {
	attrs[1] = n;
	H5Awrite(attrId, H5T_NATIVE_ULONG, attrs);
      }
    } metadata;

  public:
    ReaderWriterSpec(std::shared_ptr<H5Location> location, std::shared_ptr<schema::NodeBase> schemaRoot)
      : ReaderWriter(location, schemaRoot), metadata(location->GetHandle())
    {
      props = metadata.GetWriteProperties();
      Node_t::RealizePrivateData info{/*parentGroup=*/location->GetHandle(), /*dcpl=*/H5I_INVALID_HID};
      RealizeSchema(&info);
    }

    ReaderWriterSpec(std::shared_ptr<H5Location> location, std::shared_ptr<schema::NodeBase> schemaRoot,
		 const WriteProperties &props)
      : ReaderWriter(location, schemaRoot, props), metadata(location->GetHandle(), props)
    {
      hsize_t chunkSize[] = {props.GetChunkSize()};
      dcpl = H5Pcreate(H5P_DATASET_CREATE);
      if (auto level = props.GetCompressionLevel())
	H5Pset_deflate(dcpl, level);
      H5Pset_chunk(dcpl, 1, chunkSize);

      Node_t::RealizePrivateData info{/*parentGroup=*/location->GetHandle(), /*dcpl=*/dcpl};
      RealizeSchema(&info);
    }

    virtual ~ReaderWriterSpec() {
      if (dcpl != H5I_INVALID_HID) H5Pclose(dcpl);
    }

    size_t GetNEntries() const override { return metadata.GetNEntries(); }

    size_t ReadExtents(const std::vector<Span> &extents, void *buf) override {
      // TODO: non-sequential access should throw (see `LookupElements()` restrictions)
      InitializeCollections(extents, buf);
      return root->ReadExtents(extents, buf);
    }

    size_t WriteExtents(const std::vector<Span> &extents, const void *buf) override {
      auto size = internal::GetMinimumDatasetSize(extents);
      if (size > GetNEntries()) // FIXME:
	metadata.SetNEntries(size);
      return root->WriteExtents(extents, buf);
    }
  };

} // namespace h5hep

#endif // _H5HEP_MODEL_COLUMNARFNAL_HXX
