#include "Table.h"<
//Vérifier si d'autres include sont nécéssaires (Menu.h?)

//constructeurs
Table::Table() {
	//constructeur par défaut
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	*commande_ = new Plat[MAXPLAT];
}

Table::Table(int id, int nbPlaces) {
	//constructeur avec paramètres
	id_ = id;
	nbPlaces_ = nbPlaces;
	//Construire Menu avec methode de lecture
}

//getters
int Table::getId(){
	//retourne le id de la table
	return { id_ };
}

unsigned int Table::getNbPlaces() { //ajout unsigned
	//retourne le nombre de place sur la table
	return { nbPlaces_ };
}

bool Table::estOccupee() {
	//retourne si la table est occupée ou pas
	return occupee_;
}

//setters
void Table::libererTable() {
	//libère la table de ses occupants et la reset
	occupee_ = false;
	*commande_ = new Plat[MAXPLAT];	//yep, faut also libérer la table
}

void Table::placerClient() {
	//la table devient occupé
	occupee_ = true; //vu que la table devient occupée par qqun?

}

void Table::setId(int id) {
	//set le id de la table
	id_ = id;
}

//autres methodes
void Table::commander(Plat * plat) {
	//ajoute un plat à la liste de pointeurs de commande de la table
	if (nbPlats_ < capacite_) {
		//ajouter le plat au tableau de commande s'il y a de la place
	}
}

double Table::getChiffreAffaire() {
	//Calcul le chiffre d'affaire de la table et le retourne
	return 0.0;
}

//affichage
void Table::afficher() {
	//Affichage de la table
}