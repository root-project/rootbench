# Base class from which the other modules will inherit
import ROOT
from header import *

class module:
   
    def __init__(self):
        
        self.myTH1 = []
        self.myTH2 = []
        self.myTH3 = []

        self.myTH1Group = []
        self.myTH2Group = []
        self.myTH3Group = []
        

    def run(self,d):

        pass 


    def defineSubcollectionFromIndex(self, collection, subcollection, idx, d1, syst={}):

        columns = list(d1.GetColumnNames())
        columns.extend(d1.GetDefinedColumnNames())

        #remove duplicates
        columns = list(dict.fromkeys(columns))

        subSetWithSyst = []
        mainWithSyst = []

        if syst:

            for nom, variations in syst.iteritems(): 

                if len(variations)>0: # case variations

                    main = [c for c in columns if c.startswith(collection) and nom in c] # columns of the main collection
                
                    subSet = [c.replace(collection,subcollection) for c in main] # columns of the sub collection if affected by the syst

                    for var in variations:
                        subSetWithSyst.extend([c.replace(nom,var) for c in subSet]) # now with systematics
                        mainWithSyst.extend([c.replace(nom,var) for c in main])

                    for i,s in enumerate(subSetWithSyst):
                        d1 = d1.Define(s, '{vec}[{idx}]'.format(vec=mainWithSyst[i], idx=idx))

                else: #case nominal

                    main = [c for c in columns if c.startswith(collection)] # columns of the main collection
                    mainNom = [c for c in main if not 'Up' in c]
                    mainNom2 = [c for c in mainNom if not 'Down' in c]

                    subSet = [c.replace(collection,subcollection) for c in mainNom2 ]
                    subSetNom = [c for c in subSet if not 'Up' in c]
                    subSetNom2 = [c for c in subSetNom if not 'Down' in c]

                    for i,s in enumerate(subSetNom2):
                        
                        d1 = d1.Define(s, '{vec}[{idx}]'.format(vec=mainNom2[i], idx=idx))

                    # define new vector length 

                    d1 = d1.Define("n{}".format(subcollection), "{}".format(1))
        else:

            main = [c for c in columns if c.startswith(collection)] # columns of the main collection
            mainNom = [c for c in main if not 'Up' in c]
            mainNom2 = [c for c in mainNom if not 'Down' in c]


            subSet = [c.replace(collection,subcollection) for c in mainNom2 ]
            subSetNom = [c for c in subSet if not 'Up' in c]
            subSetNom2 = [c for c in subSetNom if not 'Down' in c]

            for i,s in enumerate(subSetNom2):
                
                d1 = d1.Define(s, '{vec}[{idx}]'.format(vec=mainNom2[i], idx=idx))

            # define new vector length 

            d1 = d1.Define("n{}".format(subcollection), "{}".format(1))

        return d1


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

