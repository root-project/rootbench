from module import *

class getLumiWeight(module):
   
    def __init__(self,xsec, inputFile, targetLumi = 35.9):
        
        self.myTH1 = []
        self.myTH2 = []
        self.myTH3 = []

        self.myTH1Group = []
        self.myTH2Group = []
        self.myTH3Group = []

        self.xsec = xsec / 0.001
        self.inputFile = inputFile
        self.targetLumi = targetLumi

    def run(self,d):

        self.d = d

        RDF = ROOT.ROOT.RDataFrame
        runs = RDF('Runs', self.inputFile)

         
        genEventSumw = runs.Sum("genEventSumw").GetValue()

        #print 'genEventSumw : '+'{:1.1f}'.format(genEventSumw)+' weighted events'
        #print 'xsec         : '+'{:1.1f}'.format(self.xsec)+' fb'
        #print 'lumiweight   : '+'{:1.8f}'.format((1.*self.xsec)/genEventSumw)

        self.d = self.d.Define('lumiweight', 'float(({L}*{xsec}*Generator_weight)/({genEventSumw}))'.format(L=self.targetLumi, genEventSumw = genEventSumw, xsec = self.xsec))\
        .Define('genEventSumw','{genEventSumw}'.format(genEventSumw = genEventSumw))
        
        return self.d

    def getTH1(self):

        return self.myTH1

    def getTH2(self):

        return self.myTH2  

    def getTH3(self):

        return self.myTH3

    def getGroupTH1(self):

        return self.myTH1Group

    def getGroupTH2(self):

        return self.myTH2Group  

    def getGroupTH3(self):

        return self.myTH3Group  

    def reset(self):

        self.myTH1 = []
        self.myTH2 = []
        self.myTH3 = [] 

        self.myTH1Group = []
        self.myTH2Group = []
        self.myTH3Group = [] 
