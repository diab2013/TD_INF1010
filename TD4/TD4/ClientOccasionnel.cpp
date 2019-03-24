/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#include "ClientOccasionnel.h"

/*
 * Constructeur par param�tres de la classe
 * IN:
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
 * M�thode d'affichage des attributs de la classe
 * IN: une r�f�rence � un ostream pour l'affichage
*/
void ClientOccasionnel::afficherClient(ostream & os) const {
	(*this).afficherClient(os);
}

/*
 * Getter pour la r�duction
 * Cependant, un client occasionnel n'a aucune r�duction donc return 0
*/
double ClientOccasionnel::getReduction(const Restaurant & res, double montant, bool estLivraison) {
	estLivraison = 0;//a laisser? et pk on get le Resto?
	return 0.0;
}