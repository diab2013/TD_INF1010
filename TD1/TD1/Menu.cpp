#include "Menu.h"

//constructeurs
Menu::Menu() {
	//constructeur par défaut
	capacite_ = MAXPLAT;
	//FINIS?
}

Menu::Menu(string fichier, TypeMenu type){
	//constructeur avec paramètres
	lireMenu(fichier);
	type_ = type;
}

//getters
int Menu::getNbPlats() {
	//retourne le nombre de plat dans le menu
	return { (int) nbPlats_ };
}

//méthodes en plus
Plat * Menu::trouverPlat(string& nom) {
	//chercher le plat dans la liste par son nom et retourné le pointeur du plat
	//if (found) {
		return { /*plat*/ };
	//} else {
		return { nullptr };	//return nullptr si le plat n'est pas trouver
	//}
}

void Menu::ajouterPlat(Plat& plat){
	//ajoute le plat à listePlats_ en utilisant le plat lui-même
}

void Menu::ajouterPlat(string& nom, double montant, double cout){
	//créer le plat avant de l'ajouter à la liste?
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