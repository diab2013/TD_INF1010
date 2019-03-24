/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#include "PlatBio.h"

/*
 * Constructeur par param�tres de la classe PlatBio
 * IN:
*/
PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe)
	: Plat(nom, prix, cout), ecoTaxe_(ecotaxe) {
}

/*
 * Destructeur de la classe PlatBio
*/
PlatBio::~ PlatBio(){}

/*
 * Getter de l'attribut ecoTaxe_
 * OUT: return l'attribut ecoTaxe_ de l'objet
*/
double PlatBio::getEcoTaxe() const {
	return ecoTaxe_;
}

/*
 * Setter de l'attribut ecoTaxe_
 * IN: nouvelle valeur pour l'attribut ecoTaxe_
*/
void PlatBio::setEcoTaxe(double ecoTaxe) {
	ecoTaxe_ = ecoTaxe;
}

/*
 * M�thode pour returner un clone de l'objet actuel
 * OUT: une r�f�rence vers un clone du PlatBio
*/
Plat * PlatBio:: clone () const {
	PlatBio* platBio = new PlatBio(*this);
	return platBio;
}

/*
 * Getter du profit fait avec le plat bio
 * OUT: return le profit fait avec le plat en fesant le
 *		prix moins le cout plus la taxe ecologique du plat bio
*/
double PlatBio::getPrixDeRevient() const {
	return { prix_ - cout_ + ecoTaxe_ };
}

/*
 * M�thode pour l'affichage des attributs du plat bio
 * IN: la r�f�rence � un ostream pour l'affichage
*/
void PlatBio::afficherPlat(ostream& os) const {
	((Plat)*this).afficherPlat(os);	
	os << "Plat Bio     comprend une taxe ecologique de :" << ecoTaxe_ << "$" << endl;
}
