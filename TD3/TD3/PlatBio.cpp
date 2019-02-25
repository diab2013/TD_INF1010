/*
* Titre : PlatBio.cpp - Travail Pratique #3
* Date : 25 Février 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creer un plat biologique.
*/

#include "PlatBio.h"


PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
	ecoTaxe_ = ecotaxe;
	type_ = Bio;
}

double PlatBio::getEcoTaxe() const {
	return { ecoTaxe_ };
}

void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}

ostream & operator<<(ostream & os, const PlatBio & plat) {
	os << plat.nom_ << " - " << (plat.prix_ + plat.prix_*plat.ecoTaxe_) << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return os;
}
