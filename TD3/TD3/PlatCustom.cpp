/*
* Titre : PlatCustom.cpp - Travail Pratique #3
* Date : 25 F�vrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne D�sormeaux
* Description : Creer un plat custom selon des demandes.
*/

#include "PlatCustom.h"

/*
* Constructeur par param�tre de la classe PlatCustim
* Initialise les attributs � des valeurs pass�es en param�tres
*/
PlatCustom::PlatCustom(string nom, double prix, double cout, int nbIngredients) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
	nbIngredients_ = nbIngredients;
	type_ = Custom;
}

int PlatCustom::getNbIngredients() const {
	return { nbIngredients_ };
}

/*
* Out: Variable de supplement de type double
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
}

/*
* Out: Prix du supplement d'ingredient
* Renvoie la valeur du nombre d'ingredient multipli� par les frais de customisation
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
	os << plat.nom_ << " - " << (plat.prix_+ plat.supplement_) << " $ (" << plat.cout_ << "$ pour le restaurant)" << endl;
	return os;
}
