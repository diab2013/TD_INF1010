#include "Restaurant.h"

Restaurant::Restaurant(){
	//constructeur par défaut
	nom_ = "inconnu"; //wtf pk c'est un pointeur ?!??!
	momentJournee_ = Matin;
	chiffreAffaire_ = NULL;
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
	nom_ = &nom; //utile?
	momentJournee_ = moment;
}

//setters
void Restaurant::setMoment(TypeMenu moment){
	momentJournee_ = moment;
}

//getters
string Restaurant::getNom(){
	return string();
}

TypeMenu Restaurant::getMoment(){
	return TypeMenu();
}

//autres methodes
void Restaurant::lireTable(string & fichier){
	ifstream entree(fichier + ".txt");
	while (!entree.open.eof()) {
		
	}
}

void Restaurant::ajouterTable(int id, int nbPlaces){

}

void Restaurant::libererTable(int id){

}

void Restaurant::commanderPlat(string & nom, int idTable){

}

void Restaurant::placerClients(int nbClients){

}

void Restaurant::afficher(){

}