/*
* Titre : client.cpp - Travail Pratique #3
* Date : 25 Février 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creer un client.
*/

#include "Client.h"

/*
* Constructeur par défaut de la classe client
* Initialise les attributs à des valeurs par défaut
* Le nom et prenom seront "inconnu" et la taille du groupe sera de zéro et le statut sera "Occasionnel"
*/
Client::Client(){
	nom_ = "inconnu";
	prenom_ = "inconnu";
	tailleGroupe_ = 0;
	statut_ = Occasionnel;
}

/*
* Constructeur par paramètre de la classe client
* Initialise les attributs à des valeurs passées en paramètres
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

