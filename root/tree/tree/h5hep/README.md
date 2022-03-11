# h5hep: (unsupported, unofficial) header-only library to read/write high-energy physics data in HDF5
THIS CODE IS FOR BENCHMARK PURPOSES ONLY; DO NOT USE IN PRODUCTION.

h5hep allows the storage of simple HEP data in HDF5, hiding away the details of data representation. Currently, it supports two different column models:

- COMPOUND_TYPE: that uses (possibly nested) compound types to represent data for each row.

- COLUMNAR_FNAL: uses one HDF5 dataset per primitive column. Collections are translated to a HDF5 group and an index column. For more information, see [this](https://inspirehep.net/files/e048b0cd122919dc9a009793983a81e0) publication.

## Example
The Makefile in the examples/ directory generates two versions of [simple_struct.cxx](https://github.com/jalopezg-r00t/h5hep/blob/root/tree/tree/h5hep/master/examples/simple_struct.cxx): `simple_struct_compound` and `simple_struct_fnal`. As seen below, both generate the same output:
```bash
$ ./simple_struct_compound
i=0 f=1.2345
i=1 f=2.2345
i=2 f=3.2345
i=3 f=4.2345
$ ./simple_struct_fnal
i=0 f=1.2345
i=1 f=2.2345
i=2 f=3.2345
i=3 f=4.2345
```

However, the HDF5 representation of the schema and user data is completely different:
```bash
$ # For ./simple_struct_compound
$ h5dump simple_struct.h5
HDF5 "simple_struct.h5" {
GROUP "/" {
   DATASET "Foo" {
      DATATYPE  H5T_COMPOUND {
         H5T_STD_I32LE "i";
         H5T_IEEE_F32LE "f";
         H5T_VLEN { H5T_COMPOUND {
            H5T_IEEE_F32LE "f1";
            H5T_IEEE_F32LE "f2";
         }} "c";
      }
      DATASPACE  SIMPLE { ( 4 ) / ( H5S_UNLIMITED ) }
      DATA {
      (0): {
            0,
            1.2345,
            ({
                  1.1,
                  1.2
               }, {
                  2.1,
                  2.2
               }, {
                  3.1,
                  3.2
               })
         },
...
$ # For ./simple_struct_fnal
$ h5dump simple_struct.h5
HDF5 "simple_struct.h5" {
GROUP "/" {
   ATTRIBUTE "$Metadata" {
      DATATYPE  H5T_STD_U64LE
      DATASPACE  SIMPLE { ( 2 ) / ( 2 ) }
      DATA {
      (0): 4, 4
      }
   }
   GROUP "c" {
      DATASET "Event ID" {
         DATATYPE  H5T_STD_U64LE
         DATASPACE  SIMPLE { ( 12 ) / ( H5S_UNLIMITED ) }
         DATA {
         (0): 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3
         }
      }
      DATASET "f1" {
         DATATYPE  H5T_IEEE_F32LE
         DATASPACE  SIMPLE { ( 12 ) / ( H5S_UNLIMITED ) }
         DATA {
         (0): 1.1, 2.1, 3.1, 1.1, 2.1, 3.1, 1.1, 2.1, 3.1, 1.1, 2.1, 3.1
         }
      }
      DATASET "f2" {
         DATATYPE  H5T_IEEE_F32LE
         DATASPACE  SIMPLE { ( 12 ) / ( H5S_UNLIMITED ) }
         DATA {
         (0): 1.2, 2.2, 3.2, 1.2, 2.2, 3.2, 1.2, 2.2, 3.2, 1.2, 2.2, 3.2
         }
      }
   }
   DATASET "f" {
      DATATYPE  H5T_IEEE_F32LE
      DATASPACE  SIMPLE { ( 4 ) / ( H5S_UNLIMITED ) }
      DATA {
      (0): 1.2345, 2.2345, 3.2345, 4.2345
      }
   }
   DATASET "i" {
      DATATYPE  H5T_STD_I32LE
      DATASPACE  SIMPLE { ( 4 ) / ( H5S_UNLIMITED ) }
      DATA {
      (0): 0, 1, 2, 3
      }
   }
}
}
```
