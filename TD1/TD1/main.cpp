/*
* Titre : main.cpp - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#include "Restaurant.h"
#include <iostream>
using namespace std;

int main() {

	//creation du restaurant - avec le fichier donne - le nom : PolyFood - moment de la journee : soir. 
	string nom,filename;
	nom == "Polyfood";
	filename == "polyfood.txt";
	Restaurant poly(filename, nom, Soir);
	//creer plusieurs clients -- des entiers 

	int client1 = 1;
	int client2 = 5;
	int client3 = 15;
	int client4 = 3;
	int client5 = 2;

	//placer les clients 

	// commander des plats
	//Poisson - Table 1 
	//Poulet - Table 2 
	//Pizza - Table 2 
	//Poulet - Table 4
	//Muffin - Table 4 
	//Oeud - Table 4 


	//afficher le restaurant
	poly.afficher();

	cout << "-------------------------------------------------" << endl;

	//liberer les tables
	for (int i = 0; i < 4; i++) {
		poly.libererTable(i-1);//comment on peut faire sa sans get le nombre de table
	}
	//afficher le restaurant 
	poly.afficher();
	return 0;

}