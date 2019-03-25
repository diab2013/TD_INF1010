/*
* Titre : ClientOccasionnel.cpp - Travail Pratique #4
* Date : 25 Mars 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creet un objet de client occasionnel ainsi que ses attributs.
*/
#include "ClientOccasionnel.h"

/*
 * Constructeur par paramètres de la classe
 * IN: nom du client, prenom du client, taille du groupe du clients
*/
ClientOccasionnel::ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe)
:Client(nom,prenom,tailleGroupe)
{}

/*
 * Destructeur de la classe
*/
ClientOccasionnel::~ClientOccasionnel(){}

/*
 * Getter de l'attribut nbPoints_
 * Cependant, un client occasionnel n'a aucun point donc return 0
*/
int ClientOccasionnel::getNbPoints() const {
	return 0;
}

/*
 * Méthode d'affichage des attributs de la classe
 * IN: une référence à un ostream pour l'affichage
*/
void ClientOccasionnel::afficherClient(ostream & os) const {
	os << prenom_ << " " << nom_ << " avec " << tailleGroupe_ << " personne(s)";
	if (tableOccupee_ != nullptr) {
		os << tableOccupee_ << endl; //a revoir
	}
	else {
		os << endl;
	}
}

/*
 * Getter pour la réduction
 * Cependant, un client occasionnel n'a aucune réduction donc return 0
*/
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison) {
	estLivraison = 0;//a laisser? et pk on get le Resto?
	return 0.0;
}
