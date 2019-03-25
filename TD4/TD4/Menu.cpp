/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/

#include "Menu.h"
#include "LectureFichierEnSections.h"
#include <cassert>  //? Contient "assert" qui permet de s'assurer qu'une expression est vraie, et terminer le programme avec un message d'erreur en cas contraire.
using namespace std;

// Constructeurs.
/*
 * Conctructeur par d�faut de la classe
*/
Menu::Menu() :
	type_{TypeMenu::Matin}
{
}

/*
 * Constructeur par param�tres de la classe
 * IN:
*/
Menu::Menu(string fichier, TypeMenu type) :
	type_{type} {
	lireMenu(fichier); 
}

/*
 * Destructeur de la classe
*/
Menu::~Menu(){
	//jpenses
	listePlats_.clear();
	listePlatsVege_.clear();
}

Plat* Menu::allouerPlat(Plat* plat) {
    return plat->clone();
}

/*
 * Constructeur par copie de la classe
*/
Menu::Menu(const Menu & menu) : type_(menu.type_){
	//vraiment pas sure
	for (unsigned i = 0; i < menu.listePlats_.size(); i++) {
		listePlats_.push_back(menu.listePlats_[i]);
	}
	for (unsigned i = 0; i < menu.listePlatsVege_.size(); i++) {
		listePlatsVege_.push_back(menu.listePlatsVege_[i]);
	}
}

/*
 * Override de l'op�rateur = 
 * IN: r�f�rence du menu dont les attributs seront copi�s
*/
Menu & Menu::operator=(const Menu & menu) {
	//je pense vraimentpas mais a revoir
	if (this != &menu) {
		this->type_ = menu.type_;
		listePlats_.clear();
		listePlatsVege_.clear();

		for (unsigned i = 0; i < menu.listePlats_.size(); i++) {
			listePlats_.push_back(allouerPlat(menu.listePlats_[i]));
		}
		for (unsigned i = 0; i < menu.listePlatsVege_.size(); i++) {
		}
	}
	return *this;
}

// Getters.
/*
 * Getter de l'attribut listePlats_
 * OUT: return l'attribut listePlats_ de l'objet
*/
vector<Plat*> Menu::getListePlats() const{
	return listePlats_;
}

// Autres methodes.
/*
 * Override de l'op�rateur +=
 * IN: la r�f�rence du plat que l'on ajoute � la liste
*/
Menu& Menu::operator+=(owner<Plat*> plat) {
	listePlats_.push_back(plat);
	if (typeid(*plat).name() == typeid(PlatVege).name()) {
		listePlatsVege_.push_back((PlatVege*) plat);
	} else if (typeid(*plat).name() == typeid(PlatBioVege).name()) {
		listePlatsVege_.push_back((PlatBioVege*)plat);
	}
	return *this;
}

/*
 * M�thode pour lire les menu du fichier
 * IN: le nom du fichier que l'on va lire
*/
void Menu::lireMenu(const string& nomFichier) {
	LectureFichierEnSections fichier{nomFichier};
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type_)]);
	while (!fichier.estFinSection())
		*this += lirePlatDe(fichier);
}

/*
 * M�thode pour trouver le plat le moins cher
 * Traverse la liste de plats et trouve le plat le moins cher
*/
Plat* Menu::trouverPlatMoinsCher() const{
	assert(!listePlats_.empty() && "La liste de plats de doit pas etre vide pour trouver le plat le moins cher.");
	Plat* minimum = listePlats_[0];
	for (Plat* plat : listePlats_)
		if (*plat < *minimum)
			minimum = plat;

	return minimum;
}

/*
 * M�thode pour trouver un plat selon avec l'aide de son nom
 * On cherche un plat dans la liste par son nom
 * IN: un nom de type string que l'on cherche dans la liste
*/
Plat* Menu::trouverPlat(string_view nom) const{
	for (Plat* plat : listePlats_)
		if (plat->getNom() == nom)
			return plat; 

	return nullptr; 
}

/*
 * M�thode pour lire les plats d'un fichier
 * IN: fichier lu par la m�thode
*/
Plat* Menu::lirePlatDe(LectureFichierEnSections& fichier){
    auto lectureLigne = fichier.lecteurDeLigne();
    
    string nom, typeStr;
    TypePlat type;
    double prix, coutDeRevient;
    lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
    type = TypePlat(stoi(typeStr));
    double ecotaxe, vitamines, proteines, mineraux;
    switch (type) {
        case TypePlat::Bio :
            lectureLigne >> ecotaxe;
            return new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
        case TypePlat::BioVege:
            lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
            return new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
        case TypePlat::Vege:
            lectureLigne >> vitamines >> proteines >> mineraux;
            return new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
        default:
            return new Plat{nom, prix, coutDeRevient};
    }
}

// Fonctions globales.
/*
 * Override de l'op�rateur <<
 * Permet l'affichage des attributs de la classe menu
 * IN: r�f�rence d'un ostream pour l'affichage
 *	   r�f�rence du menu dont les attributs seront affich�s
*/
ostream& operator<<(ostream& os, const Menu& menu){
	for (unsigned i = 0; i < menu.listePlats_.size(); i++) {
		menu.listePlats_[i]->afficherPlat(os);
	}
	os << endl;
	os << "MENU ENTIEREMENT  VEGETARIEN" << endl;
	for (unsigned i = 0; i < menu.listePlatsVege_.size(); i++) {
		menu.listePlatsVege_[i]->afficherVege(os);
	}
	return os;
}
