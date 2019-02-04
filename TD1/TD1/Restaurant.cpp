/*
* Titre : Restaurant.cpp - Travail Pratique #1
* Date : 04 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer un restaurant ainsi que ses attributs.
*/

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
* La fonction lireTable charge les valeurs des tables progvenant du document 
*/
Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
	nom_ = new string(nom);
	momentJournee_ = moment;
	capaciteTables_ = INTTABLES;
	tables_ = new Table*[capaciteTables_];
	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier, Midi);
	menuSoir_ = new Menu(fichier, Soir);
	lireTable(fichier);
}

//destructeur
Restaurant::~Restaurant(){
}

/*
* in: moment de la journee de type TypeMenu
* out: variable privee de la classe ayant la valeur du in
* Set la variable privee momentJournee à la variable in
*/
void Restaurant::setMoment(TypeMenu moment){
	momentJournee_ = moment;
}

/*
* out: pointeur string
* Renvoie un pointeur string privee
*/
string Restaurant::getNom() const{
	return *nom_;
}

/*
* out: variable TypeMenu
* Renvoie une variable TypeMenu privee
*/
TypeMenu Restaurant::getMoment() const{
	return momentJournee_;
}

/*
* in: nom du fichier .txt
* Lit les tables du fichier et envoie leurs donnees a une autre fonction
*/
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

/*
* in: id d'une table, nombre de place d'une table
* Creer une table selon les donnees recues en parametre
*/
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

/*
* in: id d'une table
* Libere une table occupee, l'enleve de la liste de table ainsi que son pointeur
*/
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

/*
* in: nom d'un plat, id d'une table
* Envoie a une autre fonction, selon le type de menu, un nom plat commande.
*/
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

/*
* in: nombre int de client a placer a une table
* Place le groupe de client selon la table la plus optimale s'il y a de la place
*/
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
	if (peutPlacer) { 
		tables_[tableOptimale]->placerClient();
		cout << "Le client à ete ajouter a la table " << tables_[tableOptimale]->getId() << " !" << endl;
	}
	if (!peutPlacer) {
		cout << "Il n'y a pas de table ayant asser de place pour ces clients." << endl;
	}
}

/*
* Affiche le nom du restaurant, tous les menus ainsi que toutes les informations des tables
*/
void Restaurant::afficher(){
	cout << "| Bienvenue chez " << nom_ << "! |" <<endl;
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