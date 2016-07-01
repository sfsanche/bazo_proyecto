#define signal_extractor_cxx
// The class definition in signal_extractor.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("signal_extractor.C")
// Root > T->Process("signal_extractor.C","some options")
// Root > T->Process("signal_extractor.C+")
//

#include "signal_extractor.h"
#include <TH2.h>
#include <TStyle.h>


void signal_extractor::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void signal_extractor::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t signal_extractor::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either signal_extractor::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

	fChain->GetEntry(entry);
	nmuons = 0;
	found_a_lepton = 0;

	//Encontrando dimuones:
	//Preguntar si es corriente cargada; entonces ya tenemos un lepton y resta buscar el otro en la parte hadrónica
	if(cc==1)
	{
		cout<<"Es corriente cargada: "<<cc<<endl;
		cout<<"Es un neutrino leptonico: "<<neu<<endl;	
		cout<<"Number of fs in ths hadronic system: "<<nf<<endl;
		
		//Retrieve first lepton 4-momentum
		pl1.SetPxPyPzE(pxl,pyl,pzl,El);	
		
		//Preguntar si es sabor muonico y el primer muón acompañará a este neutrino.
		if(neu==14 || neu==-14) nmuons++;
		
		//Buscar el segundo lepton en en pdgf
		for (int i=0; i<nf ;i++)
		{
			if(pdgf[i]==13 || pdgf[i]==-13 || pdgf[i]==11 || pdgf[i]==-11)
			{
				//Rettrieve second lepton 4-momentum
				pl2.SetPxPyPzE(pxf[i],pyf[i],pzf[i],Ef[i]);
				cout<<"El segundo lepton es: "<<pdgf[i]<<endl;		
				//Check if it's a muon
				if(pdgf[i]==13 || pdgf[i]==-13) nmuons++;
			}
		}
	
	}
	//Preguntar si es corriente neutra; entonces los dos leptones estan en la parte hadronica
	else if(nc==1)
	{
		cout<<"Es corriente neutra: "<<nc<<endl;
		cout<<"Number of fs in ths hadronic system: "<<nf<<endl;
		
		//Buscar dos leptones en pdgf
		for (int i=0; i<nf ;i++)
		{
			if(pdgf[i]==13 || pdgf[i]==-13 || pdgf[i]==11 || pdgf[i]==-11)
			{
				//Aqui se buscan los leptones.
				cout<<"es un lepton: "<<pdgf[i]<<endl;		
				cout<<"entrada : "<<i<<endl;
				//Retrieve their 4-momenta
				if(found_a_lepton)	
				{
					pl2.SetPxPyPzE(pxf[i],pyf[i],pzf[i],Ef[i]);
				}	
				else		
				{		
					pl1.SetPxPyPzE(pxf[i],pyf[i],pzf[i],Ef[i]);
					found_a_lepton = 1;
				}
				
				//Check if we've got a muon
				if(pdgf[i]==13 || pdgf[i]==-13) nmuons++;
			}
		}	
	}

	
	
	//Now calculate the lepton pair invariant mass
	Wlep = (pl1+pl2).Mag();

	//Store the new values
	b_nmuons -> Fill();
	b_Wlep	 -> Fill();

   return kTRUE;
}

void signal_extractor::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void signal_extractor::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.


	//Save the updated tree with the new branches (only the newest instance)
	fChain -> Write("", TObject::kOverwrite);

}
