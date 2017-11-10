void show(TString file = "test"){

    auto C = new TCanvas();

	string  	buf;
	Double_t 	val,val2;
	ifstream ifs(file);

    while(true){
		getline(ifs,buf);
        if(buf.size()>10)if(buf.substr(0,10) == "# Integral")break;
	}

    const Double_t MIN = 0;         //keV
    const Double_t MAX = 20000;     //keV
    const Double_t BIN_WIDTH = 100;   //keV

	auto hist = new TH1D("hist","hist",MAX/BIN_WIDTH+1,MIN-BIN_WIDTH/2.0,MAX+BIN_WIDTH/2.0);
    while(ifs >> val >> val2){
        hist->Fill(val,val2);
    }

    C->SetLogy();
    hist->SetMarkerStyle(kOpenCircle);
    hist->SetLineStyle(0);
	hist->SetTitle(";Energy(keV);Counts /decay /100keV");
	hist->Draw("hist");
}
