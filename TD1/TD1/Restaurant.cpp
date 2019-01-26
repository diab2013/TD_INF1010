#include "Restaurant.h"

//constructeurs
Restaurant::Restaurant(){
	//constructeur par défaut<
	nom_ = new string;
	*nom_ = "inconnu"; //wtf pk c'est un pointeur ?!??!
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
	if (nbTables_ < capaciteTables_) {

	} else {
		cout << "La table n'a pas pu être ajouter" << endl;
	}
}

void Restaurant::libererTable(int id){

}

void Restaurant::commanderPlat(string & nom, int idTable){

}

void Restaurant::placerClients(int nbClients){

}

//affichage
void Restaurant::afficher(){

}