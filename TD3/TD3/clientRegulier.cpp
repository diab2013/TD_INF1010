/*
* Titre : clientRegulier.cpp - Travail Pratique #3
* Date : 25 Février 2019
* Auteurs : Diab Khanafer et Charles-Etienne Désormeaux
* Description : Ajoute des attributs speciaux a un client.
*/
#include "ClientRegulier.h"

/*
* Constructeur par défaut de la classe clientRegulier
* Initialise les attributs à des valeurs par défaut
* Le statut sera "Fidele" et le nombre de points est a 0
*/
ClientRegulier::ClientRegulier() : Client() {
	statut_ = Fidele;
	nbPoints_ = 0;
}

/*
* Constructeur par paramètre de la classe clientRegulier
* Initialise les attributs à des valeurs passées en paramètres
*/
ClientRegulier::ClientRegulier(string nom, string prenom, int tailleGroupe, int nbPoints) 
		: Client(nom, prenom, tailleGroupe) {
	nbPoints_ = nbPoints;
	statut_ = Fidele;
}

/*
* Out: variable du nombre de point de type int
* Renvoie la variable privee nbPoints_
*/
int ClientRegulier::getNbPoints() {
	return { nbPoints_ };
}

/*
* In: Nombre de points acquis de type int
* Ajoute au client a son montant de point la variable en parametre
*/
void ClientRegulier::augmenterNbPoints(int bonus) {
	nbPoints_ += bonus;
}

/*
* In/out: stream de l'output
* In: Client a afficher
* Out: String contenant tous les informations d'un client regulier
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream & operator<<(ostream & os, const ClientRegulier & client) {
	os << static_cast<Client>(client) << " possede " << client.nbPoints_ << " point(s)." << endl;
	return os;
}
