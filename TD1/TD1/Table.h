/*
* Titre : Table.h - Travail Pratique #1
* Date : 09 Janvier 2019
* Auteur : David Dratwa
*/

#ifndef TABLE_H
#define TABLE_H

#include "Menu.h"
const  int MAXCAP = 5;
class Table {
public: 
	//constructeurs 
	Table(); 
	Table(int id, int nbPlaces);

	//getters 
	int getId() const; 
	unsigned int getNbPlaces() const; //ajout unsigned
	bool estOccupee() const; 

	//setters 
	void libererTable(); //why setter? good question
	void placerClient(); //why setter? good question
	void setId(int id); 

	//autres methodes 
	void commander(Plat* plat); 
	double getChiffreAffaire(); 

	//affichage
	void afficher(); 
private : 
	Plat** commande_; 
	unsigned int capacite_; 
	unsigned int nbPlats_; 

	int id_; 
	unsigned int nbPlaces_; 
	bool occupee_; 
};
#endif // !TABLE_H
