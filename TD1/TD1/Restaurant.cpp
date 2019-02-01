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
	capaciteTables_ = INTTABLES;
	tables_ = new Table*[capaciteTables_];
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
	nom_ = &nom;
	momentJournee_ = moment;
	//jpense c'est de même qu'il faut faire, a reverifier
	capaciteTables_ = INTTABLES;
	tables_ = new Table*[capaciteTables_];
	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier, Midi);
	menuSoir_ = new Menu(fichier, Soir);
	lireTable(fichier);
	afficher();
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
	
	bool renduTable = false;
	while (!renduTable) {
		lireFichier >> mot;
		if (mot == "-TABLES") {
			renduTable = true;
			while (!lireFichier.eof()) {
				int id, nbPlace;
				lireFichier >> id >> nbPlace;
				ajouterTable(id, nbPlace);
			}
		}
	}
	cout << "toute les tables ajoutes " << endl;
}

void Restaurant::ajouterTable(int id, int nbPlaces){
	Table tempTable(id, nbTables_);
	Table* temp = &tempTable;
	//tempTable.afficher();
	if (nbTables_ < capaciteTables_) { //maybe utiliser INTTABLES???
		tables_[nbTables_] = new Table();
		tables_[nbTables_] = temp;
		nbTables_++;
		cout << "table ajouter" << endl;
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
	Plat* platTemp = new Plat();
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
	tables_[idTable]->commander(platTemp);//maybe???
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
		} else {
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