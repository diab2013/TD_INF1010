/*
* Titre : Menu.cpp - Travail Pratique #1
* Date : 04 Fevrier 2019
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
	listePlats_ = new Plat*[capacite_];
}

/*
* Constructeur par param�tre de la classe Menu
* Initialise les attributs � des valeurs pass�es en param�tres
* Aussi, fait appelle � la m�thode lireMenu
*/
Menu::Menu(string fichier, TypeMenu type){
	type_ = type;
	capacite_ = MAXPLAT;
	nbPlats_ = 0;
	listePlats_ = new Plat*[capacite_];
	lireMenu(fichier);
}

/*
* Getter de la variable nbPlats_
* Return l'attributs nbPlats_ de la classe
*/
unsigned int Menu::getNbPlats() const{
	return { nbPlats_ };
}

/*
* M�thode qui permet de trouver un certain plat dans la liste dynamique
* de plat selon un variable nom pass�e en param�tre
* return un pointeur vers le plat s'il a �t� trouver, sinon return nullptr
*/
Plat* Menu::trouverPlat(string& nom) {
	//chercher le plat dans la liste par son nom et retourn� le pointeur du plat
	for (unsigned i = 0; i < nbPlats_; i++) {
		if (listePlats_[i]->getNom() == nom) {
			return { listePlats_[i] }; //return le plat si trouver
		}
	}
	return { nullptr };	//return nullptr si le plat n'est pas trouver
}

/*
* M�thode qui permet d'ajouter un plat, pass� en param�tre, � la liste de plat listePlats_
* si le nombre de plat n'a pas atteint la capacit� maximale
* Le param�tre pass� est l'adresse d'un plat d�j� cr��
*/
void Menu::ajouterPlat(Plat& plat){
	if (nbPlats_ <= capacite_) {
		listePlats_[nbPlats_] = new Plat();
		*listePlats_[nbPlats_] = plat;
		nbPlats_++;
	} else {
		cout << "Il n'y a plus de place dans la liste de plat!" << endl;
	}
}

/*
* M�thode qui permet d'ajouter un plat � la liste, mais cette fois-ci en passant le nom, le
* montant et le cout en param�tre
* Les param�tres sont utilis�s pour cr�er un plat et ensuite le passer � la premi�re m�thode 
* ajouterPlat pour l'ajouter � la liste
*/
void Menu::ajouterPlat(string& nom, double montant, double cout){
	//cr�er le plat avant de l'ajouter � la liste?
	Plat plat(nom, montant, cout);
	ajouterPlat(plat); //jpense c'est de m�me
}

/*
* M�thode qui permet de lire le fichier, pass� en param�tre, contenant les menus selon chaque moment 
* de la journ�e et les tables du restaurant
* return true/false si l'ouverture du fichier � �t� possible
*/
bool Menu::lireMenu(string& fichier){
	//lire le fichier texte et mettre les infos dans les variables
	//ne pas oublier le type de menu (matin, midi, soir)
	bool renduMenu;
	ifstream source(fichier);
	if (source.fail()) {
		cout << "Echec de lecture du fichier!" << endl;
	} else {
		//j'ai pas une bonne m�thode pour bien lire le file efficacement
		switch (type_) {
			case Matin:
				while (!ws(source).eof()) {
					string mot;
					source >> mot;
					if (mot == "-MATIN") {
						while (mot != "-MIDI") {
							string mot;
							double montantPlat, coutPlat;
							source >> mot >> montantPlat >> coutPlat;
							if (mot == "-MIDI") {
								return true;
							}
							ajouterPlat(mot, montantPlat, coutPlat);
						}
					}
				}
				break;	
			case Midi:
				while (!ws(source).eof()) {
					string mot;
					source >> mot;
					if (mot == "-MIDI") {
						while (mot != "-SOIR") {
							string mot;
							double montantPlat, coutPlat;
							source >> mot >> montantPlat >> coutPlat;
							if (mot == "-SOIR") {
								return true;
							}
							ajouterPlat(mot, montantPlat, coutPlat);
						}
					}
				}
				break;
			case Soir:
				while (!ws(source).eof()) {
					string mot;
					source >> mot;
					if (mot == "-SOIR") {
						while (mot != "-TABLES") {
							string mot;
							double montantPlat, coutPlat;
							source >> mot >> montantPlat >> coutPlat;
							if (mot == "-TABLES") {
								return true;
							}
							ajouterPlat(mot, montantPlat, coutPlat);
						}
					}
				}
				break;
		}
		return true; //return true si le fichier a bien �tait lu
	}
	return false;	//return false si le fichier a mal �tait lu
}

/*
* M�thode d'affichage de la classe Menu
* Affiche les attributs de l'objet lorsque la m�thode est appel�e
* Pr�sente le moment de la journ�e, et les plats selon ce dernier
*/
void Menu::afficher() {
	switch (type_) {
		case Matin:
			cout << "Voici le menu du MATIN :" << endl;
			break;
		case Midi:
			cout << "Voici le menu du MIDI :" << endl;
			break;
		case Soir:
			cout << "Voici le menu du SOIR :" << endl;
			break;
	}
	for (unsigned i = 0; i < nbPlats_; i++) {
		listePlats_[i]->afficher();
	}
	cout << "---------------------------------------------" << endl;
}