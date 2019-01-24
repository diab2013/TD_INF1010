#include "Plat.h"

// constructeurs
Plat::Plat() {
	
}

Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

//getters
string Plat::getNom() {
	return { nom_ };
}

double Plat::getPrix() {
	return { prix_ };
}

double Plat::getCout() {
	return{ cout_ };
}

