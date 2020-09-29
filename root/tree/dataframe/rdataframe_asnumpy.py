import numpy as np
import pytest
import os

import ROOT

nanoaod_file = os.path.join(os.environ["RB_DATASETDIR"], "Run2012BC_DoubleMuParked_Muons.root")
ntuple_file = os.path.join(os.environ["RB_DATASETDIR"], "data_A.GamGam.root")

# Simple AsNumpy benchmark processing a minimal amount of data from memory

def payload_asnumpy_simple():
    df = ROOT.RDataFrame(10)
    x = df.Define('x', 'rdfentry_').AsNumpy(['x'])
    return np.sum(x['x'])

def test_rdataframe_asnumpy_simple(benchmark):
    ROOT.DisableImplicitMT()
    r = benchmark(payload_asnumpy_simple)
    assert(r == 45)

# Read from a NanoAOD file a scalar type branch with millions of events

def payload_asnumpy_nanoaod_scalar(nthreads):
    if nthreads > 1: ROOT.EnableImplicitMT(nthreads)
    df = ROOT.RDataFrame('Events', nanoaod_file)
    df.AsNumpy(['nMuon'])

def test_rdataframe_asnumpy_nanoaod_scalar_noimt(benchmark):
    ROOT.DisableImplicitMT()
    benchmark.pedantic(payload_asnumpy_nanoaod_scalar, kwargs={'nthreads': 1}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_nanoaod_scalar_imt(benchmark):
    ROOT.DisableImplicitMT()
    benchmark.pedantic(payload_asnumpy_nanoaod_scalar, kwargs={'nthreads': 8}, iterations=1, rounds=1)

# Read from a NanoAOD file a vector type branch with millions of events

def payload_asnumpy_nanoaod_vector(nthreads):
    if nthreads > 1: ROOT.EnableImplicitMT(nthreads)
    df = ROOT.RDataFrame('Events', nanoaod_file)
    df.AsNumpy(['Muon_pt'])

def test_rdataframe_asnumpy_nanoaod_vector_noimt(benchmark):
    ROOT.DisableImplicitMT()
    benchmark.pedantic(payload_asnumpy_nanoaod_vector, kwargs={'nthreads': 1}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_nanoaod_vector_imt(benchmark):
    ROOT.DisableImplicitMT()
    benchmark.pedantic(payload_asnumpy_nanoaod_vector, kwargs={'nthreads': 8}, iterations=1, rounds=1)

# Read from a flat ntuple file of a small size branches in various configurations

def payload_asnumpy_manybranches(nthreads, columns):
    if nthreads > 1: ROOT.EnableImplicitMT(nthreads)
    df = ROOT.RDataFrame('mini', ntuple_file)
    df.AsNumpy(columns)

def get_column_names(vectors=False, booleans=False, scalars=False):
    '''
    Get column names for the "manybranches" benchmarks

    Arguments:
        vectors: boolean, take columns with vectors (containing rvec in the typename)
        booleans: boolean, take columns with booleans
        scalars: boolean, take columns with other scalar types (containing int and float in the typename)

    Returns:
        vector<string> of column names
    '''
    df = ROOT.RDataFrame('mini', ntuple_file)
    columns = ROOT.std.vector('string')()
    for col in df.GetColumnNames():
        typename = str(df.GetColumnType(col)).lower()
        is_boolean = True if 'bool' in typename else False
        is_vector = True if 'rvec' in typename else False
        is_scalar = True if 'int' in typename or 'float' in typename else False
        if (vectors and is_vector) or (booleans and is_boolean) or (scalars and is_scalar):
            columns.push_back(col)
    return columns

def test_rdataframe_asnumpy_manybranches_booleans_noimit(benchmark):
    ROOT.DisableImplicitMT()
    columns = get_column_names(booleans=True)
    benchmark.pedantic(payload_asnumpy_manybranches, kwargs={'nthreads': 1, 'columns': columns}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_manybranches_booleans_imt(benchmark):
    ROOT.DisableImplicitMT()
    columns = get_column_names(booleans=True)
    benchmark.pedantic(payload_asnumpy_manybranches, kwargs={'nthreads': 8, 'columns': columns}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_manybranches_scalars_noimit(benchmark):
    ROOT.DisableImplicitMT()
    columns = get_column_names(scalars=True)
    benchmark.pedantic(payload_asnumpy_manybranches, kwargs={'nthreads': 1, 'columns': columns}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_manybranches_scalars_imt(benchmark):
    ROOT.DisableImplicitMT()
    columns = get_column_names(scalars=True)
    benchmark.pedantic(payload_asnumpy_manybranches, kwargs={'nthreads': 8, 'columns': columns}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_manybranches_vectors_noimit(benchmark):
    ROOT.DisableImplicitMT()
    columns = get_column_names(vectors=True)
    benchmark.pedantic(payload_asnumpy_manybranches, kwargs={'nthreads': 1, 'columns': columns}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_manybranches_vectors_imt(benchmark):
    ROOT.DisableImplicitMT()
    columns = get_column_names(vectors=True)
    benchmark.pedantic(payload_asnumpy_manybranches, kwargs={'nthreads': 8, 'columns': columns}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_manybranches_all_noimit(benchmark):
    ROOT.DisableImplicitMT()
    columns = get_column_names(vectors=True, scalars=True, booleans=True)
    benchmark.pedantic(payload_asnumpy_manybranches, kwargs={'nthreads': 1, 'columns': columns}, iterations=1, rounds=1)

def test_rdataframe_asnumpy_manybranches_all_imt(benchmark):
    ROOT.DisableImplicitMT()
    columns = get_column_names(vectors=True, scalars=True, booleans=True)
    benchmark.pedantic(payload_asnumpy_manybranches, kwargs={'nthreads': 8, 'columns': columns}, iterations=1, rounds=1)
