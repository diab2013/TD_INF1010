/*
* Titre : PlatBio.cpp - Travail Pratique #3
* Date : 25 Février 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creer un plat biologique ainsi que ses attributs.
*/

#include "PlatBio.h"

/*
* Constructeur par paramètre de la classe PlatBio
* Initialise les attributs à des valeurs passées en paramètres
*/
PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe) 
	: Plat(nom, prix, cout){
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
* Set la variable privee ecoTaxe_ a la valeur en parametre
*/
void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}

/*
* In/out: stream de l'output
* In: Plat biologique a afficher
* Out: String contenant tous les informations d'un plat biologique
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream & operator<<(ostream & os, const PlatBio & plat) {
	os << static_cast<Plat>(plat) << "\t avec une taxe ecologique de : " << plat.ecoTaxe_ << "$" << endl;
	return os;
}
