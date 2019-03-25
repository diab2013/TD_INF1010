/*
* Titre : PlatBioVege.cpp - Travail Pratique #4
* Date : 25 Mars 2019
* Auteurs : Diab Khanafer et Charles-Etienne D�sormeaux
* Description : Cr�er un objet de plat vegetarien et 
*				biologique ainsi que ses attributs.
*/
#include "PlatBioVege.h"

/*
 * Contructeurs par param�tres de la classe
 * IN: nom du plat, prix du plat, cout du plat, prix de la taxe ecologique
 *     quantite de vitamines, quantite de proteines, quantite de mineraux
*/
PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux)
			:PlatBio(nom, prix, cout,ecotaxe), Vege(nom, vitamines, proteines, mineraux)
{}

/*
 * Destructeur de la classe
*/
PlatBioVege:: ~PlatBioVege(){}

/*
 * M�thode pour l'affichage des attributs du plat bio vege
 * IN: la r�f�rence � un ostream pour l'affichage
*/
void PlatBioVege::afficherPlat(ostream & os) const {
	((PlatBio)*this).afficherPlat(os);
	os << "ET ";
	(*this).afficherVege(os);
}

/*
 * M�thode pour returner un clone de l'objet actuel
 * OUT: une r�f�rence vers un clone du PlatBioVege
*/
Plat * PlatBioVege::clone() const {
	PlatBioVege* platBioVege = new PlatBioVege(*this);
	return platBioVege;
}

/*
 * M�thode pour calculer l'apport nutritif du platBioVege
 * OUT: return la r�ponde au calcul de l'apport nutritif
*/
double PlatBioVege::calculerApportNutritif() const {
	return (vitamines_* proteines_ / mineraux_)*RAPPORT_NUTRITIF_BIO*AVANTAGE_SANS_PESTICIDE;
}
