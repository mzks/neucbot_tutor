// ------------------------- //
// show.C -- root macro
// Author: Mizukoshi Keita
// 2017.Nov.12
// ------------------------- //


void show(TString file = "./iron_u.dat"){
    auto C = new TCanvas();

	string  	buf;
	Double_t 	val,val2;
	ifstream ifs(file);

    while(true){
		if(!getline(ifs,buf)){
            std::cerr << "No such file" << std::endl;
            return;
        }
        if(buf.size()>10)if(buf.substr(0,10) == "# Integral")break;
	}
    
    const Double_t MIN = 0;         //keV
    const Double_t MAX = 20000;     //keV
    const Double_t BIN_WIDTH = 100;   //keV

	auto hist = new TH1D(file,"hist",MAX/BIN_WIDTH+1,MIN-BIN_WIDTH/2.0,MAX+BIN_WIDTH/2.0);
    while(ifs >> val >> val2){
        hist->Fill(val,val2);
    }

    C->SetLogy();
    hist->SetMarkerStyle(kOpenCircle);
    hist->SetLineStyle(0);
	hist->SetTitle(";Energy(keV);Counts /decay /100keV");
    hist->SetStats(0);
	hist->Draw("hist");

    C->BuildLegend();
    
}
