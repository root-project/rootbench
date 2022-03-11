# h5hep: header-only library to read/write high-energy physics data in HDF5
This code is for benchmark purposes only; do NOT use in production.

Example of use:
```c++
#include <h5hep/h5hep.hxx>

struct Bar {
  float f1;
  float f2;
};

struct Foo {
  int i;
  float f;
  h5hep::Collection<Bar> c;
};

int main(int argc, char *argv[]) {
  using Builder = h5hep::schema::SchemaBuilder<h5hep::ColumnModel::COMPOUND_TYPE>;
  
  auto root = Builder::MakeStructNode<Foo>("Foo", {
      Builder::MakePrimitiveNode<int>("i", HOFFSET(Foo, i)),
      Builder::MakePrimitiveNode<float>("f", HOFFSET(Foo, f)),
      Builder::MakeCollectionNode("c", HOFFSET(Foo, c),
				  Builder::MakeStructNode<Bar>("Bar", {
				      Builder::MakePrimitiveNode<float>("f1", HOFFSET(Bar, f1)),
				      Builder::MakePrimitiveNode<float>("f2", HOFFSET(Bar, f2)),
				    })),
    });

  // ...
  return 0;
}
```