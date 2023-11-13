//============================================================================
// Name        : IASI.cpp
// Author      : sergio orgaz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
using namespace std;

#include "EscaladaSimple.h"
#include "MaximaPendiente.h"
#include "ESEstocastico.h"

int menuAlgoritmo(){
	cout<<"Menú Seleccion Algoritmo"<<endl;
	int opcion;
	do{
		cout<<"1-Escalada Simple (Moneda Cercana)"<<endl;
		cout<<"2-Maxima Pendiente (Mejor Moneda Cercana)"<<endl;
		cout<<"3-Escalada Simple  Estocastico (Moneda Cercana)"<<endl;
		cout<<"Opcion: "<<endl;
		cin>>opcion;
		cin.ignore();
	}while((opcion < 0) || (opcion > 4));
	return opcion;
}


void seleccionarAlgoritmo(){
	int opcion;
	opcion=menuAlgoritmo();
	switch(opcion){
	case 1:
		cout<<"Has seleccionado ESCALADA SIMPLE: "<<endl;
		EscaladaSimple *e;
		e= new EscaladaSimple();
		e->escaladaSimple();
		break;
	case 2:
		cout<<"Has seleccionado MAXIMA PENDIENTE: "<<endl;
		MaximaPendiente *m;
		m= new MaximaPendiente();
		m->maximaPendiente();
		break;
	case 3:
		cout<<"Has seleccionado ESCALADA SIMPLE ESTOCASTICO: "<<endl;
		ESEstocastico *j;
		j= new ESEstocastico();
		j->escaladaSimpleEsto();
		break;
	default :
		break;
	}
}


int main() {
	seleccionarAlgoritmo();
	return 0;
}
