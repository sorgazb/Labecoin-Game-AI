/*
 * FuncionRentabilidad.h
 *
 *  Created on: 17 abr. 2023
 *      Author: alumno
 */

#ifndef FUNCIONRENTABILIDAD_H_
#define FUNCIONRENTABILIDAD_H_
#include "Coordenada.h"
#include "Moneda.h"
#include "FuncionDistancia.h"

class FuncionRentabilidad {
	FuncionDistancia d;
public:
	FuncionRentabilidad();

	double funcionRentabilidad(Coordenada inicio, Coordenada destino, Moneda *&cercana);

	virtual ~FuncionRentabilidad();
};

#endif /* FUNCIONRENTABILIDAD_H_ */
