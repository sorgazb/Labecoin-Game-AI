/*
 * Tablero.h
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "Coordenada.h"
#include "Moneda.h"
#include "vectorMonedas.h"
#include "Fichero.h"
#include "FuncionDistancia.h"
#include "FuncionRentabilidad.h"

const int LIM=13;

class Tablero {

	Fichero *f;
	vectorMonedas *vMoneda;

	FuncionDistancia d;

	FuncionRentabilidad r;

	int monedasObjetivo;
	int fila;
	int columna;
	int tableroJuego [LIM][LIM];

	void cargarTablero();

public:
	Tablero();

	bool estoyMoneda(int i, int j);

	void recogerMoneda(int i, int j);

	void imprimirTablero();

	void buscarRobot(int &i, int &j);
	void buscarSalida(int &i, int &j);

	void moverArriba(int i, int j);
	void moverAbajo(int i, int j);
	void moverDerecha(int  i, int j);
	void moverIzquierda(int i, int j);
	void moverArribaIzquierda(int i, int j);
	void moverArribaDerecha(int i, int j);
	void moverAbajoIzquierda(int i, int j);
	void moverAbajoDerecha(int i, int j);

	bool sePuedeArriba(int i, int j);
	bool sePuedeAbajo(int i, int j);
	bool sePuedeIzquierda(int i, int j);
	bool sePuedeDerecha(int i, int j);
	bool sePuedeArribaDerecha(int i, int j);
	bool sePuedeArribaIzquierda(int i, int j);
	bool sePuedeAbajoDerecha(int i, int j);
	bool sePuedeAbajoIzquierda(int i, int j);

	void buscarMonedaCercana(Coordenada inicio, Moneda *&m);

	void buscarMonedaRentable(Coordenada inicio, Moneda *&m);

	int cuantasMonedas();

	virtual ~Tablero();
};

#endif /* TABLERO_H_ */
