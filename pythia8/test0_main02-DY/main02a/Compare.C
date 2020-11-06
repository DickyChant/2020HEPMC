{
#include "TAxis.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TNtupleD.h"
#include <stdio.h>
#include <stdlib.h>



	TFile * input1 = new TFile ("p6.root");
        input1->cd("");
        TTree *Outtree1 = (TTree*)input1->Get("tree");

	TFile * input2 = new TFile ("p80.root");
        input2->cd("");
        TTree *Outtree2 = (TTree*)input2->Get("t");
 
	TFile * input3 = new TFile ("p81.root");
        input3->cd("");
        TTree *Outtree3 = (TTree*)input3->Get("t");

	TFile * input4 = new TFile ("p82.root");
        input4->cd("");
        TTree *Outtree4 = (TTree*)input4->Get("t");


       int nentries1 = (int)Outtree1->GetEntries();
       cout<<"nentries1 = "<<nentries1<<endl;
       int nentries2 = (int)Outtree2->GetEntries();
       cout<<"nentries2 = "<<nentries2<<endl;
       int nentries3 = (int)Outtree3->GetEntries();
       cout<<"nentries3 = "<<nentries3<<endl;
       int nentries4 = (int)Outtree4->GetEntries();
       cout<<"nentries3 = "<<nentries4<<endl;

       TH1D *PTA1   = new TH1D("a"," ",20,0,100);
       PTA1->Sumw2();
       TH1D *PTA2   = new TH1D("b"," ",20,0,100);
       PTA2->Sumw2();
       TH1D *PTA3   = new TH1D("c"," ",20,0,100);
       PTA3->Sumw2();
       TH1D *PTA4   = new TH1D("d"," ",20,0,100);
       PTA4->Sumw2();
       double ptz1,ptz2,ptz3,ptz4;

       Outtree1->SetBranchAddress("ptz" ,&ptz1);
       Outtree2->SetBranchAddress("ptz" ,&ptz2);
       Outtree3->SetBranchAddress("ptz" ,&ptz3);
       Outtree4->SetBranchAddress("ptz" ,&ptz4);

       for(int i=0; i<nentries1; i++)
     {
         Outtree1->GetEntry(i);
         PTA1->Fill(ptz1,1.0/float(nentries1));
     } 

       for(int i=0; i<nentries2; i++)
     {
         Outtree2->GetEntry(i);
         PTA2->Fill(ptz2,1.0/float(nentries2));
     } 
 
       for(int i=0; i<nentries3; i++)
     {
         Outtree3->GetEntry(i);
         PTA3->Fill(ptz3,1.0/float(nentries3));
     } 

       for(int i=0; i<nentries4; i++)
     {
         Outtree4->GetEntry(i);
         PTA4->Fill(ptz4,1.0/float(nentries4));
     } 

      TCanvas *c01 = new TCanvas("c01","",700,500);
      c01->SetLogy();
      PTA1->SetTitle("pp #rightarrow z #rightarrow #mu^{+}#mu^{-} at 13TeV LHC");
      PTA1->GetXaxis()->SetTitle("Z PT [GeV] ");
      PTA1->GetYaxis()->SetTitle("a.u.");
      PTA1->GetXaxis()->CenterTitle();
      PTA1->GetYaxis()->CenterTitle();
      PTA1->SetStats(kFALSE);
      PTA1->SetLineColor(kBlack);
      PTA1->SetLineWidth(3);
      PTA1->SetMarkerStyle(20);
      PTA1->GetXaxis()->SetTitleOffset(1.4);
      PTA1->Draw("e HIST");

      PTA2->SetLineColor(kRed);
      PTA2->SetLineWidth(2);
      PTA2->Draw("e same");
 
      PTA3->SetLineColor(kBlue);
      PTA3->SetLineWidth(2);
      PTA3->Draw("e same");     
 
      PTA4->SetLineColor(kGreen);
      PTA4->SetLineWidth(2);
      PTA4->Draw("e same");     

     TLegend *l1 = new TLegend(0.62,0.65,0.86,0.85);
     l1->SetBorderSize(1);
     l1->SetFillColor(0);
     l1->AddEntry(PTA1,"MG242+Pythia6");
     l1->AddEntry(PTA2,"Pythia8 pTmaxMatch_0");
     l1->AddEntry(PTA3,"Pythia8 pTmaxMatch_1");
     l1->AddEntry(PTA4,"Pythia8 pTmaxMatch_2");

     l1->Draw();


     c01->SaveAs("compare-ptll2.png");

}
