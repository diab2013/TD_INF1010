/*
* Titre : Boisson.cpp - Travail Pratique #4
* Date : 25 Mars 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creet un objet de boisson ainsi que ses attributs.
*/
#include "Boisson.h"

/*
 * Constructeur par paramètres de la classe
 * IN: nom de la boisson, type string_view
 *	   prix de la boisson, type double
*/
Boisson::Boisson (string_view nom, double prix): nom_(nom), prix_(prix) {
	taxe_ = 0.12;
}

/*
 * Getter de l'attribut nom_
 * OUT: return l'attribut nom_ de l'objet
*/
string_view Boisson::getNom() const{ 
	return nom_;
}

/*
 * Getter le prix de la boisson
 * OUT: return le prix de la boisson incluant la taxe appliquée
*/
double Boisson::getPrix()  const{
	return { prix_ + (prix_ * taxe_) };
}

void Boisson::setTaxe(double taxe){
	taxe_ = taxe;
}

double Boisson::getTaxe() const{
	return taxe_;
}
