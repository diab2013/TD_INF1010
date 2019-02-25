/*
* Titre : clientRegulier.cpp - Travail Pratique #3
* Date : 25 Février 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creer un client de ainsi que ses attributs.
*/
#include "ClientRegulier.h"

ClientRegulier::ClientRegulier() : Client() {
	statut_ = Fidele;
	nbPoints_ = 0;
}

ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints) 
		: Client(nom, prenom, tailleGroupe) {
	nbPoints_ = nbPoints;
	statut_ = Fidele;
}

int ClientRegulier::getNbPoints() {
	return { nbPoints_ };
}

void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

ostream & operator<<(ostream & os, const ClientRegulier & client) {
	os << static_cast<Client>(client) << " possede " << client.getNbPoints << " point(s)." << endl;
	return os;
}
