/*
* Titre : PlatBioVege.cpp - Travail Pratique #4
* Date : 25 Mars 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Créer un objet de plat vegetarien et 
*				biologique ainsi que ses attributs.
*/
#include "PlatBioVege.h"

/*
 * Contructeurs par paramètres de la classe
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
 * Méthode pour l'affichage des attributs du plat bio vege
 * IN: la référence à un ostream pour l'affichage
*/
void PlatBioVege::afficherPlat(ostream & os) const {
	((PlatBio)*this).afficherPlat(os);
	os << "ET ";
	(*this).afficherVege(os);
}

/*
 * Méthode pour returner un clone de l'objet actuel
 * OUT: une référence vers un clone du PlatBioVege
*/
Plat * PlatBioVege::clone() const {
	PlatBioVege* platBioVege = new PlatBioVege(*this);
	return platBioVege;
}

/*
 * Méthode pour calculer l'apport nutritif du platBioVege
 * OUT: return la réponde au calcul de l'apport nutritif
*/
double PlatBioVege::calculerApportNutritif() const {
	return (vitamines_* proteines_ / mineraux_)*RAPPORT_NUTRITIF_BIO*AVANTAGE_SANS_PESTICIDE;
}
