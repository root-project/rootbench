import os
import ROOT
import copy

ROOT.gInterpreter.Declare('TH1D *Obj2TH1D(TObject *p) { return (TH1D*)p; }')

class plotter:
    
    def __init__(self, outdir, folder = '', fileList = [], norm = 1, tag =''):

        self.folder = folder # folder containig the various outputs
        self.fileList = fileList # list of files in each folders
        self.canvas = []
        self.outdir = outdir
        self.norm = norm
        self.tag = tag
        self.colours =[ROOT.kRed, ROOT.kGreen+2, ROOT.kBlue, ROOT.kMagenta+1, ROOT.kOrange+7, ROOT.kCyan+1, ROOT.kGray+2, ROOT.kViolet+5, ROOT.kSpring+5, ROOT.kAzure+1, ROOT.kPink+7, ROOT.kOrange+3, ROOT.kBlue+3, ROOT.kMagenta+3, ROOT.kRed+2]
        
        ROOT.gROOT.SetBatch()

        if not os.path.exists(self.outdir):
            os.system("mkdir -p " + self.outdir)

    def getHistos(self):


        self.histos = []

        os.chdir(self.folder)

        for f in self.fileList:


            hlist = []
            
            fIn = ROOT.TFile.Open(f)

            for key in fIn.GetListOfKeys():

                if key.InheritsFrom(ROOT.TH2D.Class()): continue

                h = fIn.Get(key.GetName())
                
                h.Sumw2()
                    
                hlist.append((copy.deepcopy(h),f.split('_')[0]))

            self.histos.append(hlist)


        os.chdir('..')

        self.histos = zip(*self.histos) # now in the right order

    def plotStack(self):

        pave_cms = ROOT.TPaveText(0.16,0.82,0.42,0.89, "NDC")
        pave_cms.SetFillStyle(0);
        pave_cms.SetBorderSize(0);
        pave_cms.SetTextAlign(12)
        pave_cms.SetTextSize(0.06)
        #pave_cms.SetTextFont(61)
        pave_cms.AddText("CMS")
        pave_prel = ROOT.TPaveText(0.16,0.75,0.42,0.82, "NDC")
        pave_prel.SetFillStyle(0);
        pave_prel.SetBorderSize(0);
        pave_prel.SetTextAlign(12)
        pave_prel.SetTextSize(0.045)
        pave_prel.SetTextFont(52)
        pave_prel.AddText("Preliminary")
        pave_lumi = ROOT.TPaveText(0.484,0.90,0.92,0.96, "NDC")
        pave_lumi.SetFillStyle(0);
        pave_lumi.SetBorderSize(0);
        pave_lumi.SetTextAlign(32)
        pave_lumi.SetTextSize(0.05)
        pave_lumi.SetTextFont(42)
        pave_lumi.AddText(("%.2f fb^{-1} (2016)" % self.norm))

        self.getHistos()

        self.stacks = []

        for group in self.histos: 

            print (group[0])[0].GetName()

            hs = ROOT.THStack((group[0])[0].GetName(),"")

            c = ROOT.TCanvas(hs.GetName(), '')

            legend = ROOT.TLegend(0.62, 0.70, 0.82, 0.88)
            legend.SetFillColor(0)
            legend.SetBorderSize(0)
            legend.SetTextSize(0.03)

            hdata = ROOT.TH1D()
            for i,tup in enumerate(group):

                if 'Data' in tup[1]: 
                    legend.AddEntry(tup[1], "Data", "PE1")
                    hdata = tup[0]
                    hdata.SetMarkerStyle(20)
                    hdata.SetMarkerColor(ROOT.kBlack)
                    continue

                legend.AddEntry(tup[0], tup[1], "f")
                tup[0].Scale(self.norm)
                tup[0].SetFillStyle(1001)
                tup[0].SetLineWidth(0)
                tup[0].SetFillColor(self.colours[i])
                hs.Add(tup[0])

            c.SetTicks(0, 1)
            c.cd()

            maxdata = hdata.GetMaximum()
            maxstack = hs.GetMaximum()

            hs.SetMaximum(1.5*max(maxdata,maxstack))
            hs.Draw("HIST")
            hs.GetXaxis().SetTitle(hdata.GetXaxis().GetTitle())
            #hdata.Draw("same")

            rp = ROOT.TRatioPlot(hs, hdata)
            rp.Draw()
            rp.GetLowerRefYaxis().SetRangeUser(0,2)
            rp.GetLowYaxis().SetNdivisions(505)
            rp.GetLowerRefYaxis().SetTitle("MC / DATA")

            legend.Draw()
            pave_cms.Draw("same")
            pave_prel.Draw("same")
            pave_lumi.Draw("same")


            c.Update()
            c.SaveAs("{dir}/{c}_{t}.pdf".format(dir=self.outdir,c=c.GetName(), t=self.tag))
            c.SaveAs("{dir}/{c}_{t}.png".format(dir=self.outdir,c=c.GetName(), t=self.tag))
       

            
            

    def plotDataMC(self):

        
        self.getHistos()

        for group in self.histos: # group of histos with same name

            legend = ROOT.TLegend(0.62, 0.70, 0.82, 0.88)
            legend.SetFillColor(0)
            legend.SetBorderSize(0)
            legend.SetTextSize(0.03)

            legend.AddEntry(group[0], "Data", "PE1")
            legend.AddEntry(group[1], "MC", "f")

            group[0].Scale(1./group[0].Integral())
            group[1].Scale(1./group[1].Integral())
            
            c = ROOT.TCanvas(group[0].GetName(), '')
            rp = ROOT.TRatioPlot(group[0], group[1])
            
            #group[1].SetLineWidth(2)
            #group[1].SetFillStyle(1001)
            #group[1].SetLineColor(ROOT.kBlack)
            #group[1].SetFillColor(ROOT.kAzure - 9)

            c.SetTicks(0, 1)
            rp.GetLowYaxis().SetNdivisions(505)
            c.cd()
            rp.Draw()

            h = ROOT.Obj2TH1D(rp.GetUpperRefObject())
            h.SetMarkerStyle(ROOT.kFullCircle)
            h.SetLineWidth(1)
            h.SetMarkerSize(1.0)
            h.SetMarkerColor(ROOT.kBlack)
            h.SetLineColor(ROOT.kBlack)

            legend.Draw()

            c.Update()
            c.SaveAs("{dir}/{c}.pdf".format(dir=self.outdir,c=c.GetName()))
            
            #self.canvas.append(copy.deepcopy(c))

    def plotDataMCDiff(self):

        self.getHistos()

        for group in self.histos: # group of histos with same name

            legend = ROOT.TLegend(0.62, 0.70, 0.82, 0.88)
            legend.SetFillColor(0)
            legend.SetBorderSize(0)
            legend.SetTextSize(0.03)

            legend.AddEntry(group[0], "Data", "PE1")
            legend.AddEntry(group[1], "MC", "f")
            
            c = ROOT.TCanvas(group[0].GetName(), '')
            rp = ROOT.TRatioPlot(group[0], group[1],'diff')
            
            #group[1].SetLineWidth(2)
            #group[1].SetFillStyle(1001)
            #group[1].SetLineColor(ROOT.kBlack)
            #group[1].SetFillColor(ROOT.kAzure - 9)

            c.SetTicks(0, 1)
            rp.GetLowYaxis().SetNdivisions(505)
            c.cd()
            rp.Draw()

            h = ROOT.Obj2TH1D(rp.GetUpperRefObject())
            h.SetMarkerStyle(ROOT.kFullCircle)
            h.SetLineWidth(1)
            h.SetMarkerSize(1.0)
            h.SetMarkerColor(ROOT.kBlack)
            h.SetLineColor(ROOT.kBlack)

            legend.Draw()

            c.Update()
            c.SaveAs("{dir}/{c}.pdf".format(dir=self.outdir,c=c.GetName()))
            
            #self.canvas.append(copy.deepcopy(c))

            
                
                



                                  

    