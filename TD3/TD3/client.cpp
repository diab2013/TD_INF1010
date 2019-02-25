#include "Client.h"

//constructeurs
Client::Client(){
	nom_ = "inconnu";
	prenom_ = "inconnu";
	tailleGroupe_ = 0;
	statut_ = Occasionnel;
}

Client::Client(string nom, string prenom, int tailleGroupe){
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
}

//getters
StatutClient Client::getStatut() const{
	return statut_;
}

int Client::getTailleGroupe() const{
	return tailleGroupe_;
}

string Client::getNom() const{
	return nom_;
}

string Client::getPrenom() const{
	return prenom_;
}

string Client::convertirStatutString() const{
	switch (statut_) {
		case Fidele:
			return "Regulier";
		case Prestige:
			return "Prestige";
		default:
			return "Occasionnel";
	}
}

ostream & operator<<(ostream & os, const Client & client){
	os << "Le client principal est: \n" << "-" << client.prenom_ << " " << client.nom_ << " statut: " << client.convertirStatutString();
	return os;
}

