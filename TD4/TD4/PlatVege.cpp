/*
* Titre : PlatVege.cpp - Travail Pratique #4
* Date : 25 Mars 2019
* Auteurs : Diab Khanafer et Charles-Etienne D�sormeaux
* Description : Creet un objet de plat vegetarien ainsi que ses attributs.
*/
#include "PlatVege.h"

/*
 * Constructeur par param�tres de la classe
 * IN: nom du plat, prix du plat, cout du plat, quantite de vitamines,
 *     quantite de proteines, quantite de mineraux
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
Plat* PlatVege::clone() const {
	PlatVege* platVege = new PlatVege(*this);
	return platVege;
}

/*
 * M�thode pour l'affichage des attributs du plat vege
 * IN: la r�f�rence � un ostream pour l'affichage
*/
void PlatVege::afficherPlat(ostream & os) const {
	((Plat)*this).afficherPlat(os);
	(*this).afficherVege(os);
	os << "(Apport nutritif " << (*this).calculerApportNutritif() << " mg)" << endl;
}

/*
 * M�thode pour calculer l'apport nutritif du plat vege
 * OUT: return le r�sultat du calcul de l'apport
*/
double PlatVege::calculerApportNutritif() const {
	return { (vitamines_ * proteines_ / mineraux_) * RAPPORT_NUTRITIF };
}

/*
 * Setetr de l'attribut taxe_
 * IN: nouvelle valeur de l'attribut taxe_ de l'objet
*/
void PlatVege::setTaxe(double taxe){
	taxe_ = taxe;
}

/*
 * Getter de l'attribut taxe_
 * OUT: return l'attribut taxe_ de l'objet
*/
double PlatVege::getTaxe() const{
	return taxe_;
}
