/*
* Titre : PlatCustom.cpp - Travail Pratique #3
* Date : 25 Février 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creer un plat custom selon des demandes.
*/

#include "PlatCustom.h"

PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
	nbIngredients_ = nbIngredients;
	type_ = Custom;
}

int PlatCustom::getNbIngredients() const {
	return { nbIngredients_ };
}

double PlatCustom::getSupplement() const {
	return { supplement_ };
}

void PlatCustom::setNbIngredients(int nIngredients) {
	nbIngredients_ = nIngredients;
}


double PlatCustom::calculerSupplement() const {
	return { nbIngredients_*FRAIS_CUSTOMISATION };
}

ostream& operator<<(ostream& os, const PlatCustom& plat) {
	os << plat.nom_ << " - " << (plat.prix_+ plat.supplement_) << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return os;
}
