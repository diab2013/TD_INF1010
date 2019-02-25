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
	return statut_;
}

int Client::getTailleGroupe(){
	return 0;
}

string Client::getNom(){
	return nom_;
}

string Client::getPrenom(){
	return prenom_;
}

string Client::convertirStatutString() const{

	switch (statut_) {
	case (Occasionnel):
		return "Occasionnel";
	case (Fidele):
		return "Regulier";
	case (Prestige):
		return "Prestige";
	}
}

ostream & operator<<(ostream & os, const Client & client){
	os << "Le client principal est: \n" << client.getPrenom << " " << client.nom_ << " statut: " << client.convertirStatutString();
	return os;
}

