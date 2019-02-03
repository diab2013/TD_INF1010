/*
* Titre : Plat.cpp - Travail Pratique #1
* Date : 04 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer un plat ainsi que ses attributs.
*/

#include "Plat.h"

// constructeurs
Plat::Plat() {
	//constructeur par défaut
	nom_ = "inconnu";
	prix_ = 0;
	cout_ = 0;
}

Plat::Plat(string nom, double prix, double cout) {
	//constructeur avec paramètres
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

//getters
string Plat::getNom() const {
	//retourne le nom du plat
	return { nom_ };
}

double Plat::getPrix() const {
	//retourne le prix du plat
	return { prix_ };
}

double Plat::getCout() const {
	//retourne le cout de production du plat
	return{ cout_ };
}

//setters
void Plat::setNom(string nom){
	//set le nom du plat
	nom_ = nom;
}

void Plat::setPrix(double prix){
	//set le prix du plat
	prix_ = prix;
}

//affichage
void Plat::afficher() const{
	cout << "\t" << nom_ << " - " << prix_ << "$ (" << cout_ 
		 << "$ pour le restaurant)" << endl;
	//autre chose maybe?
}