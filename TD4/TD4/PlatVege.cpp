/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"

/*
 * Constructeur par param�tres de la classe
 * IN:
*/
PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux)
	: Plat(nom, prix, cout), Vege(nom, vitamines, proteines, mineraux) 
{
	//rien � faire
}

/*
 * Destructeur de la classe
*/
PlatVege::~PlatVege(){
	//rien � faire
}

/*
 * M�thode pour returner un clone de l'objet actuel
 * OUT: une r�f�rence vers un clone du plat vege
*/
Plat* PlatVege::clone()const { //TODO
	PlatVege* platVege = new PlatVege(*this);
	return platVege;
}

/*
 * M�thode pour l'affichage des attributs du plat vege
 * IN: la r�f�rence � un ostream pour l'affichage
*/
void PlatVege::afficherPlat(ostream & os) const {
	//useless vu que tu fais deja afficherVege()
	//os << "PLAT VEGE " << (*this).Plat::nom_ << " ";
	(*this).afficherVege(os);
	os << endl;
	os << (*this).calculerApportNutritif() << endl;
}

/*
 * M�thode pour calculer l'apport nutritif du plat vege
 * OUT: return le r�sultat du calcul de l'apport
*/
double PlatVege::calculerApportNutritif() const {
	return (vitamines_ * proteines_ / mineraux_) * RAPPORT_NUTRITIF;
}