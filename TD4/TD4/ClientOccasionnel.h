/*
* Date : 25 f�vrier 2019
* Auteur : AbdeB
*/
#ifndef CLIENT_OCCASIONNEL
#define CLIENT_OCCASIONNEL

#include "Client.h"

class ClientOccasionnel: public Client
{
public:
	ClientOccasionnel(string_view nom, string_view prenom, int tailleGroupe);//TODO
    ~ClientOccasionnel();
     int getNbPoints() const override;// TODO
     virtual void afficherClient(ostream & os) const override;// TODO
     double getReduction(const Restaurant & res, double montant, bool estLivraison) override; // TODO
};

#endif
