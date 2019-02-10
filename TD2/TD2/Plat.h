/*
* Titre : Plat.h - Travail Pratique #2
* Date : 18 Janvier 2019
* Auteur : Allan BEDDOUK
*/

#ifndef PLAT_H
#define PLAT_H

#include <string>
#include <iostream>

using namespace std;

class Plat {
public:
	/// constructeurs
	Plat();
	Plat(string nom, double prix, double cout);

	///getters
	string getNom() const;
	double getPrix() const;
	double getCout() const;
	double getPetitPrix(double a, double b) const;//maybe?

	///setters
	void setNom(string nom);
	void setPrix(double prix);

	///methodes en plus
	string afficher() const; // A MODIFIER
	friend ostream& operator<<(ostream& o, const Plat& plat);

private:
	string nom_;
	double prix_;
	double cout_;

};

#endif // !PLAT_H
