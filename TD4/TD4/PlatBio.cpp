/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe)
	: Plat(nom, prix, cout), ecoTaxe_(ecotaxe) {

}

PlatBio::~ PlatBio(){}

double PlatBio::getEcoTaxe() const {
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}

Plat * PlatBio:: clone () const {
	PlatBio* platBio = new PlatBio(*this);
	return platBio;
}

double PlatBio::getPrixDeRevient() const {
	return { prix_ - cout_ + ecoTaxe_ };
}

void PlatBio::afficherPlat(ostream& os) const {
	((Plat)*this).afficherPlat(os);
	os << "Plat Bio     comprend une taxe ecologique de :" << ecoTaxe_ << "$" << endl;
}


