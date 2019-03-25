/*
* Titre : ClientPrestige.cpp - Travail Pratique #4
* Date : 25 Mars 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creet un objet de client prestige ainsi que ses attributs.
*/
#include "ClientPrestige.h"
#include "Restaurant.h"

/*
 * Constructeur par défaut de la classe
*/
ClientPrestige::ClientPrestige() {
	adresse_ = ZoneHabitation::Zone3;
}

/*
 * Constructeur par paramètres de la classe
 * IN: nom du client, prenom du client, taille du groupe du client,
 *     nombre de points du client, adresse du client
*/
ClientPrestige::ClientPrestige(string_view nom, string_view prenom, int tailleGroupe, int nbPoints, ZoneHabitation adresse)
	: ClientRegulier(nom,prenom,tailleGroupe,nbPoints),adresse_(adresse)
{}

/*
 * Destructeur de la classe
*/
ClientPrestige::~ClientPrestige() {};

/*
 * Getter de l'attribut adresse_
 * OUT: return l'attribut adresse_ de l'objet
*/
ZoneHabitation ClientPrestige::getAdresseCode() const {
	return adresse_;
}

/*
 * Méthode pour l'affichage des attributs de la classe
 * IN: une référence à un ostream pour l'affichage
*/
void ClientPrestige::afficherClient(ostream & os) const {
	((ClientRegulier)*this).afficherClient(os);
	//ajout de plus?
}

/*
 * Getter de l'attribut adresse_
 * OUT: return l'attribut adresse_ sous forme de string
*/
string ClientPrestige::getAdressCodeString() const {
	string zone;
	switch (adresse_)
	{
		case ZoneHabitation::Zone1:
			zone = "Zone 1";
			break;
		case  ZoneHabitation::Zone2:
			zone = " Zone 2";
			break;
		case  ZoneHabitation::Zone3:
			zone = "Zone 3";
			break;
		default:
			zone = "erreur zone";
			break;
	}
	return zone;
}

/*
 * Getter de la reduction
 * OUT: return le calcul de la réduction de la cliente
*/
double ClientPrestige :: getReduction(const Restaurant & res, double montant , bool estLivraison) {
	estLivraison = 1;
	if (nbPoints_ >= SEUIL_LIVRAISON_GRATUITE) {
		return -montant * TAUX_REDUC_PRESTIGE;
	} else
	return -montant * TAUX_REDUC_PRESTIGE + res.getFraisLivraison(this->getAdresseCode);
}
