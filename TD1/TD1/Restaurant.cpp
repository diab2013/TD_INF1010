#include "Restaurant.h"

//constructeurs
string nomResto = "inconnu"; //a changer?
Restaurant::Restaurant(){
	//constructeur par défaut<
	nom_ = new string;
	*nom_ = nomResto;
	momentJournee_ = Matin;
	chiffreAffaire_ = NULL;
	menuMatin_ = nullptr;
	menuMidi_ = nullptr;
	menuSoir_ = nullptr;
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
	//Menu::lireMenu(fichier);
	nom_ = &nom;
	momentJournee_ = moment;
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
	ifstream lireFichier(fichier + ".txt");
	string mot;
	int numeroTable = 0,id,nbPLace;
	bool renduTable = false;
	while (!renduTable) {
		lireFichier >> mot;
		if (mot == "-TABLES") {
			renduTable = true;
			while (!lireFichier.eof) {
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
		if ((id == &tables_[i]->getId) && tables_[i]->estOccupee()) {
			tables_[i]->libererTable();
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			delete tables_[i];
			tables_[i] = nullptr;
		}
	}
}

void Restaurant::commanderPlat(string& nom, int idTable){
	tables_[idTable]->commander.commander(nom);//maybe???
}

void Restaurant::placerClients(int nbClients){
	int nbTablesOccupees = 0;
	int tableOptimale = 0;
	bool peutPlacer = false;

	for (int i = 0; i < nbTables_; i++) {
		if (tables_[i]->estOccupee) {
			nbTablesOccupees++;
			if (nbTablesOccupees == nbTables_) {
				cout << "Il n'y a pas de places disponible" << endl;
			}
		}
		else {
			while (tables_[tableOptimale]->estOccupee) { //si tables_[0] est occupee
				tableOptimale++;
			}			
			if (tables_[i]->getNbPlaces < tables_[tableOptimale]->getNbPlaces && nbClients <= tables_[i]->getNbPlaces) {
				tableOptimale = i;
				peutPlacer = true;
			}

		}	
	}
	if (peutPlacer) { 
		tables_[tableOptimale]->placerClient();
	}
	if (!peutPlacer && nbTablesOccupees < nbTables_) {
		cout << "Il n'y a pas de table ayant asser de place pour ces clients." << endl;
	}
}

//affichage
void Restaurant::afficher(){

	for (int i = 0; i < nbTables_; i++) {
		tables_[i]->afficher();
	}
}