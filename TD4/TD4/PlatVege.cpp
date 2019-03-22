/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


//TODO
PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux) {
    //TODO
}
PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const { //TODO
	PlatVege* platVege = new PlatVege(*this);
	return platVege;
}


void PlatVege::afficherPlat(ostream & os) const {
	((Plat)*this).afficherPlat(os);
}

double PlatVege::calculerApportNutritif() const
{

    //TODO
}
