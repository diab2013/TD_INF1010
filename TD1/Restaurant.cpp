#include "Restaurant.h"

Restaurant::Restaurant(){
	//constructeur par défaut
	nom_ = "inconnu"; //wtf pk c'est un pointeur ?!??!
	momentJournee_ = Matin;
	chiffreAffaire_ = NULL;
}

Restaurant::Restaurant(string& fichier, string& nom, TypeMenu moment){
	
	nom_ = &nom;
}

void Restaurant::setMoment(TypeMenu moment){

}

string Restaurant::getNom(){
	return string();
}

TypeMenu Restaurant::getMoment(){
	return TypeMenu();
}

void Restaurant::lireTable(string & fichier){

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