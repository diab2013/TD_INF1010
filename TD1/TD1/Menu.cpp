#include "Menu.h"

//constructeurs
Menu::Menu() {
	//constructeur par défaut
	capacite_ = MAXPLAT;
	Plat* liste = new Plat[capacite_];
	listePlats_ = &liste;
	nbPlats_ = 0;
	//FINIS?
}

Menu::Menu(string fichier, TypeMenu type){
	//constructeur avec paramètres
	type_ = type;
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	Plat* liste[MAXPLAT];
	listePlats_ = liste;
	lireMenu(fichier);
	string nom = "Pain";
	trouverPlat(nom)->afficher();
	cout << "fin menu" << endl;
}

//getters
unsigned int Menu::getNbPlats() const{
	//retourne le nombre de plat dans le menu
	return { nbPlats_ };
}

//méthodes en plus
Plat* Menu::trouverPlat(string& nom) {
	//chercher le plat dans la liste par son nom et retourné le pointeur du plat
	for (unsigned i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom() == nom) { //maybe changer le & de place
			return { listePlats_[i] }; //return le plat si trouver
		}
	}
	return { nullptr };	//return nullptr si le plat n'est pas trouver
}

void Menu::ajouterPlat(Plat& plat){
	cout << plat.getNom() << endl;
	if (nbPlats_ <= capacite_) {
		listePlats_[nbPlats_] = &plat;
		nbPlats_++;
	} else {
		cout << "Il n'y a plus de place dans la liste de plat!" << endl;
	}
	//ajoute le plat à listePlats_ en utilisant le plat lui-même
}

void Menu::ajouterPlat(string& nom, double montant, double cout){
	//créer le plat avant de l'ajouter à la liste?
	Plat plat(nom, montant, cout);
	ajouterPlat(plat); //jpense c'est de même
}

bool Menu::lireMenu(string& fichier){
	//lire le fichier texte et mettre les infos dans les variables
	//ne pas oublier le type de menu (matin, midi, soir)
	string mot, nomPlat;
	double montantPlat, coutPlat;
	bool renduMenu;
	ifstream source(fichier);
	if (source.fail()) {
		cout << "Echec de lecture du fichier!" << endl;
	} else {
		//j'ai pas une bonne méthode pour bien lire le file efficacement
		switch (type_) {
			case Matin:
				cout << "we matin" << endl;
				renduMenu = false;
				while (!renduMenu) {
					source >> mot;
					if (mot == "-MATIN") {
						renduMenu = true;
						while (nomPlat != "-MIDI") {
							cout << "nomPlat = " << nomPlat << endl;
							source >> nomPlat >> montantPlat >> coutPlat;
							ajouterPlat(nomPlat, montantPlat, coutPlat);
						}
					}
				}
				cout << "we matin done" << endl;
				break;
			case Midi:
				cout << "we midi" << endl;
				renduMenu = false;
				while (!renduMenu) {
					source >> mot;
					if (mot == "-MIDI") {
						renduMenu = true;
						while (nomPlat != "-SOIR") {
							source >> nomPlat >> montantPlat >> coutPlat;
							ajouterPlat(nomPlat, montantPlat, coutPlat);
						}
					}
				}
				cout << "we matin done" << endl;
				break;
			case Soir:
				cout << "we soir" << endl;
				renduMenu = false;
				while (!renduMenu) {
					source >> mot;
					if (mot == "-SOIR") {
						renduMenu = true;
						while (nomPlat != "-TABLES") {
							source >> nomPlat >> montantPlat >> coutPlat;
							ajouterPlat(nomPlat, montantPlat, coutPlat);
						}
					}
				}
				cout << "we soir done" << endl;
				break;
		}
		return true; //return true si le fichier a bien était lu
	}
	return false;	//return false si le fichier a mal était lu
}

//affichage
void Menu::afficher() {

	//VOIR QUOI AFFICHER
}