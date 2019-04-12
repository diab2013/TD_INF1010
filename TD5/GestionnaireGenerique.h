/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"

using namespace  std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 

template<typename T, typename C>
class GestionnaireGenerique
{
public:
	C getConteneur() const; //TODO
	void ajouter(T t);//TODO
	int getNombreElements() const;//TODO

protected:
	C conteneur_;
};

/*
* Out: Copie du conteneur
* Creer une copie du conteneur et la renvoie
*/
template<typename T, typename C>
inline C GestionnaireGenerique<T, C>::getConteneur() const {
	C copie;
	copy(conteneur_.begin(),conteneur_.end(),copie);
	return copie;
}

/*
* In: Template de type T
* Ajoute un objet au conteneur
*/
template<typename T, typename C>
inline void GestionnaireGenerique<T, C>::ajouter(T t) {
	conteneur_.insert(t);
}

/*
* Out: Nombre d'element contenu dans le conteneur
* Renvoie le nombre d'element du conteneur
*/
template<typename T, typename C>
inline int GestionnaireGenerique<T, C>::getNombreElements() const {
	return conteneur_.size();
}
