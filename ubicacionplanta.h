#include<iostream>
#include<windows.h>
#include<fstream>

using namespace std;

void titulo(){  
      fstream planta;
	  planta.open("ubicacionplanta.txt");
	  string guardar;
	  while (getline(planta,guardar))
   	{ cout<<"\t\t"<<guardar<<endl;	}
    	planta.close();
 }  
 
 float redondeo(float N) {
 	
 	N=N*4.68;

 	return N;
 	
 }

