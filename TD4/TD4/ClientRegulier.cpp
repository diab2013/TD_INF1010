/*
* Titre : ClientRegulier.cpp - Travail Pratique #4
* Date : 25 Mars 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creet un objet de client regulier ainsi que ses attributs.
*/
#include "ClientRegulier.h"

/*
 * Constructeur par défaut de la classe
*/
ClientRegulier::ClientRegulier() {
	nbPoints_ = 0;
}

/*
 * Constructeur par paramètres de la classe
 * IN: nom du client, prenom du client, taille du groupe du client, nombre de points du client
*/
ClientRegulier::ClientRegulier(string_view nom, string_view prenom, int tailleGroupe, int npoints)
:Client(nom,prenom,tailleGroupe),nbPoints_(npoints)
{}

/*
 * Destructeur de la classe
*/
ClientRegulier::~ClientRegulier() {}

/*
 * Getter de l'attribut nbPoints_
 * OUT: return l'attribut nbPoints_ de l'objet
*/
int ClientRegulier::getNbPoints() const {
	return nbPoints_;
}

/*
 * Méthode pour augmenter le nombre de point du clien
 * IN: le nombre de points à ajouter à l'attribut nbPoints_
*/
void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

/*
 * Méthode d'affichage des attributs de la classe
 * IN: une référence à un ostream pour l'affichage
*/
void ClientRegulier::afficherClient(ostream & os) const {
	os << prenom_ << " " << nom_ << " avec " << tailleGroupe_ << " personne(s)";
	if (tableOccupee_ != nullptr) {
		os << tableOccupee_ << endl; //a revoir
	}
	else {
		os << endl;
	}
}

/*
 * Méthode pour obtenir la réduction pour le client
 * IN: 
*/
double ClientRegulier::getReduction(const Restaurant & res, double montant, bool estLivraison) {
	estLivraison = 0;
	if (nbPoints_ > SEUIL_DEBUT_REDUCTION) {
		return { -montant * TAUX_REDUC_REGULIER };
	} else {
		return 0.0;
	}
}
