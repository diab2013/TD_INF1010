/*
* Titre : Table.cpp - Travail Pratique #1
* Date : 04 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer une table ainsi que ses attributs.
*/

#include "Table.h"

/*
* Constructeur par défaut de la classe Table
* Crée une nouvelle liste de plat vide avec une capacité de MAXCAP 
* Le nombre de plat est zéro, le id de la table est -1, le nombre de places à 1
* et la table n'est pas occupée
*/
Table::Table() {
	capacite_ = MAXCAP;
	id_ = -1;
	nbPlaces_ = 1;
	nbPlats_ = 0;
	occupee_ = false;
	commande_ = new Plat*[capacite_];
}

/*
* Constructeur par paramétres de la classe Table
* Initialise les attributs à des valeurs passées en paramètres
*/
Table::Table(int id, int nbPlaces) {
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbPlats_ = 0;
	occupee_ = false;
	capacite_ = MAXCAP;
	commande_ = new Plat*[capacite_];
}

/*
* Getter de la variable id
* Return l'attribut id_ de la classe
*/
int Table::getId() const {
	return { id_ };
}

/*
* Getter de la variable nbPlaces_
* Return l'attribut nbPlaces_ de la classe
*/
unsigned int Table::getNbPlaces() const {
	return { nbPlaces_ };
}

/*
* Getter de la variable occupee_
* Return l'attribut occupee_ de la classe
*/
bool Table::estOccupee() const {
	//retourne si la table est occupée ou pas
	return { occupee_ };
}

/*
* Méthode qui permet de liberer une table et la reset
* Supprime la commande actuelle et met la table comme libre
*/
void Table::libererTable() {
	delete[] commande_;
	delete commande_;
	commande_ = new Plat*[capacite_]; //reinitialise la commande de la table
	occupee_ = false;
}

/*
* Méthode qui permet de placer la table comme occupee
*/
void Table::placerClient() {
	//la table devient occupé
	occupee_ = true;
}

/*
* Méthode qui set le id
* à la valeur passée en paramètre
*/
void Table::setId(int id) {
	//set le id de la table
	id_ = id;
}

/*
* Méthode qui permer de commande un plat pour les clients assis à la table
* Si le nombre de plats commander n'est pas dépassé, ajoute le plat passé
* en paramètre à la liste de commande 
*/
void Table::commander(Plat* plat) {
	if (nbPlats_ < capacite_) {
		commande_[nbPlats_] = new Plat();
		commande_[nbPlats_] = plat;
		nbPlats_++;
	} else {
		cout << "Plus de place pour commander" << endl;
	}
	
}

/*
* Méthode qu perment de calculer le chiffre d'affaire fait par la liste de commande
* de la table
* return le chiffre d'affaire après le calcul
*/
double Table::getChiffreAffaire() {
	//Calcul le chiffre d'affaire de la table et le retourne
	double chiffreAffaire = 0.0;
	for (unsigned i = 0; i < nbPlats_; i++){
		double prix = commande_[i]->getPrix(); //car getPrix est const
		double cout = commande_[i]->getCout(); //car getCout est const
		chiffreAffaire += (prix - cout);
	}
	return chiffreAffaire;
}

/*
* Méthode d'affichage de la classe Table
* Affiche les attributs de l'objet lorsque la méthode est appelée
* Présente l'id de la table, ainsi que le nombre de place à cette derniere
* Présente aussi si elle est occupée et la liste des plats commandés si les clients
* ont commander de quoi
*/
void Table::afficher() {
	//Affichage de la table
	cout << "La table " << getId() << ", avec " << nbPlaces_ << " places, ";
	//Si table occupee
	if (estOccupee()) {
		cout << " est occupee." << endl;
		//Si les clients ont fait des commandes ou pas
		if (nbPlats_ != 0) {
			cout << "\t -> Voici la commande passee par les clients : " << endl;
			for (unsigned i = 0; i < nbPlats_; i++) {
				commande_[i]->afficher();
			}
		}
		//Si aucune commande
		else {
			cout << "\t -> Ils n'ont rien commende pour l'instant." << endl;
		}
	} else{
		cout << " est libre." << endl;
	}
}