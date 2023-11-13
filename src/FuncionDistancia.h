/*
 * FuncionDistancia.h
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#ifndef FUNCIONDISTANCIA_H_
#define FUNCIONDISTANCIA_H_
#include "Coordenada.h"

#include <iostream>
using namespace std;
#include <cmath>

class FuncionDistancia {
public:
	FuncionDistancia();

	double compararDistancia(Coordenada c1, Coordenada c2);

	virtual ~FuncionDistancia();
};

#endif /* FUNCIONDISTANCIA_H_ */
