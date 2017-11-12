// ------------------------- //
// table.C -- root macro
// Author: Mizukoshi Keita
// 2017.Nov.12
// ------------------------- //

void table(TString file = "iron_u.dat"){

	string  	buf;
	Double_t 	val,val2;
	ifstream ifs(file);
    TString  output = "table_" + file;
    ofstream ofs(output);

    while(true){
		getline(ifs,buf);
        if(buf.size()>10)if(buf.substr(0,10) == "# Integral")break;
	}

    while(ifs >> val >> val2){
        ofs << val << " " << val2 << std::endl;
    }

}
