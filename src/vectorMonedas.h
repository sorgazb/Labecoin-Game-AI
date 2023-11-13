/*
 * vectorMonedas.h
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#ifndef VECTORMONEDAS_H_
#define VECTORMONEDAS_H_
#include <iostream>
using namespace std;

#include "Moneda.h"

const int MAX=100;

class vectorMonedas {
	Moneda* vMoneda[MAX];
	int ocupacion;
public:
	vectorMonedas();

	void insertarMoneda(Moneda *&m);

	void obtener(int pos, Moneda *&m);

	int cuantos();

	void eliminar(Coordenada c);

	virtual ~vectorMonedas();
};

#endif /* VECTORMONEDAS_H_ */
