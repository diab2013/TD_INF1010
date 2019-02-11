/*
* Titre : Plat.cpp - Travail Pratique #2
* Date : 11 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer un plat ainsi que ses attributs.
*/

#include "Plat.h"

/*
* Constructeur par d�faut de la classe Plat
* Initialise les attributs � des valeurs par d�faut
* Le nom sera "inconnu" et les prix et cout seront de z�ro
*/
Plat::Plat() {
	nom_ = "Inconnu";
	prix_ = 0;
	cout_ = 0;
}

/*
* Constructeur par param�tre de la classe Plat
* Initialise les attributs � des valeurs pass�es en param�tres
*/
Plat::Plat(string nom, double prix, double cout) {
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

/*
* Getter pour la variable nom_
* return l'attribut nom_ de la classe
*/
string Plat::getNom() const {
	return nom_;
}

/*
* Getter pour la variable prix_
* return l'attribut prix_ de la classe
*/
double Plat::getPrix() const {
	return prix_;
}

/*
* Getter pour la variable cout_
* return l'attribut cout_ de la classe
*/
double Plat::getCout() const {
	return cout_;
}


/*
* Setter pour la variable nom_
* Re�oit un nom en param�tre et le set � l'attribut nom_ de la classe
*/
void Plat::setNom(string nom) {
	nom_ = nom;
}

/*
* Setter pour la variable prix_
* Re�oit un prix en param�tre et le set � l'attribut prix_ de la classe
*/
void Plat::setPrix(double prix) {
	prix_ = prix;
}

/*
* In/out: stream de l'output 
* In: Plat a afficher
* Out: String contenant tous les informations d'un plat
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream & operator<<(ostream & o, const Plat & plat){
	return o << plat.nom_ << " - " << plat.prix_ << " $ (" << plat.cout_ 
			 << "$ pour le restaurant)" << endl;
}

/*
* In: Deux plats differents
* Out: True si le plat a est plus petit, false s'il ne l'est pas
* Surcharge de l'operateur <. Compare les deux plats recus.
*/
bool operator<(const Plat & a, const Plat & b){
	if (a.getPrix() < b.getPrix()) {
		return true;
	} else {
		return false;
	}
}
