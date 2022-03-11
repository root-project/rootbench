/// \file h5hep/schema.hxx
/// \author Javier Lopez-Gomez <j.lopez@cern.ch>
/// \date 2021-10-23
///
/// \brief Header-only library to read/write high-energy physics data in HDF5.
/// For benchmark purposes only; do NOT use in production.

#ifndef _H5HEP_SCHEMA_HXX
#define _H5HEP_SCHEMA_HXX

#include <h5hep/common.hxx>

#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace h5hep {

  /// \brief The column model defines how schema columns are translated to HDF5.
  enum class ColumnModel {
    /// \brief Uses (possibly nested) compound types to represent data for each row.
    COMPOUND_TYPE = 0,

    /// \brief Uses one HDF5 dataset per primitive column; collections are translated to
    /// a HDF5 group and a index column. For more information, see
    /// https://inspirehep.net/files/e048b0cd122919dc9a009793983a81e0.
    COLUMNAR_FNAL,

    UNKNOWN = 99
  };

  class ReaderWriter;
  template <ColumnModel M> class ReaderWriterSpec;

  namespace schema {
    enum class NodeKind {
      PRIMITIVE = 0, 
      STRUCT,
      COLLECTION,
    };

    struct NodeBase {
      NodeKind kind;
      std::string name;
      size_t offset; /// \brief Offset of this member within the enclosing type
      size_t size;   /// \brief Size of the datatype
      hid_t typeId;  /// \brief HDF5 type id for this node, if any
      std::vector<std::shared_ptr<NodeBase>> children;
      ReaderWriter *readerWriter{}; /// \brief Related `ReaderWriter` object, if the schema has been realized

      NodeBase(const NodeBase &) = default;
      NodeBase(NodeKind k, std::string_view name, size_t offset, size_t size, hid_t tid)
        : kind(k), name(name), offset(offset), size(size), typeId(tid) {}
      virtual ~NodeBase() {}

      /// \brief Called by a ReaderWriter during construction to perform initialization that requires
      /// an HDF5 file handle, e.g. to create datasets/groups.
      ///
      /// \param rw The `ReaderWriter` instance realizing the schema
      /// \param privateData Reserved for private use of the column model implementation
      virtual void Realize(ReaderWriter &rw, void *privateData) {
        readerWriter = &rw;
        for (auto &I : children)
          I->Realize(rw, privateData);
      }

      /// \brief Initialize the value pointed to by `p` of this type. This is typically a no-op for primitive
      /// types; non-scalar types require it though.
      virtual void InitializeValue(void *p) {}

      /// \brief Read the rows described by `extents` into `buf`. The caller must provide a
      /// buffer that is large enough to copy all the data.
      virtual size_t ReadExtents(const std::vector<Span> &extents, void *buf) = 0;
      /// \brief Write the rows pointed to by `buf` using the layout described by `extents`.
      virtual size_t WriteExtents(const std::vector<Span> &extents, const void *buf) = 0;

      virtual std::shared_ptr<NodeBase> Clone() const = 0;
    };

    template <ColumnModel M> class Node;

    /// \brief A field of a fundamental type `T`, e.g. 'double'. The mapping of a PrimitiveNode
    /// to HDF5 depends on the column model.
    template <ColumnModel M, typename T> class PrimitiveNode;

    /// \brief A group of `PrimitiveNode` or `CollectionNode` fields. The mapping of a StructNode
    /// to HDF5 depends on the column model.
    template <ColumnModel M, typename T> class StructNode;

    /// \brief A variable-length collection of any type `T`. The mapping of a CollectionNode to HDF5
    /// depends on the column model.
    template <ColumnModel M, typename T> class CollectionNode;

    /// \brief Provides access to convenience functions for building schema nodes, e.g.
    /// ```
    /// using Builder = h5hep::schema::SchemaBuilder<h5hep::ColumnModel::COMPOUND_TYPE>
    /// auto root = Builder::MakeStructNode<Foo>("Foo", {
    ///   })
    /// ```
    template <ColumnModel M>
    struct SchemaBuilder {
      static constexpr ColumnModel GetColumnModel() { return M; }

      template <typename T>
      static std::shared_ptr<PrimitiveNode<M, T>> MakePrimitiveNode(std::string_view name = "(anonymous)", size_t offset = 0)
      { return std::make_shared<PrimitiveNode<M, T>>(name, offset); }

      template <typename T>
      static std::shared_ptr<StructNode<M, T>> MakeStructNode(std::string_view name, size_t offset,
                                                              typename StructNode<M, T>::MemberList_t &&v)
      { return std::make_shared<StructNode<M, T>>(name, offset, v); }

      template <typename T>
      static std::shared_ptr<StructNode<M, T>> MakeStructNode(std::string_view name, typename StructNode<M, T>::MemberList_t &&v)
      { return std::make_shared<StructNode<M, T>>(name, 0UL, v); }

      template <typename T>
      static std::shared_ptr<CollectionNode<M, typename T::Value_t>> MakeCollectionNode(std::string_view name, size_t offset,
                                                                      std::shared_ptr<T> inner)
      { return std::make_shared<CollectionNode<M, typename T::Value_t>>(name, offset, inner); }

      template <typename... Ts>
      static std::shared_ptr<ReaderWriterSpec<M>> MakeReaderWriter(Ts... args)
      { return std::make_shared<ReaderWriterSpec<M>>(args...); }
    };
  } // namespace schema

} // namespace h5hep

#endif // _H5HEP_SCHEMA_HXX
