/// \file h5hep/model_compoundtype.hxx
/// \author Javier Lopez-Gomez <j.lopez@cern.ch>
/// \date 2021-11-05
///
/// \brief Header-only library to read/write high-energy physics data in HDF5.
/// For benchmark purposes only; do NOT use in production.
///
/// Implements a column model that uses compound types; collections are encoded unsing HDF5 VL types.

#ifndef _H5HEP_MODEL_COMPOUNDTYPE_HXX
#define _H5HEP_MODEL_COMPOUNDTYPE_HXX

#include <h5hep/io.hxx>
#include <h5hep/schema.hxx>

#include <hdf5.h>

namespace h5hep {

  namespace schema {
    template <>
    class Node<ColumnModel::COMPOUND_TYPE> : public NodeBase {
    public:
      using NodePtr_t = std::shared_ptr<Node<ColumnModel::COMPOUND_TYPE>>;
      using MemberList_t = std::vector<NodePtr_t>;

      Node(NodeKind k, std::string_view name, size_t offset, size_t size, hid_t tid = H5I_INVALID_HID)
	: NodeBase(k, name, offset, size, tid) {}
      Node(const Node &) = default;

      size_t ReadExtents(const std::vector<Span> &extents, void *buf) override { return 0; }
      size_t WriteExtents(const std::vector<Span> &extents, const void *buf) override { return 0; }
    };

    template <typename T>
    class PrimitiveNode<ColumnModel::COMPOUND_TYPE, T> : public Node<ColumnModel::COMPOUND_TYPE> {
    public:
      using Value_t = T;

      PrimitiveNode(std::string_view name, size_t offset)
	: Node(NodeKind::PRIMITIVE, name, offset, sizeof(T), GetH5TypeId<T>()) {}
      PrimitiveNode(const PrimitiveNode &) = default;

      std::shared_ptr<NodeBase> Clone() const override {
	return std::make_shared<typename std::decay<decltype(*this)>::type>(*this);
      }
    };

    template <typename T>
    class StructNode<ColumnModel::COMPOUND_TYPE, T> : public Node<ColumnModel::COMPOUND_TYPE> {
    public:
      using Value_t = T;

      StructNode(std::string_view name, size_t offset, const MemberList_t &v)
	: Node(NodeKind::STRUCT, name, offset, sizeof(T))
      {
	for (auto &I : v)
	  children.push_back(std::static_pointer_cast<NodeBase>(I));
      }
      StructNode(const StructNode &) = default;
      virtual ~StructNode() { if (typeId != H5I_INVALID_HID) H5Tclose(typeId); }

      void Realize(ReaderWriter &rw, void *privateData) override {
	NodeBase::Realize(rw, privateData);
	typeId = H5Tcreate(H5T_COMPOUND, size);
	for (auto &I : children)
	  H5Tinsert(typeId, I->name.c_str(), I->offset, I->typeId);
      }

      std::shared_ptr<NodeBase> Clone() const override {
	MemberList_t v;
	for (auto &I : children)
	  v.push_back(std::reinterpret_pointer_cast<NodePtr_t::element_type>(I->Clone()));
	return std::make_shared<typename std::decay<decltype(*this)>::type>(name, offset, v);
      }
    };

    template <typename T>
    class CollectionNode<ColumnModel::COMPOUND_TYPE, T> : public Node<ColumnModel::COMPOUND_TYPE> {
    public:
      using Value_t = T;

      CollectionNode(std::string_view name, size_t offset, NodePtr_t inner)
	: Node(NodeKind::COLLECTION, name, offset, sizeof(hvl_t))
      {
	children = {std::static_pointer_cast<NodeBase>(inner)};
      }
      CollectionNode(const CollectionNode &) = default;
      virtual ~CollectionNode() { if (typeId != H5I_INVALID_HID) H5Tclose(typeId); }

      void Realize(ReaderWriter &rw, void *privateData) override {
	NodeBase::Realize(rw, privateData);
	typeId = H5Tvlen_create(children.back()->typeId);
      }

      void InitializeValue(void *p) override {
	reinterpret_cast<CollectionBase*>(p)->assign({},
		   [](void *p, void *data) {
		     const auto that = reinterpret_cast<const CollectionNode<ColumnModel::COMPOUND_TYPE, T>*>(data);
		     H5Dvlen_reclaim(that->children.back()->typeId,
				     that->readerWriter->GetSpaceId(), H5P_DEFAULT, p);
		   }, this);
      }

      std::shared_ptr<NodeBase> Clone() const override {
	auto inner = std::reinterpret_pointer_cast<NodePtr_t::element_type>(children.back()->Clone());
	return std::make_shared<typename std::decay<decltype(*this)>::type>(name, offset, inner);
      }
    };
  } //namespace schema

  template <>
  class ReaderWriterSpec<ColumnModel::COMPOUND_TYPE> : public ReaderWriter {
  public:
    ReaderWriterSpec(std::shared_ptr<H5Location> location, std::shared_ptr<schema::NodeBase> schemaRoot)
      : ReaderWriter(location, schemaRoot)
    {
      RealizeSchema();

      datasetId = H5Dopen(location->GetHandle(), root->name.c_str(), H5P_DEFAULT);
      spaceId = H5Dget_space(datasetId);
      dcpl = H5Dget_create_plist(datasetId);

      hsize_t chunkSize{};
      H5Pget_chunk(dcpl, 1, &chunkSize);
      props.SetChunkSize(chunkSize);
      // TODO: retrieve deflate level, if using compression
    }

    ReaderWriterSpec(std::shared_ptr<H5Location> location, std::shared_ptr<schema::NodeBase> schemaRoot,
		 const WriteProperties &props)
      : ReaderWriter(location, schemaRoot, props)
    {
      hsize_t chunkSize[] = {props.GetChunkSize()};

      dcpl = H5Pcreate(H5P_DATASET_CREATE);
      if (auto level = props.GetCompressionLevel())
	H5Pset_deflate(dcpl, level);
      H5Pset_chunk(dcpl, 1, chunkSize);

      RealizeSchema();

      spaceId = H5Screate_simple(1, /*dims=*/internal::zero, /*maxdims=*/internal::unlimited);
      datasetId = H5Dcreate(location->GetHandle(), root->name.c_str(), root->typeId, spaceId,
			    H5P_DEFAULT, dcpl, H5P_DEFAULT);
    }

    virtual ~ReaderWriterSpec() {
      if (datasetId != H5I_INVALID_HID) H5Dclose(datasetId);
      if (spaceId != H5I_INVALID_HID) H5Sclose(spaceId);
      if (dcpl != H5I_INVALID_HID) H5Pclose(dcpl);
    }

    size_t GetNEntries() const override {
      return internal::GetDataspaceSize(spaceId);
    }

    size_t ReadExtents(const std::vector<Span> &extents, void *buf) override {
      InitializeCollections(extents, buf);
      return internal::SimpleReadExtents(extents, buf, datasetId, spaceId, root->typeId);
    }

    size_t WriteExtents(const std::vector<Span> &extents, const void *buf) override {
      return internal::SimpleWriteExtents(extents, buf, datasetId, spaceId, root->typeId);
    }
  };

} // namespace h5hep

#endif // _H5HEP_MODEL_COMPOUNDTYPE_HXX
