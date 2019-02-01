#include "Restaurant.h"

//constructeurs
Restaurant::Restaurant(){
	//constructeur par défaut
	string nom = "inconnu";
	*nom_ = nom;
	momentJournee_ = Matin;
	chiffreAffaire_ = NULL;
	menuMatin_ = nullptr;
	menuMidi_ = nullptr;
	menuSoir_ = nullptr;
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
	nom_ = &nom;
	momentJournee_ = moment;
	//jpense c'est de même qu'il faut faire, a reverifier
	cout << "before matin" << endl;
	Menu matin(fichier, Matin);
	cout << "before" << endl;
	menuMatin_ = &matin;
	cout << "menu matin finit" << endl;
	menuMidi_ = new Menu(fichier, Midi);
	menuSoir_ = new Menu(fichier, Soir);
}

//destructeur
Restaurant::~Restaurant(){
	//je feel ca a besoin d'un destructeur
}

//setters
void Restaurant::setMoment(TypeMenu moment){
	momentJournee_ = moment;
}

//getters
string Restaurant::getNom() const{
	return *nom_;
}

TypeMenu Restaurant::getMoment() const{
	return momentJournee_;
}

//autres méthodes
void Restaurant::lireTable(string & fichier){
	ifstream lireFichier(fichier);
	string mot;
	int numeroTable = 0, id , nbPLace;
	bool renduTable = false;
	while (!renduTable) {
		lireFichier >> mot;
		if (mot == "-TABLES") {
			renduTable = true;
			while (!lireFichier.eof()) {
				lireFichier >> id >> nbPLace;
				ajouterTable(id, nbPLace);
			}
		}
	}
}

void Restaurant::ajouterTable(int id, int nbPlaces){
	Table tempTable(id, nbPlaces);
	if (nbTables_ < capaciteTables_) { //maybe utiliser INTTABLES???
		nbTables_++;
		tables_[id - 1] = &tempTable; //pcq id = position + 1
	} else {
		cout << "La table n'a pas pu être ajouter" << endl;
	}
}

void Restaurant::libererTable(int id){
	for (unsigned i = 0; i < nbTables_; i++) {
		if ((id == tables_[i]->getId()) && tables_[i]->estOccupee()) {
			tables_[i]->libererTable();
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			delete tables_[i];
			tables_[i] = nullptr;
		}
	}
}

void Restaurant::commanderPlat(string& nom, int idTable){
	Plat* platTemp = nullptr;
	switch(momentJournee_) {
		case Matin:
			platTemp = menuMatin_->trouverPlat(nom);
			break;
		case Midi:
			platTemp = menuMidi_->trouverPlat(nom);
			break;
		case Soir:
			platTemp = menuSoir_->trouverPlat(nom);
			break;
	}
	tables_[idTable - 1]->commander(platTemp);//maybe???
	cout << "le plat " << nom << " a été commande pour la table " << idTable << endl;
}

void Restaurant::placerClients(int nbClients){
	unsigned int nbTablesOccupees = 0;
	int tableOptimale = 0;
	bool peutPlacer = false;

	for (unsigned i = 0; i < nbTables_; i++) {
		if (tables_[i]->estOccupee()) {
			nbTablesOccupees++;
			if (nbTablesOccupees == nbTables_) {
				cout << "Il n'y a pas de places disponible" << endl;
			}
		}
		else {
			while (tables_[tableOptimale]->estOccupee()) { //si tables_[0] est occupee
				tableOptimale++;
			}			
			if ((tables_[i]->getNbPlaces() < tables_[tableOptimale]->getNbPlaces()) && (nbClients <= tables_[i]->getNbPlaces())) {
				tableOptimale = i;
				peutPlacer = true;
			}
		}	
	}
	if (peutPlacer) { 
		tables_[tableOptimale]->placerClient();
		cout << "Le client à ete ajouter!" << endl;
	}
	if (!peutPlacer && (nbTablesOccupees < nbTables_)) {
		cout << "Il n'y a pas de table ayant asser de place pour ces clients." << endl;
	}
}

//affichage
void Restaurant::afficher(){
	for (unsigned i = 0; i < nbTables_; i++) {
		tables_[i]->afficher();
	}
}