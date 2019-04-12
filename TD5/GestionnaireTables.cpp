/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"

/*
* In: id d'une table
* Out: Pointeur vers un objet Table
* Utilise un iterateur pour parcourir le conteneur afin de trouver un objet Table ayant un certain id
*/
Table * GestionnaireTables::getTable(int id) const{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if ((*(it))->getId() == id) {
			return (*(it));
		}
	}
	return nullptr;
}

/*
* In: taille du groupe de client
* Out: Pointeur vers un objet Table
* Utilise un iterateur pour parcourir le conteneur afin de trouver un objet Table
  ayant une capacite optimisee pour la taille du groupe de client
*/
Table * GestionnaireTables::getMeilleureTable(int tailleGroupe) const{
	Table* meilleurTable = nullptr;
	bool tableTrouvee = false;
	
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if (!((*(it))->estOccupee()) && ((*(it))->getNbPlaces() >= tailleGroupe)) {
			meilleurTable = (*it);
			tableTrouvee = true;
		}
	}

	if (!tableTrouvee) {
		return nullptr;
	}

	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if ( ((*(it))->getNbPlaces() < meilleurTable->getNbPlaces()) 
			 && !(*(it))->estOccupee()
			 && ((*(it))->getNbPlaces() >= tailleGroupe) ) {
			meilleurTable = (*(it));
		}
	}

	return meilleurTable;
}

// pas nous
void GestionnaireTables::lireTables(const string& nomFichier){
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		ajouter(new Table(id, nbPlaces));
	}
}

/*
* In: Pointeur vers un objet Table
* Out: Pointeur vers un objet Table
* Override de l'operateur +=. Ajoute un objet Table au conteneur.
*/
GestionnaireTables& GestionnaireTables::operator+=(Table* table) {
	ajouter(table);
	return *this;
}

/*
* In/Out: Variable ostream
* Affiche tous les elements du conteneur de tables
*/
void GestionnaireTables::afficherTables(ostream & os) const{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		os << (*(it));
	}
}
