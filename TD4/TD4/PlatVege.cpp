/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


//TODO
PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux)
	: Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux) 
{}

PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const { //TODO
	PlatVege* platVege = new PlatVege(*this);
	return platVege;
}


void PlatVege::afficherPlat(ostream & os) const {
	os << "PLAT VEGE " << (*this).Plat::nom_ << " "; //a revoir
	(*this).afficherVege(os);
	os << endl;
	os << (*this).calculerApportNutritif() << endl;
}

double PlatVege::calculerApportNutritif() const {
	return (vitamines_ * proteines_ / mineraux_) * RAPPORT_NUTRITIF;
}
