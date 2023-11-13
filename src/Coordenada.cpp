/*
 * Coordenada.cpp
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#include "Coordenada.h"

Coordenada::Coordenada() {
	this->i=0;
	this->j=0;
}

Coordenada::Coordenada(int i, int j) {
	this->i=i;
	this->j=j;
}

int Coordenada::getI() const {
	return i;
}

void Coordenada::setI(int i) {
	this->i = i;
}

int Coordenada::getJ() const {
	return j;
}

void Coordenada::setJ(int j) {
	this->j = j;
}

Coordenada::~Coordenada() {
	// TODO Auto-generated destructor stub
}

