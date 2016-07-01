{
	//Get a pointer to the data tree
	TFile f("../lair/pollo.gst.root","update");
	TTree * gst = (TTree*) f.Get("gst");

	//Process the tree with the previously created TSelector
	gst->Process("signal_extractor.C");

}
