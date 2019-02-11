/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 11 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer un restaurant ainsi que ses attributs.
*/

#include "Restaurant.h"

//constructeurs
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);

	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
}

Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom);

	chiffreAffaire_ = 0;

	momentJournee_ = moment;

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);

	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
	
	lireTable(fichier);
}

Restaurant::Restaurant(const Restaurant& resto){
	menuMatin_ = new Menu(*resto.menuMatin_);
	menuMidi_ = new Menu(*resto.menuMidi_);
	menuSoir_ = new Menu(*resto.menuSoir_);
	nom_ = new string(*resto.nom_);
	chiffreAffaire_ = resto.chiffreAffaire_;
	momentJournee_ = resto.getMoment();
	capaciteTables_ = resto.capaciteTables_;
	nbTables_ = resto.nbTables_;

	for (int i = 0; i < resto.nbTables_; i++) {
		Table* table = new Table(resto.tables_[i]->getId(), resto.tables_[i]->getNbPlaces());
		*table = *resto.tables_[i];
		tables_.push_back(table);
	}
}

//destructeur
Restaurant::~Restaurant() {
	delete nom_;
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;
	
	tables_.clear();
}

//setter
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

void Restaurant::setNom(const string& nom){
	nom_ = new string(nom);
}

//getters
string Restaurant::getNom() const {
	return *nom_;
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

//autres methodes
void Restaurant::libererTable(int id) {
	for (int i = 0; i < nbTables_; i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
		}
	}
}

void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* plat = nullptr;
	int index;
	for (int i = 0; i < nbTables_; i++) {
		if (idTable == tables_[i]->getId()) {
			index = i;
			switch (momentJournee_) {
			case Matin :
				plat = menuMatin_->trouverPlat(nom);
				break;
			case Midi :
				plat = menuMidi_->trouverPlat(nom);
				break;
			case Soir :
				plat = menuSoir_->trouverPlat(nom);
				break;
			}
		}
	}
	if (plat != nullptr && tables_[index]->estOccupee()) {
		tables_[index]->commander(plat);
	}
	else cout << "Erreur : table non occupee ou plat introuvable" << endl;
}

void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (file) {
		string ligne, idString, nbPersonnesString;
		int id, nbPersonnes, curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-TABLES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (int i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						idString += ligne[i];
					}
					id = stoi(idString);
					nbPersonnesString = ligne.substr(curseur + 1);
					nbPersonnes = stoi(nbPersonnesString);
					Table* table = new Table(id, nbPersonnes);
					*this += table;
					nbPersonnesString = "";
					idString = "";
				}
			}
		}
		file.close();
	}
}

void Restaurant::placerClients(int nbClients) {
	int indexTable = -1;
	int minimum = 100;

	for (int i = 0; i < nbTables_; i++) {
		if (tables_[i]->getNbPlaces() >= nbClients && !tables_[i]->estOccupee() && tables_[i]->getNbPlaces() < minimum) {
			indexTable = i;
			minimum = tables_[i]->getNbPlaces();
		}
	}
	if (indexTable == -1) {
		cout << "Erreur : il n'y a plus/pas de table disponible pour le client. " << endl;
	}else
	tables_[indexTable]->placerClient(nbClients);
}

ostream & operator<<(ostream & o, const Restaurant & resto){
	cout << "Le restaurant " << *resto.nom_;
	if (resto.chiffreAffaire_ != 0) {
		cout << " a fait un chiffre d'affaire de : " << resto.chiffreAffaire_ << "$" << endl;
	} else {
		cout << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	}
	cout << "-Voici les tables : " << endl;
	for (int i = 0; i < resto.nbTables_; i++) {
		cout << "\t";
		cout << *resto.tables_[i];
	}
	
	cout << "-Voici son menu : " << endl;
	cout << *resto.menuMatin_;
	cout << *resto.menuMidi_;
	cout << *resto.menuSoir_;
	return o;
}

void Restaurant::operator+=(Table* table) {
	tables_.push_back(table);
	nbTables_++;
}
bool Restaurant::operator<(const Restaurant & resto) {
	return (chiffreAffaire_ < resto.chiffreAffaire_);
}

Restaurant& Restaurant::operator=(const Restaurant& resto) {
	delete nom_;
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;

	menuMatin_ = new Menu(*resto.menuMatin_);
	menuMidi_ = new Menu(*resto.menuMidi_);
	menuSoir_ = new Menu(*resto.menuSoir_);
	nom_ = resto.nom_;
	chiffreAffaire_ = resto.chiffreAffaire_;
	capaciteTables_ = resto.capaciteTables_;
	momentJournee_ = resto.momentJournee_;
	nbTables_ = resto.nbTables_;

	tables_.clear();
	for (int i = 0; i < resto.tables_.size(); i++){
		tables_.push_back(resto.tables_[i]);
    }
	return *this;
}
