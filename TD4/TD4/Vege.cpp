/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "Vege.h"

/* 
 * Constructeurs par paramètre de la classe Vege
 * IN: string nom 
 * 
*/
Vege::Vege(string nom, double vitamines, double proteines, double mineraux): nom_(nom),vitamines_(vitamines), proteines_(proteines), mineraux_(mineraux) {
}

/*
* Getter de l'attribut vitamines_
* OUT: return l'attribut vitamines_ de l'objet
*/
double Vege::getVitamines() {
	return vitamines_;
}

/*
 * Getter de l'attribut proteines_
 * OUT: return l'attribut proteines_ de l'objet
 */
double Vege::getProteines() {
	return proteines_;
}

/*
 * Getter de l'attribut mineraux_
 * OUT: return l'attribut mineraux_ de l'objet
*/
double Vege::getMineraux() {
	return mineraux_;
}

/*
 * Setter de l'attribut vitamines_
 * IN: nouvelle valeur pour l'attribut vitamines_
*/
void Vege::setVitamines(double vitamines) {
	vitamines_ = vitamines;
}

/*
 * Setter de l'attribut proteines_
 * IN: nouvelle valeur pour l'attribut proteines
*/
void Vege::setProteines(double proteines) {
	proteines_ = proteines;
}

/*
 * Setter de l'attribut mineraux_
 * IN: nouvelle valeur pour l'attribut mineraux_
*/
void Vege::setMineraux(double mineraux) {
	mineraux_ = mineraux;
}

/*
 *  Méthode d'affichage pour d'un objet Vege
 * IN: la référence d'un ostream pour l'affichage
*/
void Vege::afficherVege(ostream & os) const {
	os << "PLAT VEGE " << nom_ << " vitamines " << vitamines_ << " Proteines " << proteines_ << " Mineraux " << mineraux_ << endl;
}
