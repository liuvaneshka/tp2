#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include "archivo.h"

using namespace std;

	int main (){

		string archivo_lecturas = "Lecturas.txt"; 
		string archivo_autores = "Autores.txt";

		Archivo ar_lec(archivo_lecturas), ar_au(archivo_autores);
		//ar_lec.parserdatos();

		cout << "**************Lecturas: " <<  endl;

	    while (!ar_lec.final_archivo()){

	        string lectura = ar_lec.leer_linea();

	        if(!lectura.empty()){
	            cout << lectura << endl;
	            //lectura = new lectura(parametros)
	            //lista.agregar(dato)  
	        } 
	        else
	            cout << " ------------otro objeto: " << endl;
    	}	

 		cout << "***************Autores: " <<  endl;

    	while (!ar_au.final_archivo()){

	        string lectura = ar_au.leer_linea();

	        if(!lectura.empty()){
	            cout << lectura << endl;
	            //lectura = new lectura(parametros)
	            //lista.agregar(dato)  
	        } 
	        else
	            cout << " ------------otro objeto: " << endl;

    	}

	return 0;
}
