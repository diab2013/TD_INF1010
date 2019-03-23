/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "ClientOccasionnel.h"

ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe)
:Client(nom,prenom,tailleGroupe)
{}

ClientOccasionnel::~ClientOccasionnel(){}

int ClientOccasionnel::getNbPoints() const {
	return 0;
}

void ClientOccasionnel::afficherClient(ostream & os) const {
	(*this).afficherClient(os);
}
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison) {
	estLivraison = 0;//a laisser? et pk on get le Resto?
	return 0.0;
}
