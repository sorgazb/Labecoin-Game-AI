/*
 * Fichero.cpp
 *
 *  Created on: 15 abr. 2023
 *      Author: alumno
 */

#include "Fichero.h"

Fichero::Fichero() {
	// TODO Auto-generated constructor stub

}

int Fichero::menu() {
	int opcion;
	do{
		cout<<endl;
		cout<<"------MENU ELECION LABERINTO-------"<<endl;
		cout<<"|          -1.LABECOIN1           |"<<endl;
		cout<<"|          -2.LABECOIN2           |"<<endl;
		cout<<"|          -3.LABECOIN3           |"<<endl;
		cout<<"|          -4.LABECOIN4           |"<<endl;
		cout<<"|          -5.LABECOIN5           |"<<endl;
		cout<<"|          -6.LABECOIN6           |"<<endl;
		cout<<"|          -7.LABECOIN7           |"<<endl;
		cout<<"|          -8.LABECOIN8           |"<<endl;
		cout<<"|          -9.LABECOIN9           |"<<endl;
		cout<<"|        -10.LABECOIN10           |"<<endl;
		cout<<"|          -11.OTRO               |"<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"Opcion: "<<endl;
		cin>>opcion;
		cin.ignore();
	}while((opcion < 0) || (opcion>12));
	return opcion;
}

void Fichero::seleccionarTablero(string &nombreLaberinto) {
	int opcion;
		//opcion=menu();
		opcion=11;
		switch(opcion){
		case 1:
			cout<<"Has seleccionado LABECOIN1:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN1.txt";
			break;
		case 2:
			cout<<"Has seleccionado LABECOIN2:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN2.txt";
			break;
		case 3:
			cout<<"Has seleccionado LABECOIN3:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN3.txt";
			break;
		case 4:
			cout<<"Has seleccionado LABECOIN4:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN4.txt";
			break;
		case 5:
			cout<<"Has seleccionado LABECOIN5:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN5.txt";
			break;
		case 6:
			cout<<"Has seleccionado LABECOIN6:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN6.txt";
			break;
		case 7:
			cout<<"Has seleccionado LABECOIN7:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN7.txt";
			break;
		case 8:
			cout<<"Has seleccionado LABECOIN8:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN8.txt";
			break;
		case 9:
			cout<<"Has seleccionado LABECOIN9:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN9.txt";
			break;
		case 10:
			cout<<"Has seleccionado LABECOIN10:"<<endl;
			cout<<endl;
			nombreLaberinto="LABECOIN10.txt";
			break;
		case 11:
			cout<<"Has saleccionado otro LABECOIN: "<<endl;
			cout<<"Introduce el nombre + .extension"<<endl;
			cin>>nombreLaberinto;
			break;
		default :
			break;
		}
}

Fichero::~Fichero() {
	// TODO Auto-generated destructor stub
}

