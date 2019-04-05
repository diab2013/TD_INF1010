/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"



/*
* In: nom du fichier de lecture et type du menu
* Constructeur de GestionnairePlats. Lit un fichier de plat selon le type de menu.
*/
GestionnairePlats::GestionnairePlats(const string & nomFichier, TypeMenu type) : type_(type) {
	lirePlats(nomFichier, type);
}

//
/*
* In: Pointeur vers un GestionnairePlats
* Constructeur par copie. "Clear" le conteneur du gestionnaire a copier et met le contenu de ce dernier dans un autre objet de conteneur
*/
GestionnairePlats::GestionnairePlats(GestionnairePlats * gestionnaire) {
	this->conteneur_.clear();

	type_ = gestionnaire->type_;
	copy(gestionnaire->conteneur_.begin(), gestionnaire->conteneur_.end(), conteneur_.begin());
	for (auto it = gestionnaire->conteneur_.begin(); it != gestionnaire->conteneur_.end(); it++) {
		ajouter(make_pair(it->first, allouerPlat(it->second)));
	}

}

//Destructeur
GestionnairePlats::~GestionnairePlats() {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		delete(it->second);
	}

}

TypeMenu GestionnairePlats::getType() const {
	return { type_ };
}

Plat * GestionnairePlats::allouerPlat(Plat * plat) {
	return { new Plat(*plat) };
}

Plat* GestionnairePlats::trouverPlatMoinsCher() const { //a revoir
	return { min_element(conteneur_.begin(), conteneur_.end(), FoncteurPlatMoinsCher())->second };
}

//pas fait par nous
void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type) {
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

//pas fait par nous
pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier) {
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}


