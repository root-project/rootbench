#include <h5hep/h5hep.hxx>
#include <iostream>

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
  using Builder = h5hep::schema::SchemaBuilder<__COLUMN_MODEL__>;
  {
    auto root = Builder::MakeStructNode<Foo>("Foo", {
	Builder::MakePrimitiveNode<int>("i", HOFFSET(Foo, i)),
	Builder::MakePrimitiveNode<float>("f", HOFFSET(Foo, f)),
	Builder::MakeCollectionNode("c", HOFFSET(Foo, c),
				    Builder::MakeStructNode<Bar>("Bar", {
					Builder::MakePrimitiveNode<float>("f1", HOFFSET(Bar, f1)),
					Builder::MakePrimitiveNode<float>("f2", HOFFSET(Bar, f2)),
				      })),
      });

    h5hep::WriteProperties props;
    props.SetChunkSize(4);
    props.SetCompressionLevel(0);
    auto file = h5hep::H5File::Create("simple_struct.h5");
    auto rw = Builder::MakeReaderWriter(file, root, props);

    Foo chunk[4]{};
    std::vector<Bar> v{{1.1, 1.2}, {2.1, 2.2}, {3.1, 3.2}};
    for (size_t i = 0; i < 4; ++i) {
      chunk[i].i = i;
      chunk[i].f = i + 1.2345f;
      chunk[i].c = v;
    }
    rw->WriteChunk(0, chunk);
  }

  {
    // The schema for reading selects only a few columns
    auto root = Builder::MakeStructNode<Foo>("Foo", {
	Builder::MakePrimitiveNode<int>("i", HOFFSET(Foo, i)),
	Builder::MakePrimitiveNode<float>("f", HOFFSET(Foo, f)),
      });

    auto file = h5hep::H5File::Open("simple_struct.h5");
    auto rw = Builder::MakeReaderWriter(file, root);

    Foo chunk[4]{};
    rw->ReadChunk(0, chunk);
    for (size_t i = 0; i < 4; ++i) {
      std::cout << "i=" << chunk[i].i << " f=" << chunk[i].f << std::endl;
    }
  }
  return 0;
}
