
#include <iostream>
#include <vector>
#include <math.h>

struct Particle{
  std::string name;
  int charge;
  std::vector<double> p;

};

std::vector<double> FillVector(double px, double py, double pz){
 
   std::vector<double> V;
   
   V.push_back(px); 
   V.push_back(py); 
   V.push_back(pz); 

   return V;

}	

double dotproduct(struct Particle p1, struct Particle p2){

  double dotproduct_ = 0.;

  for(int i = 0; i < 2; ++i)
  	dotproduct_ += p1.p[i]*p2.p[i];  

  return dotproduct_;

}

int main(){

	struct Particle Electron;
	Electron.name = "Electron1";
	Electron.charge = -1;
	Electron.p = FillVector(2.,0.56,23.); 

        struct Particle Electron2;
        Electron2.name = "Electron2";
	Electron2.charge = -1;
	Electron2.p = FillVector(1.,53,3.2);	

        std::cout << Electron.name << " "  
		  << Electron.charge  << " " 
		  << Electron.p[0] << " " <<
		  Electron2.p[2]  << std::endl;

        struct Particle muon;
	struct Particle *ptrmuon = &muon;

	ptrmuon->name = "muon";
	
	std::cout << muon.name << std::endl;	


	double d = dotproduct(Electron,Electron2);
        std::cout << d << std::endl;

        int input = 4;
        int *ptr = &input;
       
	std::cout << *ptr << std::endl;	
      
      	*ptr = 569;

	std::cout << &input << std::endl;	


	return 0;
}


