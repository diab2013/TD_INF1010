/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 11 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer une table ainsi que ses attributs.
*/

#include "Table.h"

/*
* Constructeur par défaut de la classe Table
* Crée une nouvelle liste de plat vide avec une capacité de MAXCAP
* Le nombre de plat est zéro, le id de la table est -1, le nombre de places à 1
* et la table n'est pas occupée
*/
Table::Table() {
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

/*
* Constructeur par paramétres de la classe Table
* Initialise les attributs à des valeurs passées en paramètres
*/
Table::Table(int id, int nbPlaces) {
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = id;
	nbPlaces_ = nbPlaces;
	nbClientsATable_ = 0;
}

//destructeur de la classe
Table::~Table() {
	//A MODIFIER
	libererTable();
}

/*
* Getter de la variable id
* Return l'attribut id_ de la classe
*/
int Table::getId() const {
	return id_;
}

/*
* Getter de la variable nbPlaces_
* Return l'attribut nbPlaces_ de la classe
*/
int Table::getNbPlaces() const {
	return nbPlaces_;
}

/*
* Getter de la variable nbClientsATable_
* Return l'attribut nbClientsATable_ de la classe
*/
int Table::getnbClientATable() const{
	return nbClientsATable_;
}

/*
* Return l'attribut nbPlaces_ avec une valeur de 0
*/
bool Table::estPleine() const {
	return nbPlaces_==0;
}

/*
* Return 1 si nbClientsATable n'a pas la valeur 0
* Méthode qui permet de placer la table comme occupee.
*/
bool Table::estOccupee() const{
	return nbClientsATable_!=0;
}

/*
* In: Id de la table
* Méthode qui set le id à la valeur passée en paramètre
*/
void Table::setId(int id) {
	id_ = id;
}

/*
* Méthode qui permet de liberer une table et la reset
* Supprime la commande actuelle et met la table comme libre
*/
void Table::libererTable() {
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	commande_.clear();
	nbPlats_ = 0;
}

/*
* In: nombre de client a placer
* Set le nombre de client a la table au nombre recu en parametre
* et fait la difference entre le nombre de clients et le nombre de place
*/
void Table::placerClient(int nbClients) {
	nbClientsATable_ = nbClients;
	nbPlaces_ -= nbClients;
}

/*
* In: Plat a commande
* Méthode qui permer de commande un plat pour les clients assis à la table
* Si le nombre de plats commander n'est pas dépassé, ajoute le plat passé
* en paramètre à la liste de commande
*/
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
	nbPlats_++;
}

/*
* Méthode qu perment de calculer le chiffre d'affaire fait par la liste de commande
* de la table
* return le chiffre d'affaire après le calcul
*/
double Table::getChiffreAffaire() const {
	double chiffre = 0;
	for (int i = 0; i < nbPlats_; i++) {
		chiffre += (commande_[i]->getPrix() - commande_[i]->getCout());
	}
	return chiffre;
}

/*
* In/out: stream de l'output
* In: Table a afficher
* Out: String contenant les informations de la table
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream& operator<<(ostream & o, const Table & table){
	cout << "La table numero " << table.getId();
	if (table.estOccupee()) {
		cout << " est occupee. ";
		if (table.nbPlats_ != 0) {
			cout << "Voici la commande passee par les clients : " << endl;
			for (int i = 0; i < table.nbPlats_; i++) {
				cout << "\t";
				cout << *table.commande_[i];
			}
		} else {
			cout << "Mais ils n'ont rien conmmande pour l'instant. " << endl;
		}
	} else {
		cout << " est libre. " << endl;
	}
	return o;
}