/*
 * Tablero.cpp
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "Tablero.h"

void Tablero::cargarTablero() {
	Coordenada c;
	Moneda *m;
	string nombreLaberinto;
	f->seleccionarTablero(nombreLaberinto);
	string objetivo;
	string valor;
	int eObjetivo;
	int eValor;
	ifstream flujoTablero;
	//cuidao
	flujoTablero.open("LABECOIN11.txt");
	if(flujoTablero.is_open()){
		getline(flujoTablero,objetivo);
		eObjetivo = stoi(objetivo);
		this->monedasObjetivo=eObjetivo;
		while(!flujoTablero.eof()){
			getline(flujoTablero,valor,',');
			eValor=stoi(valor);
			for(int i=0; i<fila; i++){
				for(int j=0; j<columna; j++){
					if(eValor>0 && eValor<7){
						c.setI(i);
						c.setJ(j);
						m= new Moneda(eValor,c);
						vMoneda->insertarMoneda(m);
					}
					tableroJuego[i][j]=eValor;
					getline(flujoTablero,valor,',');
					//Comprobacion linea vacia
					if(!flujoTablero.eof()){
						eValor=stoi(valor);
					}
				}
			}
		}
		flujoTablero.close();
	}
}


Tablero::Tablero() {
	this->fila=LIM;
	this->columna=LIM;
	this->monedasObjetivo=0;
	this->vMoneda= new vectorMonedas();
	this->f= new Fichero();
	cargarTablero();
}

bool Tablero::estoyMoneda(int i, int j) {
	bool estoy=false;
	if(tableroJuego[i][j]>0){
		if(tableroJuego[i][j]<8){
			estoy=true;
			//recogerMoneda
		}
	}
	return estoy;
}

void Tablero::imprimirTablero() {
	cout<<"Monedas Objetivo: "<<this->monedasObjetivo<<endl;
	for(int i=0; i< LIM; i++){
		cout<<endl;
		for(int j=0; j< LIM; j++){
			cout<<" ["<<tableroJuego[i][j]<<"] ";
		}
		cout<<endl;
	}
}

void Tablero::buscarRobot(int &i, int &j) {
	bool enc=false;
	while(enc==false){
		for(int pi=0; pi<this->fila;pi++){
			for(int pj=0; pj<this->columna;pj++){
				if(tableroJuego[pi][pj]==8){
					enc=true;
					i=pi;
					j=pj;
				}
			}
		}
	}
}

void Tablero::buscarSalida(int &i, int &j) {
	bool enc=false;
	while(enc==false){
		for(int pi=0; pi<this->fila; pi++){
			for(int pj=0; pj<this->columna;pj++){
				if(tableroJuego[pi][pj]==7){
					enc=true;
					i=pi;
					j=pj;
				}
			}
		}
		if(enc==false){
			i=11;
			j=11;
			enc=true;
		}
	}

}

void Tablero::moverArriba(int i, int j) {
	if(sePuedeArriba(i, j)==true){
		int robot=tableroJuego[i][j];
		if(estoyMoneda(i-1, j)==true){
			recogerMoneda(i-1, j);
			tableroJuego[i][j]=0;
			tableroJuego[i-1][j]=robot;
		}
		else{
			tableroJuego[i][j]=0;
			tableroJuego[i-1][j]=robot;
		}
	}
}

void Tablero::moverAbajo(int i, int j) {
	if(sePuedeAbajo(i, j)==true){
		int robot=tableroJuego[i][j];
		if(estoyMoneda(i+1, j)==true){
			recogerMoneda(i+1, j);
			tableroJuego[i][j]=0;
			tableroJuego[i+1][j]=robot;
		}
		else{
			tableroJuego[i][j]=0;
			tableroJuego[i+1][j]=robot;
		}
	}
}

void Tablero::moverDerecha(int i, int j) {
	if(sePuedeDerecha(i, j)==true){
		int robot=tableroJuego[i][j];
		if(estoyMoneda(i, j+1)==true){
			recogerMoneda(i, j+1);
			tableroJuego[i][j]=0;
			tableroJuego[i][j+1]=robot;
		}
		else{
			tableroJuego[i][j]=0;
			tableroJuego[i][j+1]=robot;
		}
	}
}

void Tablero::moverIzquierda(int i, int j) {
	if(sePuedeIzquierda(i, j)==true){
		int robot=tableroJuego[i][j];
		if(estoyMoneda(i, j-1)==true){
			recogerMoneda(i, j-1);
			tableroJuego[i][j]=0;
			tableroJuego[i][j-1]=robot;
		}
		else{
			tableroJuego[i][j]=0;
			tableroJuego[i][j-1]=robot;
		}
	}
}

bool Tablero::sePuedeArriba(int i, int j) {
	bool puede=true;
	if(tableroJuego[i-1][j]==9){
		puede=false;
	}
	return puede;
}

bool Tablero::sePuedeAbajo(int i, int j) {
	bool puede=true;
	if(tableroJuego[i+1][j]==9){
		puede=false;
	}
	return puede;
}

bool Tablero::sePuedeIzquierda(int i, int j) {
	bool puede=true;
	if(tableroJuego[i][j-1]==9){
		puede=false;
	}
	return puede;
}

bool Tablero::sePuedeDerecha(int i, int j) {
	bool puede=true;
	if(tableroJuego[i][j+1]==9){
		puede=false;
	}
	return puede;
}

int Tablero::cuantasMonedas() {
	return this->monedasObjetivo;
}

Tablero::~Tablero() {
	delete this->vMoneda;
	delete this->f;
}

void Tablero::recogerMoneda(int i, int j) {
	int cuantos=0;
	Moneda *maux;
	Coordenada aux;
	aux.setI(i);
	aux.setJ(j);
	int pos=0;
	int vpos=0;
	bool enc=false;
	while(pos < vMoneda->cuantos() && vpos < vMoneda->cuantos() && !enc){
		vMoneda->obtener(pos, maux);
		if(maux->getC().getI() == aux.getI()){
			if(maux->getC().getJ() == aux.getJ()){
				cuantos=maux->getValor();
				this->monedasObjetivo= this->monedasObjetivo - cuantos;
				vMoneda->eliminar(aux);
				enc=true;
				if(monedasObjetivo<0){
					monedasObjetivo=0;
				}
			}
			else{
				pos++;
			}
		}
		else{
			pos++;
		}
	}

}

void Tablero::buscarMonedaCercana(Coordenada inicio, Moneda *&m) {
	Moneda *aux;
	double distancia1;
	double distancia2;
	double distanciamejor;
	int pos=0;
	vMoneda->obtener(pos, m);
	distancia1= d.compararDistancia(inicio, m->getC());
	distanciamejor=distancia1;
	while(pos < this->vMoneda->cuantos()){
		vMoneda->obtener(pos, aux);
		distancia2=d.compararDistancia(inicio, aux->getC());
		if(distancia2 < distanciamejor){
			m=aux;
			distanciamejor=distancia2;
		}
		pos++;
	}
}

void Tablero::buscarMonedaRentable(Coordenada inicio, Moneda *&m) {
	Moneda *aux;
	double distancia1;
	double distancia2;
	double distanciaMejor;
	int pos=0;
	vMoneda->obtener(pos, m);
	distancia1=r.funcionRentabilidad(inicio, m->getC(), m);
	distanciaMejor=distancia1;
	while(pos<this->vMoneda->cuantos()){
		vMoneda->obtener(pos, aux);
		distancia2=r.funcionRentabilidad(inicio, aux->getC(), aux);
		if(distancia2 < distanciaMejor){
			m=aux;
			distanciaMejor=distancia2;
		}
		pos++;
	}
}
