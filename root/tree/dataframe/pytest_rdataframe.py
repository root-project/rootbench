import numpy as np
import pytest

import ROOT


def payload_test_asnumpy_simple():
    df = ROOT.RDataFrame(10)
    x = df.Define('x', 'rdfentry_').AsNumpy(['x'])
    return np.sum(x['x'])

def test_asnumpy_simple(benchmark):
    r = benchmark(payload_test_asnumpy_simple)
    assert(r == 45)
