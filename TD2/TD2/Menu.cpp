/*
* Titre : Menu.cpp - Travail Pratique #2
* Date : 11 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer un menu ainsi que ses attributs.
*/
#include "Menu.h"

/*
* Constructeur par d�faut de la classe Menu
* Cr�e une nouvelle liste de plat vide avec une capacit� de MAXPLAT
* Le nombre de plat est z�ro et le type de menu est Matin
*/
Menu::Menu() {
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = Matin;
}

/*
* Constructeur par param�tre de la classe Menu
* Initialise les attributs � des valeurs pass�es en param�tres
* Aussi, fait appelle � la m�thode lireMenu
*/
Menu::Menu(string fichier, TypeMenu type) {
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	type_ = type;

	//lecture du fichier -- creation du menu
	lireMenu(fichier);
}

/*
* In: Variable de type Menu
* Creer un objet Menu ayant les memes attributs que ce menu-ci
* et ajoute ses plats dans le vecteur de plats
*/
Menu::Menu(const Menu & menu)
	: capacite_(menu.capacite_), nbPlats_(menu.nbPlats_), type_(menu.type_){
	for (int i = 0; i < menu.nbPlats_; i++) {
		listePlats_.push_back(menu.listePlats_[i]);
	}
}

//destructeur de la classe
Menu::~Menu() {
	// A MODIFIER
	for (int i = 0; i < nbPlats_; i++)
		delete listePlats_[i];
	//delete[] listePlats_;
}

/*
* Getter de la variable nbPlats_
* Return l'attributs nbPlats_ de la classe
*/
int Menu::getNbPlats() const {
	return nbPlats_;
}

/*
* Methode qui return le vecteur de la liste de plats
*/
vector<Plat*> Menu::getListePlat() const{
	return { listePlats_ };
}

/*
* In: Nom du fichier de lecture
* M�thode qui permet de lire le fichier, pass� en param�tre, contenant les menus selon chaque moment
* de la journ�e et les tables du restaurant
* return true/false si l'ouverture du fichier � �t� possible
*/
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

/*
* M�thode qui permet de trouver le plat le moins cher dans 
*la liste dynamique de plat. 
* return un pointeur vers le plat le moins cher
*/
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

/*
* In: plat a ajouter
* M�thode qui permet d'ajouter un plat � la liste, mais cette fois-ci en passant le nom, le
* montant et le cout en param�tre
* Les param�tres sont utilis�s pour cr�er un plat et ensuite le passer � la premi�re m�thode
* ajouterPlat pour l'ajouter � la liste
*/
void Menu::ajouterPlat(const Plat& plat){
	listePlats_.push_back(new Plat(plat));
	nbPlats_++;
}

/*
* In: nom du plat a trouver
* M�thode qui permet de trouver un certain plat dans la liste dynamique
* de plat selon un variable nom pass�e en param�tre
* return un pointeur vers le plat s'il a �t� trouver, sinon return nullptr
*/
Plat* Menu::trouverPlat(const string& nom) const {
	for (int i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom() == nom)
			return listePlats_[i];
	}
	return nullptr;
}

/*
* In/out: stream de l'output
* In: Menu a afficher
* Out: string contenant les informations du menu
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
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

/*
* In: Menu a ajouter
* Out: Return la reference au menu modifie
* Surcharge de l'operateur +=. Ajoute un plat dans la liste de plat.
*/
Menu& Menu::operator+=(Plat* plat){
	if (nbPlats_ < capacite_) {
		listePlats_.push_back(plat);
		nbPlats_++;
	} else {
		cout << "Capacit� de plat atteinte!" << endl;
	}
	return *this;
}

/*
* In: Menu a copier
* Out: Return la reference au menu copie
* Surcharge de l'operateur =. Copie le menu dans un autre objet.
*/
Menu& Menu::operator=(Menu & menu){
	capacite_ = menu.capacite_;
	nbPlats_ = menu.nbPlats_;
	type_ = menu.type_;

	listePlats_.clear();
	cout << "copie des plats" << endl;
	for (int i = 0; i < menu.nbPlats_; i++) {
		listePlats_.push_back(menu.listePlats_[i]);
	}
	return *this;
}