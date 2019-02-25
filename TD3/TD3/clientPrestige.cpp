#include "ClientPrestige.h"

ClientPrestige::ClientPrestige() : ClientRegulier() {
	status_ = Prestige;
	addresse_ = Zone3;
}

ClientPrestige::ClientPrestige(string nom, string prenom, int tailleGroupe, int nbPoints, 
	AddressCode addresse) : ClientRegulier(nom, prenom, tailleGroupe, nbPoints) {
	
}

AddressCode ClientPrestige::getAddresseCode(){
	return AddressCode();
}

string ClientPrestige::getAddressCodeString() const{
	string
	return string();
}

ostream & operator<<(ostream & os, ClientPrestige client){
	// TODO: insert return statement here
}
