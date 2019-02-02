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
	nom = "Polyfood";
	filename = "polyfood.txt";
	Restaurant poly(filename, nom, Soir);

	//creer plusieurs clients -- des entiers 
	int client1 = 1;
	int client2 = 5;
	int client3 = 15;
	int client4 = 3;
	int client5 = 2;

	//placer les clients 
	poly.placerClients(client1);
	poly.placerClients(client2);
	poly.placerClients(client3);
	poly.placerClients(client4);
	poly.placerClients(client5);

	// commander des plats
	string plat1, plat2, plat3, plat4, plat5, plat6;

	//Poisson - Table 1
	plat1 = "Poisson";
	poly.commanderPlat(plat1, 1);

	//Poulet - Table 2
	plat2 = "Poulet";
	poly.commanderPlat(plat2, 2);

	//Pizza - Table 2 
	plat3 = "Pizza";
	poly.commanderPlat(plat3, 2);

	//Poulet - Table 4
	plat4 = "Poulet";
	poly.commanderPlat(plat4, 4);

	//Muffin - Table 4
	plat5 = "Muffin";
	poly.commanderPlat(plat5, 4);

	//Oeuf - Table 4 
	plat6 = "Oeuf";
	poly.commanderPlat(plat6, 4);

	//afficher le restaurant
	poly.afficher();

	cout << "-------------------------AFFICHAGE DU RESTO------------------------" << endl;

	//liberer les tables
	poly.libererTable(1);
	//for (int i = 0; i < 4; i++) {
	//	poly.libererTable(i-1);//comment on peut faire sa sans get le nombre de table
	//}

	//afficher le restaurant 
	poly.afficher();
	return 0;
}