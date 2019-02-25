#include "ClientPrestige.h"

ClientPrestige::ClientPrestige() : ClientRegulier() {
	statut_ = Prestige;
	addresse_ = Zone3;
}

ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, 
	AddressCode addresse) : ClientRegulier(nom, prenom, tailleGroupe, nbPoints) {
	statut_ = Prestige;
	addresse_ = addresse;
}

AddressCode ClientPrestige::getAddresseCode(){
	return addresse_;
}

string ClientPrestige::getAddressCodeString() const{
	switch (addresse_) {
		case Zone1: return "Zone1";
		case Zone2: return "Zone2";
		default: return "Zone3";
	}
}

ostream & operator<<(ostream & os, ClientPrestige client){
	os << static_cast<ClientRegulier>(client) << " habite dans la " << client.getAddressCodeString() << endl;
	return os;
}
