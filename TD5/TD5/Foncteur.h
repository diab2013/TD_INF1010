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
	FoncteurPlatMoinsCher() {};

	bool operator()(pair<string, Plat*>plat1, pair<string, Plat*>plat2) { //a modifier
		return { ((plat1).second->getPrix()) < ((plat2).second->getPrix()) };
	}
    
};

class FoncteurIntervalle {
   // TODO
};

