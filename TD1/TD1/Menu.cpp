#include "Menu.h"

//constructeurs
Menu::Menu() {
	//constructeur par d�faut
	capacite_ = MAXPLAT;
	*listePlats_ = new Plat[capacite_];
	nbPlats_ = 0;
	//type_ = NULL; //le mettre � quoi?
	//FINIS?
}

Menu::Menu(string fichier, TypeMenu type){
	//constructeur avec param�tres
	lireMenu(fichier);
	type_ = type;
}

//getters
unsigned int Menu::getNbPlats() const{
	//retourne le nombre de plat dans le menu
	return { nbPlats_ };
}

//m�thodes en plus
Plat* Menu::trouverPlat(string& nom) {
	//chercher le plat dans la liste par son nom et retourn� le pointeur du plat
	for (unsigned i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom == nom) {
			return { listePlats_[i] }; //return le plat si trouver
		}
	}
	return { nullptr };	//return nullptr si le plat n'est pas trouver
}

void Menu::ajouterPlat(Plat& plat){
	if (nbPlats_ < capacite_) {
		*listePlats_[nbPlats_] = plat;
		nbPlats_++;
	} else {
		cout << "Il n'y a plus de place dans la liste de plat!" << endl;
	}
	//ajoute le plat � listePlats_ en utilisant le plat lui-m�me
}

void Menu::ajouterPlat(string& nom, double montant, double cout){
	//cr�er le plat avant de l'ajouter � la liste?
	Plat plat(nom, montant, cout);
	ajouterPlat(plat); //jpense c'est de m�me
}

bool Menu::lireMenu(string& fichier){
	//lire le fichier texte et mettre les infos dans les variables
	//ne pas oublier le type de menu (matin, midi, soir)
	ifstream source(fichier);
	if (source.fail()) {
		cout << "Echec de lecture du fichier!" << endl;
	} else {
		//j'ai pas une bonne m�thode pour bien lire le file efficacement
		switch (type_) {
			case Matin:

				break;
			case Midi:

				break;
			case Soir:

				break;
		}
		return true; //return true si le fichier a bien �tait lu
	}
	return false;	//return false si le fichier a mal �tait lu
}

//affichage
void Menu::afficher() {

	//VOIR QUOI AFFICHER
}