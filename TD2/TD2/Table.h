/*
* Titre : Table.h - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef TABLE_H
#define TABLE_H

#include "Plat.h"
#include <vector>
const  int MAXCAP = 5;
class Table {
public:
	///constructeurs
	Table();
	Table(int id, int nbPlaces);

	///destructeur
	~Table();

	///getters
	int getId() const;
	int getNbPlaces() const;
	int getnbClientATable() const;
	bool estPleine() const;
	bool estOccupee() const;

	///setters
	void libererTable();
	void placerClient(int nbClients);
	void setId(int id);

	///autres methodes
	void commander(Plat* plat);
	double getChiffreAffaire() const;

	///override
	friend ostream& operator<<(ostream& o, const Table& table);

private:
	//A MODIFIER
	int capacite_;
	vector<Plat*> commande_;
	int nbPlats_;
	int id_;
	int nbPlaces_;
	int nbClientsATable_;
};
#endif // !TABLE_H
