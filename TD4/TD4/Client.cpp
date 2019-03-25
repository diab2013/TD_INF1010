/*
* Titre : Client.cpp - Travail Pratique #4
* Date : 25 Mars 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Creer un objet de client ainsi que ses attributs.
*/

#include "Client.h"

/*
 * Constructeur par défaut de la classe
*/
Client::Client() {
	tableOccupee_ = nullptr;
}

/*
 * Constructeur par paramètres de la classe
 * IN: nom du client, prenom du client, taille du groupe du client
*/
Client::Client(string_view nom, string_view prenom, int tailleGroupe) :
	nom_(nom), prenom_(prenom), tailleGroupe_(tailleGroupe)
{
    tableOccupee_ = nullptr;
}

/*
 * Getter de l'attribut tailleGroupe_
 * OUT: return l'attribut tailleGroupe_ de l'objet
*/
int Client::getTailleGroupe() const {
	return tailleGroupe_;
}

/*
 * Getter de l'attribut nom_
 * OUT: return l'attribut nom_ de l'objet
*/
string Client::getNom() const {
	return nom_;
}

/*
 * Getter de l'attribut prenom_
 * OUT: return l'attribut prenom_ de l'objet
*/
string Client::getPrenom() const{
	return prenom_;
}

/*
 * Setter de l'attribut tableOccupee_
 * IN: nouvelle valeur pour l'attribut tableOccupee_
*/
void Client::setTable(Table * ta){ 
	tableOccupee_ = ta;
}

/*
 * Getter de l'attrubyt tableOccupee_
 * OUT: return l'attribut tableOccupee_ de la classe
*/
Table * Client:: getTable() const{ 
	return tableOccupee_;
}

/*
 * Méthode pour l'affichage des attributs de la classe
 * IN: une référence à un ostream pour l'affichage
*/
void Client::afficherClient(ostream & os) const {
	
}
