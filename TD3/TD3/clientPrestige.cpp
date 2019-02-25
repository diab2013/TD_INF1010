/*
* Titre : clientPrestige.cpp - Travail Pratique #3
* Date : 25 F�vrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne D�sormeaux
* Description : Ajoute des attributs speciaux a un client.
*/

#include "ClientPrestige.h"

/*
* Constructeur par d�faut de la classe clientPrestige
* Initialise les attributs � des valeurs par d�faut
* Le statut sera "Prestige" et la zone a 3
*/
ClientPrestige::ClientPrestige() : ClientRegulier() {
	statut_ = Prestige;
	addresse_ = Zone3;
}

/*
* Constructeur par param�tre de la classe clientPrestige
* Initialise les attributs � des valeurs pass�es en param�tres
*/
ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, 
	AddressCode addresse) : ClientRegulier(nom, prenom, tailleGroupe, nbPoints) {
	statut_ = Prestige;
	addresse_ = addresse;
}

/*
* Out: variable de l'adresse du client de type AdresseCode
* Renvoie la variable privee addresse_
*/
AddressCode ClientPrestige::getAddresseCode(){
	return addresse_;
}

/*
* Out: variable du code de l'adresse de type string
* Renvoie l'adresse du client en string
*/
string ClientPrestige::getAddressCodeString() const{
	switch (addresse_) {
		case Zone1: return "Zone1";
		case Zone2: return "Zone2";
		default: return "Zone3";
	}
}

/*
* In/out: stream de l'output
* In: Client a afficher
* Out: String contenant tous les informations d'un client prestige
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream & operator<<(ostream & os, ClientPrestige client){
	os << static_cast<ClientRegulier>(client) << " habite dans la " << client.getAddressCodeString() << endl;
	return os;
}
