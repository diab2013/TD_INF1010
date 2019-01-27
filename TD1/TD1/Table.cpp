#include "Table.h"
//V�rifier si d'autres include sont n�c�ssaires (Menu.h?)

//constructeurs
Table::Table() {
	//constructeur par d�faut
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	commande_ = new Plat*[MAXPLAT];
}

Table::Table(int id, int nbPlaces) {
	//constructeur avec param�tres
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
	//retourne si la table est occup�e ou pas
	return occupee_;
}

//setters
void Table::libererTable() {
	commande_ = new Plat*[MAXPLAT];//maybe?
	occupee_ = false;
}

void Table::placerClient() {
	//la table devient occup�
	occupee_ = true; //vu que la table devient occup�e par qqun?

}

void Table::setId(int id) {
	//set le id de la table
	id_ = id;
}

//autres methodes
void Table::commander(Plat * plat) {
	nbPlats_++;
	commande_[nbPlats_] = plat;
}

double Table::getChiffreAffaire() {
	//Calcul le chiffre d'affaire de la table et le retourne
	double chiffreAffaire = 0.0;
	for (unsigned i = 0; i < nbPlats_; i++){
		chiffreAffaire += (commande_[i]->getPrix - 
						   commande_[i]->getCout);
	}
	return chiffreAffaire;
}

//affichage
void Table::afficher() {
	//Affichage de la table
	//Si table occupee
	cout << "Voici les tables :" << endl;
	if (occupee_) {
		cout << "La table numero " << id_ << " est occupee.";
		//Si commande
		if (nbPlats_ > 0) {
			cout << "Voici la commande passee par les clients : " << endl;
			for (unsigned i = 0; i < nbPlats_; i++) {
				cout << commande_[i]->afficher << endl;
			}
		}
		//Si aucune commande
		else {
			cout << "Mais ils n'ont rien commende pour l'instant." << endl;
		}
	}
	//Si table vide
	else {
		cout << "La table numero " << id_ << " est libre." << endl;
	}
}