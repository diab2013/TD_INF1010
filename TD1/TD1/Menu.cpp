#include "Menu.h"

//constructeurs
Menu::Menu() {
	//constructeur par d�faut
	capacite_ = MAXPLAT;
	//FINIS?
}

Menu::Menu(string fichier, TypeMenu type){
	//constructeur avec param�tres
	lireMenu(fichier);
	type_ = type;
}

//getters
int Menu::getNbPlats() {
	//retourne le nombre de plat dans le menu
	return { (int) nbPlats_ };
}

//m�thodes en plus
Plat * Menu::trouverPlat(string& nom) {
	//chercher le plat dans la liste par son nom et retourn� le pointeur du plat
	//if (found) {
		return { /*plat*/ };
	//} else {
		return { nullptr };	//return nullptr si le plat n'est pas trouver
	//}
}

void Menu::ajouterPlat(Plat& plat){
	//ajoute le plat � listePlats_ en utilisant le plat lui-m�me
}

void Menu::ajouterPlat(string& nom, double montant, double cout){
	//cr�er le plat avant de l'ajouter � la liste?
	Plat plat(nom, montant, cout); //?
	ajouterPlat(plat); //?
}

bool Menu::lireMenu(string& fichier){
	//lire le fichier texte et mettre les infos dans les variables
	//ne pas oublier le type de menu (matin, midi, soir)
	ifstream source(fichier);
	//....
	return false;
}

//affichage
void Menu::afficher() {
	//VOIR QUOI AFFICHER
}