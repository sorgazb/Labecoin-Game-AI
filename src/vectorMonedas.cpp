/*
 * vectorMonedas.cpp
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#include "vectorMonedas.h"

vectorMonedas::vectorMonedas() {
	this->ocupacion=0;
}

void vectorMonedas::insertarMoneda(Moneda *&m) {
	if(ocupacion<MAX){
		vMoneda[ocupacion]=m;
		ocupacion++;
	}
}

void vectorMonedas::obtener(int pos, Moneda *&m) {
	m=vMoneda[pos];
}

int vectorMonedas::cuantos() {
	return ocupacion;
}

void vectorMonedas::eliminar(Coordenada c) {
	int i=0;
	int posicion;
	bool enc=false;
	Moneda *m= nullptr;
	while(i<this->ocupacion && !enc){
		m=vMoneda[i];
		if(m->getC().getI()==c.getI()){
			if(m->getC().getJ() == c.getJ()){
				enc=true;
				delete m;
			}
			else{
				i++;
			}
		}
		else{
			i++;
		}
	}
	for(posicion=i; posicion < this->ocupacion+1; posicion ++){
		vMoneda[posicion]=vMoneda[posicion+1];
	}
	this->ocupacion--;
}

vectorMonedas::~vectorMonedas() {
	delete vMoneda;
}

