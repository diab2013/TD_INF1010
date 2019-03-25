/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/

#include "Table.h"
using namespace std;

// Constructeurs.
/*
 * Constructeur par param�tres de la classe
 * IN:
*/
Table::Table(int id, int nbPlaces) :
	id_{id}, nbPlaces_{nbPlaces}, nbClientsATable_{0}, clientPrincipal_{nullptr}
{
}

// Getters.
/*
 * Getter de l'attribut id_
 * OUT: return l'attribut id_ de la l'objet
*/
int Table::getId() const{
	return id_;
}

/*
 * Getter de l'attribut nbPlaces_
 * OUT: return l'attribut nbPlaces_ de l'objet
*/
int Table::getNbPlaces() const{
	return nbPlaces_;
}

/*
 * Getter de si la table est occup�e
 * OUT: return si la table est occup�e ou pas
*/
bool Table::estOccupee() const{
	return nbClientsATable_ != 0;
}

/*
 * Getter de si la table est pleine
 * OUT: return si la table est pleine ou pas
*/
bool Table::estPleine() const{
	return nbPlaces_ == 0;
}

/*
 * Getter de l'attribut nbClientsATable_
 * OUT: return l'attribut nbClientsATable_ de l'objet
*/
int Table::getNbClientsATable() const{
	return nbClientsATable_;
}

/*
 * Getter de l'attribut commmande_
 * OUT: return l'attribut commande_ de l'objet, la liste de plat
*/
vector<Plat*> Table::getCommande() const{
	return commande_;
}

/*
 * Getter de l'attribut clientPrincipal_
 * OUT: return l'attribut clientPrincipal_ de l'objet
*/
Client* Table::getClientPrincipal() const{
	return clientPrincipal_;
}

// Setters.
/*
 * Setter de l'attribut id_
 * IN: nouvelle valeur de l'attribut id_
*/
void Table::setId(int id){
	id_ = id;
}

/*
 * Setter l'attribut clientPrincipal_
 * IN: nouvelle valeur de l'attribut clientPrincipal_
*/
void Table::setClientPrincipal(Client * clientPrincipal){
	clientPrincipal_ = clientPrincipal;
}

/*
 * M�thode pour liberer la table
 * Lib�re la table de ces clients et vide la commande de la table
*/
void Table::libererTable(){
	nbPlaces_ += nbClientsATable_;
	nbClientsATable_ = 0;
	commande_.clear();
}

/*
 * M�thode pour placer un client � la table
*/
void Table::placerClients(int nbClient){
	nbPlaces_ -= nbClient;
	nbClientsATable_ = nbClient;
}


// Autres methodes.
/*
 * M�thode pour commande un plat
 * IN: pointeur vers un plat qu'on ajoute � la commande
*/
void Table::commander(Plat* plat){
	commande_.push_back(plat);
}

/*
 * M�thode pour obtenir le chiffre d'affaire de la table
 * OUT: return le r�sultat du calcul du chiffre d'affaire de la table
*/
double Table::getChiffreAffaire() const{
	double chiffre = 0;
	for (unsigned i = 0; i < commande_.size(); ++i)
        chiffre += commande_[i]->getPrixRevient();
	return chiffre;
}

/*
 * Override de l'op�rateur << pour l'affichage
 * IN: 
*/
ostream& operator<<(ostream& os, const Table& table){
	os << "La table numero " << table.id_;
	if (table.estOccupee()) {
		os << " est occupee. Le client principal est:" << endl;
        os<< table.getClientPrincipal()->getNom()<< endl;;

		if (!table.commande_.empty()) {
			os << "Voici la commande passee par les clients :" << endl;
			for (Plat* plat : table.commande_) {
				os << "\t";
				plat->afficherPlat(os);
			}
		}
		else
			os << "Mais ils n'ont rien commande pour l'instant." << endl;
	}
	else
		os << " est vide. " << endl;

	return os;
}
