/*
 * EscaladaSimple.h
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#ifndef ESCALADASIMPLE_H_
#define ESCALADASIMPLE_H_
#include <ctime>
#include "Tablero.h"
#include "FuncionDistancia.h"

class EscaladaSimple {
	Tablero *t;
	FuncionDistancia d;
	Coordenada casillaOcup[100];
	int ocupacion;

public:
	EscaladaSimple();


	void escaladaSimple();

	void avanzar(Coordenada inicio, Coordenada destino,int &avanzar, int &nodos);

	bool esMenorDistancia(Coordenada incio, Coordenada next, Coordenada destino);

	void insertarCasilla(Coordenada &c);

	bool estaVisitada(Coordenada c);


	virtual ~EscaladaSimple();
};

#endif /* ESCALADASIMPLE_H_ */
