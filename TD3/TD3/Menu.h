/*
* Titre : Menu.h - Travail Pratique #3
* Date : 11 Février 2019
* Auteur : Fatou S. Mounzeo
*/

#ifndef MENU_H
#define MENU_H 

#include <fstream>
#include <vector>
#include"PlatBio.h"


enum TypeMenu{Matin, Midi, Soir};

class Menu {
public: 
	// constructeurs
	Menu(); 
	Menu(string fichier, TypeMenu type);
	~Menu();
	Menu(const Menu& menu);


	//getters
	vector<Plat*> getListePlats() const; 
	
	//methodes en plus
	Plat* trouverPlat(const string& nom) const; 
	Menu& operator+=(const Plat& plat); 
	Menu& operator+=(const PlatBio& plat); 
	Menu& operator=(const Menu& menu);
	void lireMenu(const string& fichier); 
	Plat* trouverPlatMoinsCher() const; 
	friend ostream& operator<<(ostream& os, const Menu& menu);
	
private : 
	vector<Plat*> listePlats_; 
	TypeMenu type_; 
};

#endif // !MENU_H
