import os
import sys
import ROOT
from math import *

sys.path.append('python/')
sys.path.append('RDFprocessor/')

from RDFtree import *

from getLumiWeight import *
from basicSelection import *


def analysis(nthreads):
    # Enable multi-threading if needed
    if nthreads > 1:
        ROOT.ROOT.EnableImplicitMT(nthreads)
    else:
        ROOT.ROOT.DisableImplicitMT()

    ROOT.gSystem.Load('libSignalAnalysis.so')


    inputFile = os.path.join(os.environ["RB_DATASETDIR"], "wmass.root")

    p = RDFtree(outputDir = '.', inputFile = inputFile, outputFile="/dev/null")
    p.branch(nodeToStart = 'input', nodeToEnd = 'basicSelection', modules = [getLumiWeight(xsec=61526.7, inputFile=inputFile), ROOT.defineHarmonics(), basicSelection()])
    p.branch(nodeToStart = 'basicSelection', nodeToEnd = 'AngCoeff', modules = [ROOT.AngCoeff()])


    pdf = ROOT.vector('string')()
    for i in range(1,102):
        pdf.push_back('replica{}'.format(i))

    p.branch(nodeToStart = 'basicSelection', nodeToEnd = 'AngCoeffPDF', modules = [ROOT.defineSystWeight("LHEPdfWeight"),ROOT.AngCoeff(pdf,"LHEPdfWeight")])

    p.getOutput()

    p.branch(nodeToStart = 'AngCoeff', nodeToEnd = 'AngCoeff2',modules = [ROOT.getACValues([h for h in p.getObjects('AngCoeff') if 'vector' in type(h).__cpp_name__][0])])

    maps = ROOT.vector(ROOT.RDF.RResultPtr('TH2D'))()
    for i in range(0,3):
        maps.push_back([h for h in p.getObjects('AngCoeff') if not 'vector' in type(h).__cpp_name__][i])

    p.branch(nodeToStart = 'AngCoeff2', nodeToEnd = 'accMap', modules =[ROOT.getAccMap(maps)])
    p.branch(nodeToStart = 'accMap', nodeToEnd = 'templates', modules =[ROOT.getWeights(), ROOT.templateBuilder()])
    p.branch(nodeToStart = 'accMap', nodeToEnd = 'dataObs', modules =[ROOT.dataObs()])

    p.getOutput()

def test_rdataframe_wmass_imt(benchmark):
    benchmark.pedantic(analysis, kwargs={'nthreads': 8}, iterations=1, rounds=1)

def test_rdataframe_wmass_noimt(benchmark):
    benchmark.pedantic(analysis, kwargs={'nthreads': 1}, iterations=1, rounds=1)
