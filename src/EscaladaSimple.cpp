/*
 * EscaladaSimple.cpp
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#include "EscaladaSimple.h"

EscaladaSimple::EscaladaSimple() {
	t= new Tablero();
	this->ocupacion=0;
	t->imprimirTablero();
}



void EscaladaSimple::escaladaSimple() {
	int nodos=0;
	unsigned t0, t1;
	t0=clock();
	int valor=1;
	Coordenada Robot;
	int iRobot;
	int jRobot;
	t->buscarRobot(iRobot, jRobot);
	Robot.setI(iRobot);
	Robot.setJ(jRobot);
	Coordenada Salida;
	Coordenada SalidaAux;
	int iSalida=100;
	int jSalida=100;
	t->buscarSalida(iSalida, jSalida);
	Salida.setI(iSalida);
	Salida.setJ(jSalida);
	SalidaAux=Salida;
	bool fin=false;
	while(fin==false){
		if(Salida.getI()>10){
			if(Salida.getJ()>10){
				cout<<"No hay salida"<<endl;
				fin=true;
			}
		}
		else{
			if(valor!=0){
				t->buscarRobot(iRobot, jRobot);
				if(t->cuantasMonedas()!=0){
					Moneda *cercana;
					t->buscarMonedaCercana(Robot, cercana);
					avanzar(Robot, cercana->getC(),valor,nodos);
				}
				else{
					if(t->cuantasMonedas()==0){
						avanzar(Robot, Salida,valor, nodos);
					}
				}
			}
			else{
				if(iRobot == SalidaAux.getI() && jRobot == SalidaAux.getJ()){
					cout<<"Has resuelto el laberinto."<<endl;
					cout<<endl;
					fin=true;
				}
				else{
					cout<<"Fin, el laberinto no se ha podido resolver."<<endl;
					cout<<endl;
					fin=true;
				}
			}
		}
	}
	t1=clock();
	double tiempo= (double(t1-t0)/CLOCKS_PER_SEC);
	cout<<"- La búsqueda ha durado: "<<tiempo<<endl;
	cout<<"- El numero de nodos generados ha sido: "<<nodos<<endl;
	cout<<"- El laberinto ha quedado asi: "<<endl;
	cout<<endl;
	t->imprimirTablero();
}

void EscaladaSimple::avanzar(Coordenada inicio, Coordenada destino, int &avanzar,int &nodos) {
	cout<<endl;
	bool mov=false;
	int i;
	int j;
	t->buscarRobot(i, j);
	inicio.setI(i);
	inicio.setJ(j);
	while(!mov){
		Coordenada auxAr;
		auxAr.setI(inicio.getI()-1);
		auxAr.setJ(inicio.getJ());
		nodos=nodos+1;
		if(t->sePuedeArriba(i, j)==true && esMenorDistancia(inicio, auxAr, destino)==true && estaVisitada(auxAr)==false){
			t->moverArriba(i, j);
			insertarCasilla(auxAr);
			cout<<"Movimineto realizado: AR"<<endl;
			mov=true;
			avanzar=1;
		}
		else{
			nodos=nodos+1;
			Coordenada auxAb;
			auxAb.setI(inicio.getI()+1);
			auxAb.setJ(inicio.getJ());
			if(t->sePuedeAbajo(i, j)==true && esMenorDistancia(inicio, auxAb, destino)==true && estaVisitada(auxAb)==false){
				t->moverAbajo(i, j);
				insertarCasilla(auxAb);
				cout<<"Movimiento realizado: AB"<<endl;
				mov=true;
				avanzar=1;
			}
			else{
				nodos=nodos+1;
				Coordenada auxD;
				auxD.setI(inicio.getI());
				auxD.setJ(inicio.getJ()+1);
				if(t->sePuedeDerecha(i, j)== true && esMenorDistancia(inicio, auxD, destino)==true && estaVisitada(auxD)==false){
					t->moverDerecha(i, j);
					insertarCasilla(auxD);
					cout<<"Movimiento realizado: D"<<endl;
					mov=true;
					avanzar=1;
				}
				else{
					nodos=nodos+1;
					Coordenada auxI;
					auxI.setI(inicio.getI());
					auxI.setJ(inicio.getJ()-1);
					if(t->sePuedeIzquierda(i, j)==true && esMenorDistancia(inicio, auxI, destino)==true && estaVisitada(auxI)==false){
						t->moverIzquierda(i, j);
						insertarCasilla(auxI);
						cout<<"Movimiento realizado: I"<<endl;
						mov=true;
						avanzar=1;
					}
					else{
						nodos=nodos+1;
						Coordenada auxARD;
						auxARD.setI(inicio.getI()-1);
						auxARD.setJ(inicio.getJ()+1);
						if(t->sePuedeArribaDerecha(i, j)==true && esMenorDistancia(inicio, auxARD, destino)==true && estaVisitada(auxARD)==false){
							t->moverArribaDerecha(i, j);
							insertarCasilla(auxARD);
							cout<<"Movimiento realizado: AR-D"<<endl;
							mov=true;
							avanzar=1;
						}
						else{
							nodos=nodos+1;
							Coordenada auxARI;
							auxARI.setI(inicio.getI()-1);
							auxARI.setJ(inicio.getJ()-1);
							if(t->sePuedeArribaIzquierda(i, j)==true && esMenorDistancia(inicio, auxARI, destino)==true && estaVisitada(auxARI)==false){
								t->moverArribaIzquierda(i, j);
								insertarCasilla(auxARI);
								cout<<"Movimiento realizado: AR-I"<<endl;
								mov=true;
								avanzar=1;
							}
							else{
								nodos=nodos+1;
								Coordenada auxABD;
								auxABD.setI(inicio.getI()+1);
								auxABD.setJ(inicio.getJ()+1);
								if(t->sePuedeAbajoDerecha(i, j)==true && esMenorDistancia(inicio, auxABD, destino)==true && estaVisitada(auxABD)){
									t->moverAbajoDerecha(i, j);
									insertarCasilla(auxABD);
									cout<<"Movimiento realizado: AB-D"<<endl;
									mov=true;
									avanzar=1;
								}
								else{
									nodos=nodos+1;
									Coordenada auxABI;
									auxABI.setI(inicio.getI()+1);
									auxABI.setJ(inicio.getJ()-1);
									if(t->sePuedeAbajoIzquierda(i, j)==true && esMenorDistancia(inicio, auxABI, destino)==true && estaVisitada(auxABI)==false){
										t->moverArribaIzquierda(i, j);
										insertarCasilla(auxABI);
										cout<<"Movimiento realizado: AB-I"<<endl;
										mov=true;
										avanzar=1;
									}
									else{
										cout<<"No se ha podido avanzar a otra posicion"<<endl;
										mov=true;
										avanzar=0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

bool EscaladaSimple::esMenorDistancia(Coordenada incio, Coordenada next, Coordenada destino) {
	bool esMenor=false;
	double distancia1;
	distancia1= d.compararDistancia(incio, destino);
	double distancia2;
	distancia2=d.compararDistancia(next, destino);
	if(distancia2 < distancia1){
		esMenor=true;
	}
	return esMenor;
}

void EscaladaSimple::insertarCasilla(Coordenada &c) {
	if(ocupacion<100){
		casillaOcup[ocupacion]=c;
		ocupacion++;
	}
}

bool EscaladaSimple::estaVisitada(Coordenada c) {
	bool visitada=false;
	int pos;
		for(pos=0; pos<ocupacion; pos++){
			if(casillaOcup[pos].getI() == c.getI() ){
				if(casillaOcup[pos].getJ() == c.getJ()){
					visitada=true;
				}
			}
		}
	return visitada;
}

EscaladaSimple::~EscaladaSimple() {
	delete t;
}

