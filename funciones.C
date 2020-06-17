// paso por referencia a una funcion
void CambiarA(int &a){

  cout << " local memory " << &a << endl; 	
  a = 10;
  cout << " a local: " << a << endl; 

}

void FillHisto( TH1D h1, int Nentries, string label){

	for(int i = 0; i < 100; i++){
	h1.Fill(3);
	h1.SetTitle(label.c_str());
 	Nentries++;
	}
        cout << Nentries << endl;
}

void CambiarEjeX( TH1D *h1 ){
   h1->GetXaxis()->SetTitle("Nose");
   cout  << " histograma en memoria local "  << h1 << endl;
}

void funciones(){
 
   //variable global	
   int a = 100;
   cout << " Global memory "  << &a << endl;
  
   CambiarA(a);

   cout << " a global " << a << endl; 

   TH1D *h1 = new TH1D("h1","h1", 50, 0.,50.);
   cout  << " histograma h1 en memoria global "  << h1 << endl;
 
   int Nentries = 0;

   TLorentzVector muon1(20.,0.,0.,0.);
   TLorentzVector muon2(40.,0.,0.,0.);


   std::vector<TLorentzVector> MUON;
   MUON.push_back(muon1);
   MUON.push_back(muon2);


   double sum = MUON[0].Px()+MUON[1].Px();

   double sum2=0;

   int value = 10;
   for(long int i = 0; i < 1E+10; i++){ 

      if(i == value){
      	cout << " i: " << i <<endl;
	break;
      }

   }

   int j = 0;
   std::vector<int> *vector1 = new std::vector<int>;
   while( j != 50  ){
   cout << " while " << j << endl;
   vector1->push_back(j);

   if(j == 49) continue;
   j++;
   }   


   cout << " vector size  " << vector1->size() << endl;


   cout << " componente 3 " << MUON[1].Px() <<  " suma total " << sum <<  endl; 

   FillHisto(*h1, Nentries, "My Histogram");
   cout << " Global " << Nentries << endl;

   CambiarEjeX(h1);

  h1->Draw(); 

    //TH1D *h2 ;
	    //= new TH1D("h1","h2", 50, 0.,50.);;
    //cout  << " histograma h2 en memoria global "  << h2 << endl;
    //h2->Fill(2);

   // delete h1; 
}  

int main(){
  funciones();
  return 0;
}
