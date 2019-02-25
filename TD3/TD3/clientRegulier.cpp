/*
* Titre : clientRegulier.cpp - Travail Pratique #3
* Date : 25 Février 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creer un client de ainsi que ses attributs.
*/
#include "ClientRegulier.h"

ClientRegulier::ClientRegulier() {
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
	os << "Le client principal est: \n" << client.getPrenom << " statut: " << client.getStatut();//need repair
	return os;
}
