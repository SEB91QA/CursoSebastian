// paso por referencia a una funcion
void CambiarA(int &a){

  cout << " local memory " << &a << endl; 	
  a = 10;
  cout << " a local: " << a << endl; 

}

void FillHisto( TH1D h1, int Nentries){

	for(int i = 0; i < 100; i++){
	h1.Fill(3);
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
   FillHisto(*h1, Nentries);
   cout << " Global " << Nentries << endl;

   CambiarEjeX(h1);

  h1->Draw(); 

    TH1D *h2 ;
	    //= new TH1D("h1","h2", 50, 0.,50.);;
    cout  << " histograma h2 en memoria global "  << h2 << endl;
    h2->Fill(2);

   // delete h1; 
}  

int main(){
  funciones();
  return 0;
}
