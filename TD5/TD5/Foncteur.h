/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher {
public:
    //Constructeur
	FoncteurPlatMoinsCher() {};
	/*
	* In: 2 objets de pair d'un string et un pointeur de Plat
	* Compare le prix de ces deux plats et renvoie un "true" ou "false" si le prix du premier est plus petit que le second
	*/
	bool operator()(pair<string, Plat*>plat1, pair<string, Plat*>plat2) { //a modifier
		return { ((plat1).second->getPrix()) < ((plat2).second->getPrix()) };
	}
};


class FoncteurIntervalle {
public:
	/*
	* In: bornes superieur et inferieur
	* Constructeur par parametre
	*/
	FoncteurIntervalle(double borneInf, double borneSup) { borneInf_ = borneInf;
															borneSup_ = borneSup; };
	/*
	* In: objet de pair d'un string et un pointeur de Plat
	* Retourne "true" ou "false" si le prix du plat est entre les bornes superieur et inferieur
	*/
	bool operator() (pair<string, Plat*> p) {
		return { (p.second->getPrix() >= borneInf_) && (p.second->getPrix() <= borneSup_) };
	};

private:
	double borneInf_;
	double borneSup_;
};
