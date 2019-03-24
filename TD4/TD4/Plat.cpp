/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/

#include "Plat.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"
//#include "debogageMemoire.hpp"
using namespace std;

/*
 * Constructeurs par param�tres de la classe Plat
 * IN: 
*/
Plat::Plat(string_view nom, double prix, double cout) : nom_(nom), prix_(prix), cout_(cout) {
}

/*
 * Destructeur de la classe Plat
*/
Plat::~Plat() {
}

//getters 
/*
 * Getter de l'attribut nom_
 * OUT: return l'attribut nom_ de l'objet
*/
string Plat::getNom() const {
	return nom_;
}

/*
 * Getter de l'attribut prix_
 * OUT: return l'attribut prix_ de l'objet
*/
double Plat::getPrix() const {
	return prix_;
}

/*
 * Getter de l'attribut cout_
 * OUT: return l'attribut cout_ de l'objet
*/
double Plat::getCout() const {
	return cout_;
}

//setters 
/*
 * Setter de l'attribut nom_
 * IN: nouvelle valeur pour l'attribut nom_
*/
void Plat::setNom(string nom) {
	nom_ = nom;
}

/*
 * Setter de l'attribut prix_
 * IN: nouvelle valeur de l'attribut prix_
*/
void Plat::setPrix(double prix) {
	prix_ = prix;
}

/*
 * Getter du profit fait avec le plat
 * OUT: return le profit fait avec le plat en fesant le
 *		prix moins le cout du plat
*/
double Plat::getPrixRevient() {
	return prix_ - cout_;
}

//Autres m�thodes
/*
 * Override de l'op�rateur < pour la comparaison de plat
 * IN: la r�f�rence du plat avec lequelle on compare le prix de l'objet actuel
*/
bool Plat::operator < (const Plat& plat) const {
	return this->prix_ < plat.prix_;
}

/*
 * M�thode pour l'affichage des attributs du plat
 * IN: la r�f�rence � un ostream pour l'affichage
*/
void Plat::afficherPlat(ostream & os) const {
	os << "PLAT ----" << nom_ << " - " << prix_ << " $ (" << cout_ << "$ pour le restaurant)" << endl;
}

/*
 * M�thode pour returner un clone de l'objet actuel
 * OUT: une r�f�rence vers un clone du Plat
*/
Plat*  Plat:: clone () const { 
	 Plat* plat = new Plat(*this);
	 return plat;
}
