/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Table.h"

//constructeurs
Table::Table() {
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

Table::Table(int id, int nbPlaces) {
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}

//destructeur
Table::~Table() {
	//A MODIFIER¸
	libererTable();
}

//getters
int Table::getId() const {
	return id_;
}

int Table::getNbPlaces() const {
	return nbPlaces_;
}

int Table::getnbClientATable() const{
	return nbClientsATable_;
}

bool Table::estPleine() const {
	return nbPlaces_==0;
}

bool Table::estOccupee() const{
	return nbClientsATable_!=0;
}

//setters
void Table::setId(int id) {
	id_ = id;
}

void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	for (int i = 0; i < nbPlats_; i++) {
		commande_.pop_back();
	}
	nbPlats_ = 0;
}

void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;
}

//autres methodes
void Table::commander(Plat* plat) {
	if (nbPlats_ == capacite_) {
		capacite_ *= 2;
	}
	commande_.push_back(plat);
	nbPlats_++;
}

double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (int i = 0; i < nbPlats_; i++) {
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}

//override
ostream & operator<<(ostream & o, const Table & table){
	cout << "La table numero " << table.getId();
	if (table.estOccupee()) {
		cout << " est occupee. ";
		if (table.nbPlats_ != 0) {
			cout << "Voici la commande passee par les clients : " << endl;
			for (int i = 0; i < table.nbPlats_; i++) {
				cout << "\t";
				cout << *table.commande_[i];
			}
		} else {
			cout << "Mais ils n'ont rien conmmande pour l'instant. " << endl;
		}
	} else {
		cout << " est libre. " << endl;
	}
	return o;
}
