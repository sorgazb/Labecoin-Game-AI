/*
 * FuncionRentabilidad.cpp
 *
 *  Created on: 17 abr. 2023
 *      Author: alumno
 */

#include "FuncionRentabilidad.h"

FuncionRentabilidad::FuncionRentabilidad() {
	// TODO Auto-generated constructor stub

}

double FuncionRentabilidad::funcionRentabilidad(Coordenada inicio,
		Coordenada destino, Moneda *&cercana) {
	double distancia= d.compararDistancia(inicio, destino);
	return ((10 - cercana->getValor()) * (distancia + 1));
}

FuncionRentabilidad::~FuncionRentabilidad() {
	// TODO Auto-generated destructor stub
}

