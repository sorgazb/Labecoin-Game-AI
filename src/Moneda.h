/*
 * Moneda.h
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#ifndef MONEDA_H_
#define MONEDA_H_
#include "Coordenada.h"

class Moneda {
	int valor;
	Coordenada c;
public:
	Moneda();
	Moneda(int valor,Coordenada c);

	int getValor() const;
	void setValor(int valor);

	const Coordenada& getC() const;
	void setC(const Coordenada &c);

	virtual ~Moneda();

};

#endif /* MONEDA_H_ */
