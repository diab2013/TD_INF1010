/*
* Titre : PlatBio.cpp - Travail Pratique #3
* Date : 25 F�vrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne D�sormeaux
* Description : Creer un plat biologique.
*/

#include "PlatBio.h"

/*
* Constructeur par param�tre de la classe PlatBio
* Initialise les attributs � des valeurs pass�es en param�tres
*/
PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
	ecoTaxe_ = ecotaxe;
	type_ = Bio;
}

/*
* Out: Variable de taxe ecologique de type double
* Revoie la variable privee ecoTaxe_
*/
double PlatBio::getEcoTaxe() const {
	return { ecoTaxe_ };
}

/*
* In: variable de taxe ecologique de type double
* Set la variable privee ecoTaxe_ a la valeur en paramettre
*/
void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}

/*
* In/out: stream de l'output
* In: Plat a afficher
* Out: String contenant tous les informations d'un plat biologique
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream & operator<<(ostream & os, const PlatBio & plat) {
	os << plat.nom_ << " - " << (plat.prix_ + plat.prix_*plat.ecoTaxe_) << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return os;
}
