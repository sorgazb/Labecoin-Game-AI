/*
 * FuncionDistancia.cpp
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#include "FuncionDistancia.h"

FuncionDistancia::FuncionDistancia() {
	// TODO Auto-generated constructor stub

}

double FuncionDistancia::compararDistancia(Coordenada c1, Coordenada c2) {
	int x1=c1.getI();
	int x2=c2.getI();
	int y1=c1.getJ();
	int y2=c2.getJ();


	return sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));
}

FuncionDistancia::~FuncionDistancia() {
	// TODO Auto-generated destructor stub
}

