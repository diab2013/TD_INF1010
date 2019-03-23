/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBioVege.h"

PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux)
			:PlatBio(nom, prix, cout,ecotaxe), Vege(nom, vitamines, proteines, mineraux)
{}
PlatBioVege:: ~PlatBioVege(){}

void PlatBioVege::afficherPlat(ostream & os) const {
	((PlatBio)*this).afficherPlat(os);
	os << "ET ";
	(*this).afficherVege(os);//ajouter calculerApportNutritif?
}

Plat * PlatBioVege::clone() const {
	PlatBioVege* platBioVege = new PlatBioVege(*this);
	return platBioVege;
}

double PlatBioVege::calculerApportNutritif() const {
	return (vitamines_* proteines_ / mineraux_)*RAPPORT_NUTRITIF_BIO*AVANTAGE_SANS_PESTICIDE;
}
