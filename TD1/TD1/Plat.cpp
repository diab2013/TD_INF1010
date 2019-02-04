/*
* Titre : Plat.cpp - Travail Pratique #1
* Date : 04 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer un plat ainsi que ses attributs.
*/

#include "Plat.h"

/*
* Constructeur par défaut de la classe Plat
* Initialise les attributs à des valeurs par défaut
* Le nom sera "inconnu" et les prix et cout seront de zéro
*/
Plat::Plat() {
	//constructeur par défaut
	nom_ = "inconnu";
	prix_ = 0;
	cout_ = 0;
}

/*
* Constructeur par paramètre de la classe Plat
* Initialise les attributs à des valeurs passées en paramètres
*/
Plat::Plat(string nom, double prix, double cout) {
	//constructeur avec paramètres
	nom_ = nom;
	prix_ = prix;
	cout_ = cout;
}

/*
* Getter pour la variable nom_
* return l'attribut nom_ de la classe
*/
string Plat::getNom() const {
	//retourne le nom du plat
	return { nom_ };
}

/*
* Getter pour la variable prix_
* return l'attribut prix_ de la classe
*/
double Plat::getPrix() const {
	//retourne le prix du plat
	return { prix_ };
}

/*
* Getter pour la variable cout_
* return l'attribut cout_ de la classe
*/
double Plat::getCout() const {
	//retourne le cout de production du plat
	return{ cout_ };
}

/*
* Setter pour la variable nom_
* Reçoit un nom en paramètre et le set à l'attribut nom_ de la classe
*/
void Plat::setNom(string nom){
	nom_ = nom;
}

/*
* Setter pour la variable prix_
* Reçoit un prix en paramètre et le set à l'attribut prix_ de la classe
*/
void Plat::setPrix(double prix){
	//set le prix du plat
	prix_ = prix;
}

/*
* Méthode d'affichage de la classe Plat
* Affiche les attributs de l'objet lorsque la méthode est appelée
* Présente le nom, le prix et le coût du plat
*/
void Plat::afficher() const{
	cout << "\t" << nom_ << " - " << prix_ << "$ (" << cout_ 
		 << "$ pour le restaurant)" << endl;
}