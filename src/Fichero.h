/*
 * Fichero.h
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#ifndef FICHERO_H_
#define FICHERO_H_
#include <iostream>
#include <string>
using namespace std;

class Fichero {
public:
	Fichero();

	int menu();

	void seleccionarTablero(string &nombreLaberinto);

	virtual ~Fichero();
};

#endif /* FICHERO_H_ */
