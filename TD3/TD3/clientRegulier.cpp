/*
* Titre : clientRegulier.cpp - Travail Pratique #3
* Date : 25 F�vrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne D�sormeaux
* Description : Creer un client de ainsi que ses attributs.
*/
#include "ClientRegulier.h"

ClientRegulier::ClientRegulier() : Client() {
	nbPoints_ = NULL;
}

ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints) {
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
	nbPoints_ = nbPoints;
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
