/*
* Titre : Table.cpp - Travail Pratique #2
* Date : 11 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer une table ainsi que ses attributs.
*/

#include "Table.h"

/*
* Constructeur par d�faut de la classe Table
* Cr�e une nouvelle liste de plat vide avec une capacit� de MAXCAP
* Le nombre de plat est z�ro, le id de la table est -1, le nombre de places � 1
* et la table n'est pas occup�e
*/
Table::Table() {
	capacite_ = MAXCAP;
	nbPlats_ = 0;
	id_ = -1;
	nbPlaces_ = 1;
	nbClientsATable_ = 0;
}

/*
* Constructeur par param�tres de la classe Table
* Initialise les attributs � des valeurs pass�es en param�tres
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
* M�thode qui permet de placer la table comme occupee.
*/
bool Table::estOccupee() const{
	return nbClientsATable_!=0;
}

/*
* In: Id de la table
* M�thode qui set le id � la valeur pass�e en param�tre
*/
void Table::setId(int id) {
	id_ = id;
}

/*
* M�thode qui permet de liberer une table et la reset
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
* M�thode qui permer de commande un plat pour les clients assis � la table
* Si le nombre de plats commander n'est pas d�pass�, ajoute le plat pass�
* en param�tre � la liste de commande
*/
void Table::commander(Plat* plat) {
	commande_.push_back(plat);
	nbPlats_++;
}

/*
* M�thode qu perment de calculer le chiffre d'affaire fait par la liste de commande
* de la table
* return le chiffre d'affaire apr�s le calcul
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