/*
* Titre : Table.cpp - Travail Pratique #1
* Date : 04 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer une table ainsi que ses attributs.
*/

#include "Table.h"

/*
* Constructeur par d�faut de la classe Table
* Cr�e une nouvelle liste de plat vide avec une capacit� de MAXCAP 
* Le nombre de plat est z�ro, le id de la table est -1, le nombre de places � 1
* et la table n'est pas occup�e
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
* Constructeur par param�tres de la classe Table
* Initialise les attributs � des valeurs pass�es en param�tres
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
	//retourne si la table est occup�e ou pas
	return { occupee_ };
}

/*
* M�thode qui permet de liberer une table et la reset
* Supprime la commande actuelle et met la table comme libre
*/
void Table::libererTable() {
	delete[] commande_;
	delete commande_;
	commande_ = new Plat*[capacite_]; //reinitialise la commande de la table
	occupee_ = false;
}

/*
* M�thode qui permet de placer la table comme occupee
*/
void Table::placerClient() {
	//la table devient occup�
	occupee_ = true;
}

/*
* M�thode qui set le id
* � la valeur pass�e en param�tre
*/
void Table::setId(int id) {
	//set le id de la table
	id_ = id;
}

/*
* M�thode qui permer de commande un plat pour les clients assis � la table
* Si le nombre de plats commander n'est pas d�pass�, ajoute le plat pass�
* en param�tre � la liste de commande 
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
* M�thode qu perment de calculer le chiffre d'affaire fait par la liste de commande
* de la table
* return le chiffre d'affaire apr�s le calcul
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
* M�thode d'affichage de la classe Table
* Affiche les attributs de l'objet lorsque la m�thode est appel�e
* Pr�sente l'id de la table, ainsi que le nombre de place � cette derniere
* Pr�sente aussi si elle est occup�e et la liste des plats command�s si les clients
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