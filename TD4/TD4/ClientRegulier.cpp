/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#include "ClientRegulier.h"

/*
 * Constructeur par d�faut de la classe
*/
ClientRegulier::ClientRegulier() {
	nbPoints_ = 0;
}

/*
 * Constructeur par param�tres de la classe
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
 * M�thode pour augmenter le nombre de point du clien
 * IN: le nombre de points � ajouter � l'attribut nbPoints_
*/
void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

/*
 * M�thode d'affichage des attributs de la classe
 * IN: une r�f�rence � un ostream pour l'affichage
*/
void ClientRegulier::afficherClient(ostream & os) const {
	(*this).afficherClient(os);
	//ajout de plus?
}

/*
 * M�thode pour obtenir la r�duction pour le client
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
