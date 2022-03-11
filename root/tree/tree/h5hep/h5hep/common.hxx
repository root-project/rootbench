/// \file h5hep/common.hxx
/// \author Javier Lopez-Gomez <j.lopez@cern.ch>
/// \date 2021-10-23
///
/// \brief Header-only library to read/write high-energy physics data in HDF5.
/// For benchmark purposes only; do NOT use in production.

#ifndef _H5HEP_COMMON_HXX
#define _H5HEP_COMMON_HXX

#include <hdf5.h>

#include <cassert>
#include <type_traits>
#include <vector>

#if defined(__GNUC__)
# define likely(x)   __builtin_expect(!!(x), 1)
# define unlikely(x) __builtin_expect(!!(x), 0)
#else
# define likely(x)   x
# define unlikely(x) x
# define __restrict
#endif

/// \brief Iterate over each row described by a `std::vector<Span>`
#define for_each_row_in_extentlist(__Es, __E, __i)	\
  for (auto &__E : (__Es))				\
    for (size_t __i = 0; i < __E.len; ++i)

namespace h5hep {

  struct CollectionBase {
    using Deleter_t = void (*)(void *p, void *privateData);
    hvl_t hvl{}; // Must appear first!
    Deleter_t deleter{};
    void *privateData;

    CollectionBase() = default;
    CollectionBase(const hvl_t &hvl, Deleter_t d) : hvl{hvl.len, hvl.p}, deleter(d) {}
    ~CollectionBase() { invokeDeleter(); }

    void invokeDeleter() { if (hvl.p && deleter) deleter(hvl.p, privateData); }
    void assign(const hvl_t &hvl, Deleter_t d, void *privateData = nullptr) {
      invokeDeleter();
      this->hvl = hvl_t{hvl.len, hvl.p};
      this->deleter = d;
      this->privateData = privateData;
    }
  };

  /// \brief Variable-length collection of elements of type `T`. Might be used
  /// as part of a larger data type to annotate a collection, e.g.
  /// ```
  /// struct Foo {
  ///   float f;
  ///   h5hep::Collection<int> i;
  /// };
  /// ```
  template <typename T>
  struct Collection : public CollectionBase {
  public:
    Collection() : CollectionBase({}, nullptr) {}
    Collection(const Collection<T> &c) : CollectionBase(hvl_t{c.size(), c.data()}, nullptr) {}
    Collection(std::vector<T> &v) : CollectionBase(hvl_t{v.size(), v.data()}, nullptr) {}

    Collection<T> &operator=(Collection<T> &&other) {
      std::swap(hvl.len, other.size());
      std::swap(hvl.p, other.data());
      std::swap(deleter, other.deleter);
      std::swap(privateData, other.privateData);
      return *this;
    }

    Collection<T> &operator=(const Collection<T> &other) {
      assign(other.hvl, nullptr);
      return *this;
    }

    Collection<T> &operator=(std::vector<T> &other) {
      assign(hvl_t{other.size(), other.data()}, nullptr);
      return *this;
    }

    size_t size() const { return hvl.len; }
    T *data() { return static_cast<T*>(hvl.p); }
    T &operator[](size_t i) { return data()[i]; }
  };

  /// \brief A span of size `len` starting at `offset`.
  struct Span {
    size_t offset;
    size_t len;
  };

  /// \brief A HDF5 span type which might be used by column models as index into a collection.
  struct H5Span_t {
    hid_t typeId;
    H5Span_t() {
      typeId = H5Tcreate(H5T_COMPOUND, sizeof(Span));
      assert(typeId != H5I_INVALID_HID && "Could not create H5Span compound type");
      H5Tinsert(typeId, "offset", HOFFSET(Span, offset), H5T_NATIVE_ULONG);
      H5Tinsert(typeId, "len", HOFFSET(Span, len), H5T_NATIVE_ULONG);
    }
    ~H5Span_t() { H5Tclose(typeId); }
  };
  static H5Span_t H5Span{};

  /// \brief Translate the C++ type `T` into a HDF5 type.
  template <typename T>
  constexpr hid_t GetH5TypeId() {
    using U = typename std::decay<T>::type;
    static_assert(!std::is_pointer<U>::value && !std::is_reference<U>::value,
		  "Pointer/references currently not supported");

    if constexpr (std::is_same<U, char>::value) return H5T_NATIVE_SCHAR;
    if constexpr (std::is_same<U, unsigned char>::value) return H5T_NATIVE_UCHAR;
    if constexpr (std::is_same<U, short>::value) return H5T_NATIVE_SHORT;
    if constexpr (std::is_same<U, unsigned short>::value) return H5T_NATIVE_USHORT;
    if constexpr (std::is_same<U, int>::value) return H5T_NATIVE_INT;
    if constexpr (std::is_same<U, unsigned int>::value) return H5T_NATIVE_UINT;
    if constexpr (std::is_same<U, long>::value) return H5T_NATIVE_LONG;
    if constexpr (std::is_same<U, unsigned long>::value) return H5T_NATIVE_ULONG;
    if constexpr (std::is_same<U, long long>::value) return H5T_NATIVE_LLONG;
    if constexpr (std::is_same<U, unsigned long long>::value) return H5T_NATIVE_ULLONG;
    if constexpr (std::is_same<U, float>::value) return H5T_NATIVE_FLOAT;
    if constexpr (std::is_same<U, double>::value) return H5T_NATIVE_DOUBLE;
    if constexpr (std::is_same<U, bool>::value) return H5T_NATIVE_HBOOL;
    return H5I_INVALID_HID;
  }

  namespace internal {
    hsize_t zero[] = {0};
    hsize_t one[] = {1};
    hsize_t unlimited[] = {H5S_UNLIMITED};
  } // namespace internal

} // namespace h5hep

#endif // _H5HEP_COMMON_HXX
