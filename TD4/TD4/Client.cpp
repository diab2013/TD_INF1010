/*
* Date : 25 février 2019
* Auteur : AbdeB
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
 * IN: 
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
