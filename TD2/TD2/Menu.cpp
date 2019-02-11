/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 11 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer un menu ainsi que ses attributs.
*/
#include "Menu.h"

//constructeurs
Menu::Menu() {
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = Matin;
}

Menu::Menu(string fichier, TypeMenu type) {
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = type;

	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

Menu::Menu(const Menu & menu)
	: capacite_(menu.capacite_), nbPlats_(menu.nbPlats_), type_(menu.type_){
	for (int i = 0; i < menu.nbPlats_; i++) {
		listePlats_.push_back(menu.listePlats_[i]);
	}
}

//destructeur
Menu::~Menu() {
	// A MODIFIER
	for (int i = 0; i < nbPlats_; i++)
		delete listePlats_[i];
	//delete[] listePlats_;
}

//getters
int Menu::getNbPlats() const {
	return nbPlats_;
}

vector<Plat*> Menu::getListePlat() const{
	return { listePlats_ };
}

//méthode en plus
bool Menu::lireMenu(const string& fichier) {
	ifstream file(fichier, ios::in);
	if (!file) {
		cout << "ERREUR : le fichier n'a pas pu etre ouvert" << endl;
		return false;
	} else {
		string type;
		switch (type_) {
		case Matin :
			type = "-MATIN";
			break;
		case Midi :
			type = "-MIDI";
			break;
		case Soir :
			type = "-SOIR";
			break;
		}
		string ligne, nom, prixString, coutString;
		double prix;
		int cout;

		// lecture
		while (!file.eof()) {
			getline(file, ligne);
			//trouver le bon type de menu (section)
			if (ligne == type){
				//commencer a lire -- s'arrete si fin du fichier ou encore si on arrive a une nouvelle section du menu
				getline(file, ligne);
				int curseur;
				while (ligne[0] != '-' && !file.eof()) {
					//trouver le nom
					for (int i = 0; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						nom += ligne[i];
					}

					//trouver le prix
					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						prixString += ligne[i];
					}

					//passer le prixString en double --- indice dans l'enonce
					prix = stof(prixString.c_str());
					for (int i = curseur + 1; i < int(ligne.size()); i++) {
						if (ligne[i] == ' ')
							break;
						coutString += ligne[i];
					}
					cout = int( stof(coutString.c_str()));
					Plat* plat = new Plat(nom, prix, cout);
					*this += plat;
					//ajouterPlat(Plat(nom, prix, cout));
					nom = "";
					prixString = "";
					coutString = "";
					getline(file, ligne);
				}
			}
		}
		file.close();
		return true;
	}
}

Plat * Menu::trouverPlatMoinsCher() const{
	Plat minimum(*listePlats_[0]);
	int found = -1;
	for (unsigned i = 0; i < listePlats_.size(); ++i){
		if (*listePlats_[i] < minimum){
			minimum = *listePlats_[i];
			found = i;
		}
	}
	return listePlats_[found];
}

void Menu::ajouterPlat(const Plat& plat){
	listePlats_.push_back(new Plat(plat));
	nbPlats_++;
}

Plat* Menu::trouverPlat(const string& nom) const {
	for (int i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}

ostream & operator<<(ostream & o, const Menu & menu){
	switch (menu.type_) {
		case Matin: 
			cout << "Menu du Matin:" << endl;
			break;
		case Midi:
			cout << "Menu du Midi:" << endl;
			break;
		case Soir:
			cout << "Menu du Soir:" << endl;
			break;
	}
	for (int i = 0; i < menu.getNbPlats(); i++) {
		cout << "\t";
		cout << *menu.listePlats_[i];
	}
	return o;
}

Menu& Menu::operator+=(Plat* plat){
	if (nbPlats_ < capacite_) {
		listePlats_.push_back(plat);
		nbPlats_++;
	} else {
		cout << "Capacité de plat atteinte!" << endl;
	}
	return *this;
}

Menu& Menu::operator=(Menu & menu){
	capacite_ = menu.capacite_;
	nbPlats_ = menu.nbPlats_;
	type_ = menu.type_;

	listePlats_.clear();
	for (int i = 0; i < menu.nbPlats_; i++) {
		listePlats_.push_back(menu.listePlats_[i]);
	}
	return *this;
}