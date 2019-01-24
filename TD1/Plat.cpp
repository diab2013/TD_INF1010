#include "Plat.h"

// constructeurs
Plat::Plat() {
	nom_ = "inconnu";
	prix_ = 0;
	cout_ = 0;
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

//setters
void Plat::setNom(string nom){
	nom_ = nom;
}

void Plat::setPrix(double prix){
	prix_ = prix;
}

//affichage
void Plat::afficher() {
	cout << nom_ << " - " << prix_ << "$ (" << cout_ 
		 << "$ pour le restaurant)" << endl;
}



