/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"

Table * GestionnaireTables::getTable(int id) const{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if ((*it)->getId() == id) {
			return (*it);
		}
	}
	return nullptr;
}

Table * GestionnaireTables::getMeilleureTable(int tailleGroupe) const{
	Table* meilleurTable = nullptr;
	bool tableTrouvee = false;
	
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if (!((*it)->estOccupee()) && ((*it)->getNbPlaces() >= tailleGroupe)) {
			meilleurTable = (*it);
			tableTrouvee = true;
		}
	}

	if (!tableTrouvee) {
		return nullptr;
	}

	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if ( ((*it)->getNbPlaces() < meilleurTable->getNbPlaces()) 
			 && !(*it)->estOccupee()
			 && ((*it)->getNbPlaces() >= tailleGroupe) ) {
			meilleurTable = (*it);
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

GestionnaireTables& GestionnaireTables::operator+=(Table* table) {
	ajouter(table);
	return *this;
}

void GestionnaireTables::afficherTables(ostream & os) const{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		os << (*it);
	}
}
