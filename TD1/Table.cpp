#include "Table.h"

//constructeurs
Table::Table() {
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	*commande_ = new Plat[MAXPLAT];
}

Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	//Construire Menu avec methode de lecture
}

//getters
int Table::getId(){
	return { id_ };
}

unsigned int Table::getNbPlaces() { //ajout unsigned
	return { nbPlaces_ };
}

double Table::getChiffreAffaire() {
	return 0.0;
}

bool Table::estOccupee() {
	return occupee_;
}

//setters
void Table::libererTable() {
	*commande_ = new Plat[MAXPLAT];//maybe?
}

void Table::placerClient() {

}

void Table::setId(int id) {
	id_ = id;
}

//autres methodes
void Table::commander(Plat * plat) {

}

//affichage

void Table::afficher() {

}

