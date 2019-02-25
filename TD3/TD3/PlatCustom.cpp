/*
* Titre : PlatCustom.cpp - Travail Pratique #3
* Date : 25 Février 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creer un plat custom selon des demandes.
*/

#include "PlatCustom.h"

/*
* Constructeur par paramètre de la classe PlatCustim
* Initialise les attributs à des valeurs passées en paramètres
*/
PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients) 
	: Plat(nom, prix, cout){
	nbIngredients_ = nbIngredients;
	supplement_ = calculerSupplement();
	type_ = Custom;
}

/*
* Out: Variable de nombre d'ingredients de type int
* Renvoie la variable privee nbIngredients_
*/
int PlatCustom::getNbIngredients() const {
	return { nbIngredients_ };
}

/*
* Out: Variable de supplement de type double
* Renvoie la variable privee supplement_
*/
double PlatCustom::getSupplement() const {
	return { supplement_ };
}

/* 
* In: variable de nombre d'ingredient de type int
* Set la variable privee nbIngredients_ a la valeur en paramettre
*/
void PlatCustom::setNbIngredients(int nIngredients) {
	nbIngredients_ = nIngredients;
	supplement_ = calculerSupplement();
}

/*
* Out: Prix du supplement d'ingredient
* Renvoie la valeur du nombre d'ingredient multiplié par les frais de customisation
*/
double PlatCustom::calculerSupplement() const {
	return { nbIngredients_*FRAIS_CUSTOMISATION };
}

/*
* In/out: stream de l'output
* In: Plat a afficher
* Out: String contenant tous les informations d'un plat custom
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream& operator<<(ostream& os, const PlatCustom& plat) {
	os << static_cast<Plat>(plat) << "\t et contient " << plat.nbIngredients_ << " ingredients pour "
		<< plat.supplement_ << "$" << endl;
	return os;
}
