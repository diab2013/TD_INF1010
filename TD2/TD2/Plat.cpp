/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#include "Plat.h"

//constructeurs
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

//getters
string Plat::getNom() const {
	return nom_;
}

double Plat::getPrix() const {
	return prix_;
}

double Plat::getCout() const {
	return cout_;
}

double Plat::getPetitPrix(double a, double b) const{
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
	
}

//setters
void Plat::setNom(string nom) {
	nom_ = nom;
}

void Plat::setPrix(double prix) {
	prix_ = prix;
}

//methodes en plus
string Plat::afficher() const {
	string affichage;
	affichage += nom_;
	affichage += " - ";
	affichage += prix_;
	affichage += " $ (";
	affichage += cout_;
	affichage += "$ pour le restaurant)";
	return { affichage };
}

ostream & operator<<(ostream & o, const Plat & plat){
	string affichage = plat.afficher();
	return o << affichage << endl;
}
