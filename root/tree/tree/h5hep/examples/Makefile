CFLAGS=-std=c++17 -O2 -Wall -I..
LDFLAGS=-lhdf5

all: simple_struct_compound simple_struct_fnal

clean:
	rm -f simple_struct_compound simple_struct_fnal simple_struct.h5

simple_struct_compound: simple_struct.cxx
	g++ $(CFLAGS) $(LDFLAGS) -D__COLUMN_MODEL__=h5hep::ColumnModel::COMPOUND_TYPE -o $@ $^

simple_struct_fnal: simple_struct.cxx
	g++ $(CFLAGS) $(LDFLAGS) -D__COLUMN_MODEL__=h5hep::ColumnModel::COLUMNAR_FNAL -o $@ $^
