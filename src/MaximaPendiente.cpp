/*
 * MaximaPendiente.cpp
 *
 *  Created on: 17 abr. 2023
 *      Author: alumno
 */

#include "MaximaPendiente.h"

MaximaPendiente::MaximaPendiente() {
	t= new Tablero();
	this->ocupacion=0;
	t->imprimirTablero();
}

void MaximaPendiente::maximaPendiente() {
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
		if(Salida.getI()>LIM){
			if(Salida.getJ()>LIM){
				cout<<"No hay salida"<<endl;
				fin=true;
			}
		}
		else{
			if(valor!=0){
				//PROBABLEMENTE BÚSQUEDA INNECESARIA DEBIDO A QUE SE REPITE EN IF Y ELSE
				t->buscarRobot(iRobot, jRobot);
				if(t->cuantasMonedas()!=0){
					Moneda *cercana;
					t->buscarRobot(iRobot, jRobot);
					Robot.setI(iRobot);
					Robot.setJ(jRobot);
					t->buscarMonedaRentable(Robot, cercana);
					avanzar2(Robot, cercana->getC(), valor,nodos);
				}
				else{
					if(t->cuantasMonedas()==0){
						t->buscarRobot(iRobot, jRobot);
						Robot.setI(iRobot);
						Robot.setJ(jRobot);
						avanzar2(Robot, Salida, valor,nodos);
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
					cout<<endl,
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




void MaximaPendiente::insertarCasilla(Coordenada &c) {
	if(ocupacion < 100){
		casillaOcupada[ocupacion]=c;
		ocupacion++;
	}
}

bool MaximaPendiente::estaVisitada(Coordenada c) {
	bool visitada=false;
	int pos;
		for(pos=0; pos<ocupacion; pos++){
			if(casillaOcupada[pos].getI() == c.getI() ){
				if(casillaOcupada[pos].getJ() == c.getJ()){
					visitada=true;
				}
			}
		}
	return visitada;
}

void MaximaPendiente::avanzar2(Coordenada inicio, Coordenada destino,int &avanzar, int &nodos) {
	cout<<endl;
	double distanciaInicio=d.compararDistancia(inicio, destino);
	avanzar=0;
	bool mov=false;

	int i;
	int j;
	double distanciaMejor=1000000;
	double distancia1=1000000;
	double distancia2=1000000;
	double distancia3=1000000;
	double distancia4=1000000;
	t->buscarRobot(i, j);
	inicio.setI(i);
	inicio.setJ(j);
	while(!mov){
		Coordenada auxAr;
		auxAr.setI(inicio.getI()-1);
		auxAr.setJ(inicio.getJ());
		if(t->sePuedeArriba(i, j)==true && estaVisitada(auxAr)==false){
			nodos=nodos+1;
			distancia1=d.compararDistancia(auxAr, destino);
			distanciaMejor=distancia1;
		}
		Coordenada auxAb;
		auxAb.setI(inicio.getI()+1);
		auxAb.setJ(inicio.getJ());
		if(t->sePuedeAbajo(i, j)==true && estaVisitada(auxAb)==false){
			nodos=nodos+1;
			distancia2=d.compararDistancia(auxAb, destino);
			if(distanciaMejor!=1000000){//NO ENTIENDO ESTA CONDICIÓN
				if(distanciaInicio > distancia2){
					if(distancia2 < distanciaMejor){
						distanciaMejor=distancia2;
					}
				}
			}
			else{
				distanciaMejor=distancia2;
			}
		}
		Coordenada auxD;
		auxD.setI(inicio.getI());
		auxD.setJ(inicio.getJ()+1);
		if(t->sePuedeDerecha(i, j)==true && estaVisitada(auxD)==false){
			nodos=nodos+1;
			distancia3=d.compararDistancia(auxD,destino);
			if(distanciaMejor!=1000000){
				if(distanciaInicio > distancia3){
					if(distancia3 < distanciaMejor){
						distanciaMejor=distancia3;
					}
				}
			}
			else{
				distanciaMejor=distancia3;
			}
		}
		Coordenada auxI;
		//NO ENTIENDO ESTO, PARA QUE CREAS UNA COORDENADA AUXILIAR SI NO LA VAS A USAR EN SEPUEDEIZQUIERDA, PERO DE REÈNTE LA USAS EN ESTAVISITADA
		auxI.setI(inicio.getI());
		auxI.setJ(inicio.getJ()-1);
		if(t->sePuedeIzquierda(i, j)==true && estaVisitada(auxI)==false){
			nodos=nodos+1;
			distancia4=d.compararDistancia(auxI, destino);
			if(distanciaMejor!=1000000){
				if(distanciaInicio > distancia4){
					if(distancia4 < distanciaMejor){
						distanciaMejor=distancia4;
					}
				}

			}
			else{
				distanciaMejor=distancia4;
			}
		}


		if(distanciaMejor!=1000000){
			if(inicio.getI()!= destino.getI() || inicio.getJ()!=destino.getJ()){
				if(distanciaMejor==distancia1){
					t->moverArriba(i, j);
					insertarCasilla(auxAr);
					cout<<"Movimiento Realizado: AR"<<endl;
					mov=true;
					avanzar=1;
				}
				else{
					if(distanciaMejor==distancia2){
						t->moverAbajo(i, j);
						insertarCasilla(auxAb);
						cout<<"Movimiento Realizado: AB"<<endl;
						mov=true;
					    avanzar=1;
					}
					else{
						if(distanciaMejor==distancia3){
							t->moverDerecha(i, j);
							insertarCasilla(auxD);
							cout<<"Movimiento Realizado: D"<<endl;
							mov=true;
							avanzar=1;
						}
						else{
							if(distanciaMejor==distancia4){
								t->moverIzquierda(i, j);
								insertarCasilla(auxI);
								cout<<"Movimiento Realizado: I"<<endl;
								mov=true;
								avanzar=1;
							}
						}
					}
				}
			}
			else{
				cout<<"No se ha podido avanzar a otra posicion"<<endl;
				mov=true;
				avanzar=0;
			}
		}
		else{
			cout<<"No se ha podido avanzar a otra posicion"<<endl;
			mov=true;
			avanzar=0;
		}
	}
}


MaximaPendiente::~MaximaPendiente() {
	delete this->t;
}

