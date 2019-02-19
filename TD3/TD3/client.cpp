#include "Client.h"

//constructeurs
Client::Client(){

}

Client::Client(string nom, string prenom, int tailleGroupe){

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

string Client::getNom()
{
	return string();
}

string Client::getPrenom()
{
	return string();
}

ostream & operator<<(ostream & os, const Client & client)
{
	// TODO: insert return statement here
}

string Client::convertirStatutString() const
{
	return string();
}