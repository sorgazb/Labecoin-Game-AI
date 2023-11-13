/*
 * MaximaPendiente.h
 *
 *  Created on: 17 abr. 2023
 *      Author: alumno
 */

#ifndef MAXIMAPENDIENTE_H_
#define MAXIMAPENDIENTE_H_
#include <ctime>
#include "Tablero.h"
#include "FuncionRentabilidad.h"

class MaximaPendiente {
	Tablero *t;
	FuncionDistancia d;
	FuncionRentabilidad r;
	Coordenada casillaOcupada[100];
	int ocupacion;

public:
	MaximaPendiente();

	void maximaPendiente();

	void avanzar2(Coordenada inicio, Coordenada destino, int &avanzar, int &nodos);

	void insertarCasilla(Coordenada &c);

	bool estaVisitada(Coordenada c);

	virtual ~MaximaPendiente();
};

#endif /* MAXIMAPENDIENTE_H_ */
