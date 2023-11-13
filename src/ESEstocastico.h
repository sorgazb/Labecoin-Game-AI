/*
 * ESEstocastico.h
 *
 *  Created on: 18 abr. 2023
 *      Author: alumno
 */

#ifndef ESESTOCASTICO_H_
#define ESESTOCASTICO_H_
#include <ctime>
#include "Tablero.h"
#include "FuncionDistancia.h"
class ESEstocastico {
	Tablero *t;
	FuncionDistancia d;
	Coordenada casillaOcup[100];
	int ocupacion;
	int valor;
public:
	ESEstocastico();

	void escaladaSimpleEsto();

	void avanzar(Coordenada inicio, Coordenada destino,int &avanzar, int mejora, int &nodos);

	bool esMenorDistancia(Coordenada incio, Coordenada next, Coordenada destino);

	void insertarCasilla(Coordenada &c);

	bool estaVisitada(Coordenada c);

	void obtenerMejora(int &valor);

	bool estocastico(Coordenada c, Coordenada next, int valor, Coordenada destino);

	//bool casa();


	virtual ~ESEstocastico();
};

#endif /* ESESTOCASTICO_H_ */
