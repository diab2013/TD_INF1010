#include "Client.h"

//constructeurs
Client::Client(){
	nom_ = "inconnu";
	prenom_ = "inconnu";
	statut_ = Occasionnel;
}

Client::Client(string nom, string prenom, int tailleGroupe){
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
}

//destructur
Client::~Client(){

}

//getters
StatutClient Client::getStatut(){
	return StatutClient();
}

int Client::getTailleGroupe(){
	return 0;
}

string Client::getNom(){
	return string();
}

string Client::getPrenom(){
	return string();
}

string Client::convertirStatutString() const{
	return string();
}

ostream & operator<<(ostream & os, const Client & client){
	os << "Le client principal est: \n" << client.getPrenom << " statut: " << client.convertirStatutString();
	return os;
}

