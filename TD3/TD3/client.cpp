/*
* Titre : client.cpp - Travail Pratique #3
* Date : 25 F�vrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne D�sormeaux
* Description : Creer un client.
*/

#include "Client.h"

/*
* Constructeur par d�faut de la classe client
* Initialise les attributs � des valeurs par d�faut
* Le nom et prenom seront "inconnu" et la taille du groupe sera de z�ro et le statut sera "Occasionnel"
*/
Client::Client(){
	nom_ = "inconnu";
	prenom_ = "inconnu";
	tailleGroupe_ = 0;
	statut_ = Occasionnel;
}

/*
* Constructeur par param�tre de la classe client
* Initialise les attributs � des valeurs pass�es en param�tres
*/
Client::Client(string nom, string prenom, int tailleGroupe){
	nom_ = nom;
	prenom_ = prenom;
	tailleGroupe_ = tailleGroupe;
}

/*
* Out: variable de statut de type enum
* Renvoie la variable privee statut_
*/
StatutClient Client::getStatut() const{
	return statut_;
}

/*
* Out: variable de la taille du groupe de type int
* Renvoie la variable privee tailleGroupe_
*/
int Client::getTailleGroupe() const{
	return tailleGroupe_;
}

/*
* Out: variable de nom de client de type string
* Renvoie la variable privee nom_
*/
string Client::getNom() const{
	return nom_;
}

/*
* Out: variable de prenom de client de type string
* Renvoie la variable privee prenom_
*/
string Client::getPrenom() const{
	return prenom_;
}

/*
* Out: variable de type string
* Renvoie l'enum converti en string
*/
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

/*
* In/out: stream de l'output
* In: Plat a afficher
* Out: String contenant tous les informations d'un client
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream & operator<<(ostream & os, const Client & client){
	os << "Le client principal est: \n" << "-" << client.prenom_ << " " << client.nom_ << " statut: " << client.convertirStatutString();
	return os;
}

