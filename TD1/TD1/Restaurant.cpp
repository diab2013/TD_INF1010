#include "Restaurant.h"

/*
* Constructeur par défaut de la classe Restaurant
* Le nom sera "inconnu", le moment de la journée est MATIN et le chiffre d'affaire est null
* Les menu du matin, midi et soir pointent vers rien
*/
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

/*
* Constructeur avec paramétres de la classe Restauraut
* Prend en paramètre l'adresse d'un fichier, l'addresse d'un nom et le moment de la journée (Matin, midi, soir)
* Les variables correspondantes au paramètres sont initialisées
* La liste de table est initialisé avec une capacité
* Les différents menu de la journée sont initialisés
* La fonction lireTable charge les valeurs des tables provenant du document 
*/
Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
	nom_ = new string(nom);
	momentJournee_ = moment;
	//jpense c'est de même qu'il faut faire, a reverifier
	capaciteTables_ = INTTABLES;
	tables_ = new Table*[capaciteTables_];
	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier, Midi);
	menuSoir_ = new Menu(fichier, Soir);
	lireTable(fichier);
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
}

void Restaurant::ajouterTable(int id, int nbPlaces){
	Table* temp = new Table(id, nbPlaces);
	if (nbTables_ < capaciteTables_) { //maybe utiliser INTTABLES???
		tables_[nbTables_] = new Table();
		tables_[nbTables_] = temp;
		nbTables_++;
	} else {
		cout << "La table n'a pas pu être ajouter" << endl;
	}
}

//revoir comment liberer table
void Restaurant::libererTable(int id){
	for (unsigned i = 0; i < nbTables_; i++) {
		if ((id == tables_[i]->getId()) && tables_[i]->estOccupee()) {
			cout << "table " << tables_[i]->getId() << " va etre liberer!" << endl;
			tables_[i]->libererTable();
			cout << "table liberer" << endl;
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
	if (!(platTemp == nullptr)) {
		tables_[idTable - 1]->commander(platTemp);
	} else {
		cout << "Le plat commander n'est pas disponible en ce moment de la journee!" << endl;
	}
	
}

//REVOIR CETTE FONCTION ...........
void Restaurant::placerClients(int nbClients){
	//unsigned int nbTablesOccupees = 0;
	int tableOptimale = 0;
	int minDiff = INT_MAX;
	bool peutPlacer = false;

	for (unsigned i = 0; i < nbTables_; i++) {
		if (!tables_[i]->estOccupee() && (nbClients <= tables_[i]->getNbPlaces())) {
			if (minDiff > (tables_[i]->getNbPlaces() - nbClients) && (tables_[i]->getNbPlaces() - nbClients) >= 0) {
				tableOptimale = i;
				peutPlacer = true;
			}
		}
	}
	//La méthode ne marchait pas pour tout
	/*
	for (unsigned i = 0; i < nbTables_; i++) {
		if (tables_[i]->estOccupee()) {
			nbTablesOccupees++;
			if (nbTablesOccupees == nbTables_) {
				cout << "Il n'y a pas de table disponible ..." << endl;
			}
		} else {
			if (tables_[tableOptimale]->estOccupee()) { //si tables_[0] est occupee
				tableOptimale++;
			}			
			if ((tables_[i]->getNbPlaces() < tables_[tableOptimale]->getNbPlaces()) && (nbClients <= tables_[i]->getNbPlaces())) {
				if (minDiff > (tables_[i]->getNbPlaces() - nbClients)) {
					minDiff = tables_[i]->getNbPlaces() - nbClients;
					tableOptimale = i;
				}
				peutPlacer = true;
			}
		}	
	}
	*/
	if (peutPlacer) { 
		tables_[tableOptimale]->placerClient();
		cout << "Le client à ete ajouter a la table " << tables_[tableOptimale]->getId() << " !" << endl;
	}
	//if (!peutPlacer && (nbTablesOccupees < nbTables_)) {
	//	cout << "Il n'y a pas de table ayant asser de place pour ces clients." << endl;
	//}
	if (!peutPlacer) {
		cout << "Il n'y a pas de table ayant asser de place pour ces clients." << endl;
	}
}

//affichage
void Restaurant::afficher(){
	cout << "| Bienvenue chez " << &nom_ << "! |" <<endl;
	cout << "---------------------------------------------" << endl;
	menuMatin_->afficher();
	menuMidi_->afficher();
	menuSoir_->afficher();
	for (unsigned i = 0; i < nbTables_; i++) {
		tables_[i]->afficher();
		chiffreAffaire_ += tables_[i]->getChiffreAffaire();
	}
	cout << "Le chiffre d'affaire est de " << chiffreAffaire_ << "$" << endl;
}