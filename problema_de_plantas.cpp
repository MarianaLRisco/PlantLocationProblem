#include <bits/stdc++.h> 
#include<conio.h>
#include "ubicacionplanta.h"
#define sq(x) ((x)*(x)) 
#define EPS 1e-6 


using namespace std; 

int N;
long s=0;
 
struct punto 
{ 
    int x, y; 
    punto()  {} 
    punto(int x, int y) : x(x), y(y)   {} 
}; 
  

struct linea 
{ 
    int a, b, c; 
    linea(int a, int b, int c) : a(a), b(b), c(c) {} 
}; 
  
  
int obtener_N (){
    	
	cout<<"Cuantas fabricas desea registar: ";cin>>N;
	return N;
}


double distancia(double x, double y, punto p) 
{ 
    return sqrt(sq(x - p.x) + sq(y - p.y)); 
} 
  

double compute(punto p[], int n, linea l, double X) 
{ 
    double res = 0; 
  
   
    double Y = -1 * (l.c + l.a*X) / l.b; 
    for (int i = 0; i < n; i++) 
        res += distancia(X, Y, p[i]); 
  
    return res; 
} 
  

double optim_costo(punto p[], int n, linea l) 
{ 
    double bajo = -1e6; 
    double alto = 1e6; 
      
   
    while ((alto - bajo) > EPS) 
    { 
       
        double mid1 = bajo + (alto - bajo) / 3; 
        double mid2 = alto - (alto - bajo) / 3; 
  
        double dist1 = compute(p, n, l, mid1); 
        double dist2 = compute(p, n, l, mid2); 
  
        if (dist1 < dist2) 
            alto = mid2; 
        else
            bajo = mid1; 
        s++;
    } 
  
    return compute(p, n, l, (bajo + alto) / 2); 
} 
  

double ubicacion_optima(int puntos[][2], linea l) 
{ 
    punto p[N]; 
  
    for (int i = 0; i < N; i++) 
        p[i] = punto(puntos[i][0], puntos[i][1]); 
  
    return optim_costo(p, N, l); 
} 
  
//  Programa Principal
int main() 
{ 
    double  primercoef, segundocoef, tercercoef;
   
    titulo();

    cout<<endl<<"*********************************************"<<endl;
    
    cout<<"Ingrese los coeficientes para la recta donde se ubicara el almacen "<<endl;
    
    cout<<"Primer coeficiente: ";cin>>primercoef;
    cout<<"Segundo coeficiente: ";cin>>segundocoef;
    cout<<"Tercer coeficiente: ";cin>>tercercoef; 
   
    N= obtener_N();
    
    cout<<"*********************************************"<<endl;
    
		    
    linea l( primercoef, segundocoef, tercercoef ); 
    
    cout<<"La ecuacion de la recta es: "<<primercoef<<"x+"<<segundocoef<<"y+"<<tercercoef<<endl<<endl;
    getch();
    
    int puntos[N][2]; 
    
    cout<<"Ingrese coordenadas de la fabrica ~"<<endl;
    
    for(int i=0; i<N; i++){
    	
    	cout<<"Punto Fabrica Nro "<<i+1<<": "<<endl;
    	  		
		cout<<"\tCoordenada X: ";cin>>puntos[i][0];
		cout<<"\tCoordenada Y: ";cin>>puntos[i][1];
		   	
	}
	
    cout << ubicacion_optima(puntos, l) << endl; 
    
    return 0; 
} 
