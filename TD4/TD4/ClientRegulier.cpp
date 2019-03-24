/*
* Date : 25 février 2019
* Auteur : AbdeB
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
 * IN:
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
	(*this).afficherClient(os);
	//ajout de plus?
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
