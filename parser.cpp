#include<iostream>
#include"parser.h"
#include"novela.h"

using namespace std;

const int no_sabo = -1;

Parser :: Parser(){
	this->entrada = entrada;
}

Parser :: ~Parser(){

}
/*
Parser :: procesar_escritor(string ruta, Lista<Escritor*> &lista){

	Esctritor *autor;
	string lectura;

	entrada.abrir_archivo(ruta);
	   
	while (!entrada.final_archivo()){

		lectura = entrada.leer_linea();

	    if(!lectura.empty()){

	    	autor = new Esctritor;

	        lectura = entrada.leer_linea();
	        autor->establecer_nombre(lectura);

	        lectura = entrada.leer_linea();
	        autor->establecer_nacionalidad(lectura);

	        lectura = entrada.leer_linea();

	        if(!lectura.empty()){
	        	autor->establecer_nacimiento(atoi(lectura.c_str()));

		        lectura = entrada.leer_linea();

				if(!lectura.empty()){
	        		autor->establecer_fallecimiento(atoi(lectura.c_str()));
				}
	        }
	        else{
	        	autor->establecer_nacimiento(no_sabo);

	        	lectura = entrada.leer_linea();

				if(!lectura.empty()){
	        		autor->establecer_fallecimiento(no_sabo);
				}
	        }
	    } 

    }
    entrada.cerrar_archivo(); // esto o destructor	
}
*/
Parser :: procesar_escritor(string ruta, Lista<Escritor*> &lista){

	string nombre, nacionalidad, codigo, lectura;
	int nacimiento, fallecimiento;

	entrada.abrir_archivo(ruta);
	   
	while (!entrada.final_archivo()){

	    lectura = entrada.leer_linea();

	    if(!lectura.empty()){

	        nombre = entrada.leer_linea();

	        nacionalidad = entrada.leer_linea();

	        lectura = entrada.leer_linea();

	        if(!lectura.empty()){
		        nacimiento = atoi(lectura.c_str());

		        lectura = entrada.leer_linea();

				if(!lectura.empty()){
	        		fallecimiento = atoi(lectura.c_str());
				}
	        }
	        else{
	        	nacimiento = no_sabo;

	        	lectura = entrada.leer_linea();

				if(!lectura.empty()){
	        		fallecimiento = no_sabo;
				}
	        }

	        Esctritor *autor(nombre, nacionalidad, nacimiento, fallecimiento);
	    } 

    }
    entrada.cerrar_archivo(); // esto o destructor	
}

/*
Parser :: procesar_lectura(string ruta, Lista<Lectura*> &lista){

	Lectura *lectura;
	string dato, tipo;

	entrada.abrir_archivo(ruta);
	   
	while (!entrada.final_archivo()){

		dato = entrada.leer_linea();

	    if(!dato.empty()){

	    	tipo = dato;

	    	lectura = new Lectura;

	        dato = entrada.leer_linea();
	        lectura->establecer_titulo(dato);

	        dato = entrada.leer_linea();
	        lectura->establecer_minutos(atoi(dato.c_str()));

	        dato = entrada.leer_linea();
	        lectura->establecer_anio(atoi(dato.c_str()));

	        if(tipo == "P")
	        	lectura->establecer_versos(atoi(dato.c_str()));

	        dato = entrada.leer_linea();
	       
	        if(dato == "ANONIMO")
	        	Escritor = nullptr;

	    } 

    }
    entrada.cerrar_archivo(); // esto o destructor	
}
*/
Parser :: procesar_lectura(string ruta, Lista<Lectura*> &lista_lectura){

	string dato, titulo, genero, tipo;
	int minutos, anio, versos;

	entrada.abrir_archivo(ruta);
	   
	while (!entrada.final_archivo()){

	    dato = entrada.leer_linea();

	    if(!dato.empty()){

	        titulo = entrada.leer_linea();

	        dato = entrada.leer_linea();
	        minutos = atoi(dato.c_str());

	        dato = entrada.leer_linea();
	        anio = atoi(dato.c_str());

		    dato = entrada.leer_linea();

	        if(tipo == "P"){
		        versos = atoi(dato.c_str());
		        //cargar lista de autor(dato,lista_lectura)
		        //Poema(string titulo, Escritor *autor, int anio, int minutos, int versos);
		    }

	        if(tipo == "N"){
		        genero = entrada.leer_linea();
		       	dato = entrada.leer_linea();

		         //cargar lista de autor(dato,lista_lectura)
		        /*
		       	if genero == historica
		        	Novela_historica *his(tema);
		        else 
		        	Novela *nov(genero);

	        	*/
		    }

		    else
	        	Lectura *autor(titulo, minutos, anio/*, Escritor char* */);

	    } 

    }
    entrada.cerrar_archivo(); // esto o destructor	
}