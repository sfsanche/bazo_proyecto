#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>

#include <TString.h>
#include <TMath.h>
#include <TFile.h>
#include <TStyle.h>
#include <TH2D.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TProfile2D.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TROOT.h>
#include <TLegend.h>
#include <TLeaf.h>
#include <TChain.h>
#include <TGraphErrors.h>

using namespace std;
int Comida(){
 TFile * file = new TFile("gntp.NumiFlux_C12.gst","REWRITE");
 TTree *t = (TTree*)file->Get("gst");
 t->Process("porfavorcito.C");
 }