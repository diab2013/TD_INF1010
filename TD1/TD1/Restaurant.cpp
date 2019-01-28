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

}

void Restaurant::placerClients(int nbClients){

}

//affichage
void Restaurant::afficher(){

}