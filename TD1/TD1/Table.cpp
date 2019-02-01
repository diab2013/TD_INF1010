#include "Table.h"
//Vérifier si d'autres include sont nécéssaires (Menu.h?)

//constructeurs
Table::Table() {
	//constructeur par défaut
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	occupee_ = false;
	commande_ = new Plat*[MAXCAP];
}

Table::Table(int id, int nbPlaces) {
	//constructeur avec paramètres
	id_ = id;
	nbPlaces_ = nbPlaces;
	//Construire Menu avec methode de lecture
}

//getters
int Table::getId() const {
	//retourne le id de la table
	return { id_ };
}

unsigned int Table::getNbPlaces() const { //ajout unsigned
	//retourne le nombre de place sur la table
	return { nbPlaces_ };
}

bool Table::estOccupee() const {
	//retourne si la table est occupée ou pas
	return occupee_;
}

//setters
void Table::libererTable() {
	delete commande_;
	commande_ = new Plat*[MAXCAP];//maybe?
	occupee_ = false;
}

void Table::placerClient() {
	//la table devient occupé
	occupee_ = true;
}

void Table::setId(int id) {
	//set le id de la table
	id_ = id;
}

//autres methodes
void Table::commander(Plat* plat) {
	nbPlats_++;
	commande_[nbPlats_] = plat;
}

double Table::getChiffreAffaire() {
	//Calcul le chiffre d'affaire de la table et le retourne
	double chiffreAffaire = 0.0;
	for (unsigned i = 0; i < nbPlats_; i++){
		double prix = commande_[i]->getPrix();//car getPrix est const
		double cout = commande_[i]->getCout();//car getCout est const
		chiffreAffaire += (prix - cout);
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
				commande_[i]->afficher();
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