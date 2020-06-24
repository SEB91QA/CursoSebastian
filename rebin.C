
TH1D* cambiarbin(TH1D *h_old){
 
  double BINS[]={0,20,100,500};
  int Nbins = 3; 

  TH1D *h_new = (TH1D*)h_old->Clone("h_new");	
  h_new->Sumw2();
  h_new->SetBins(Nbins, BINS);

  Int_t old_nbins = h_old->GetXaxis()->GetNbins();
  Int_t new_nbins = h_new->GetXaxis()->GetNbins();

  for (int b = 1; b <= new_nbins; b++ ){
	  cout << b << endl;
    Double_t Right_edge_new = h_new->GetXaxis()->GetBinLowEdge(b)+h_new->GetXaxis()->GetBinWidth(b);
    Double_t Edge_new = h_new->GetXaxis()->GetBinLowEdge(b);

    cout << Edge_new << "   " << Right_edge_new << endl;
    Double_t Num_back = 0.;
    Double_t error_back = 0.;

      for (int i = 1; i <= old_nbins; i++ ){
	      cout << "old "  <<i << endl;
      Double_t Right_edge_old = h_old->GetXaxis()->GetBinLowEdge(i)+h_old->GetXaxis()->GetBinWidth(i);
              cout << Right_edge_old << endl;
      if((Right_edge_old <= Right_edge_new) && (Right_edge_old > Edge_new)){ //Relevant Condition

        Num_back += h_old->GetBinContent(i);
        error_back += TMath::Power( h_old->GetBinError(i), 2 ) ;

      }
      else continue;

      h_new->SetBinContent(b, Num_back);
      h_new->SetBinError(b, TMath::Sqrt(error_back));

    } // loop over the old hist


  }  



  return h_new;  
}

void rebin(){

 TH1D *h1 = new TH1D("h1","h1", 500, 0., 500.);

 for(int i = 0; i < 10000; i++){
 h1->Fill(gRandom->Gaus(200.,200.));
 }
 h1->Draw();

 TFile *f1 = TFile::Open("W+Jets.root","UPDATE");
 TH1D *h2 = (TH1D*)f1->Get("Tau1MetMt");
 h2->Sumw2();

 cout << h2->GetBinError(1) << " " << h2->GetBinError(2) << endl;

 TH1D *rebinh1 = cambiarbin(h2); 

 cout << rebinh1->GetBinError(1) << endl;

 rebinh1->SetLineColor(2);
 rebinh1->Draw("");

 h2->Draw("same");
}


int main(){
rebin();
return 0;
}
