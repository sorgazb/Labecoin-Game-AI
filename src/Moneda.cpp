/*
 * Moneda.cpp
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#include "Moneda.h"

Moneda::Moneda() {
	this->valor=0;
}

Moneda::Moneda(int valor,Coordenada c) {
	this->valor=valor;
	this->c=c;
}


int Moneda::getValor() const {
	return valor;
}

void Moneda::setValor(int valor) {
	this->valor = valor;
}

const Coordenada& Moneda::getC() const {
	return c;
}

void Moneda::setC(const Coordenada &c) {
	this->c = c;
}

Moneda::~Moneda() {
	// TODO Auto-generated destructor stub
}

