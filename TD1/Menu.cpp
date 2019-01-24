#include "Menu.h"

Menu::Menu() {
	capacite_ = MAXPLAT;
	//FINIS?
}

Menu::Menu(string fichier, TypeMenu type){
	lireMenu(fichier);
	type_ = type;
}

int Menu::getNbPlats() {
	return { (int) nbPlats_ };
}

void Menu::afficher(){
	//VOIR QUOI AFFICHER
}

Plat * Menu::trouverPlat(string & nom){
	return nullptr;
}

void Menu::ajouterPlat(Plat & plat){

}

void Menu::ajouterPlat(string & nom, double montant, double cout){

}

bool Menu::lireMenu(string & fichier){
	return false;
}
