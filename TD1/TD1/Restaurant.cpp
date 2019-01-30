#include "Restaurant.h"

//constructeurs
Restaurant::Restaurant(){
	//constructeur par défaut<
	nom_ = new string;
	*nom_ = "inconnu";
	momentJournee_ = Matin;
	chiffreAffaire_ = NULL;
	menuMatin_ = nullptr;
	menuMidi_ = nullptr;
	menuSoir_ = nullptr;
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
	//Menu::lireMenu(fichier);
	nom_ = &nom;

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

}

void Restaurant::ajouterTable(int id, int nbPlaces){
	Table tempTable(id, nbPlaces);
	if (nbTables_ < capaciteTables_) { //maybe utiliser INTTABLES???

	} else {
		cout << "La table n'a pas pu être ajouter" << endl;
	}
}

void Restaurant::libererTable(int id){
	for (unsigned i = 0; i < nbTables_; i++) {
		if ((id == &tables_[i]->getId) && tables_[i]->estOccupee()) {
			tables_[i]->libererTable();
			delete tables_[i];
			tables_[i] = nullptr;
		}
	}
}

void Restaurant::commanderPlat(string& nom, int idTable){
	tables_[idTable]->commander.commander(nom);//maybe???
}

void Restaurant::placerClients(int nbClients){
	//on fait comment sans le id de la table?
	int nbTablesOccupees = 0;
	int tableOptimale = 0;
	for (int i = 0; i < nbTables_; i++) {
		if (tables_[i]->estOccupee) {
			nbTablesOccupees++;
			if (nbTablesOccupees == nbTables_) {
				cout << "Il n'y a pas de places disponible" << endl;
			}
		}
		else {
			if (tables_[i]->getNbPlaces < tables_[tableOptimale]->getNbPlaces && nbClients <= tables_[i]->getNbPlaces) {
				//pour la premiere partie du int, je veux quil check si la nouvelle table quil check a moins de place que celle
				//choisie pour linstant, mais sa pourrait causer des problemes comme la variable tableOptimale est
				//initialisee a 0
				//exemple: si table_[0] est occupee et a autant de place que de client->rip
				tableOptimale = i;
			}
		}
	}
	tables_[tableOptimale]->placerClient();
}

//affichage
void Restaurant::afficher(){

	for (int i = 0; i < nbTables_; i++) {
		tables_[i]->afficher();
	}
}