/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 11 Février 2019
* Auteur : Fatou S. MOUNZEO
*/

#include "Restaurant.h"

//constructeurs 
Restaurant::Restaurant() {
	nom_ = new string("Inconnu"); 

	chiffreAffaire_ = 0; 
	
	momentJournee_ = Matin; 

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);

}

Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom); 

	chiffreAffaire_ = 0; 

	momentJournee_ = moment; 

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);

	lireTable(fichier); 
	lireAdresses(fichier);
}

Restaurant::Restaurant(const Restaurant & restau) : nom_(new string(*restau.nom_)),
chiffreAffaire_(restau.chiffreAffaire_),
momentJournee_(restau.momentJournee_),
menuMatin_(new Menu(*restau.menuMatin_)),
menuMidi_(new Menu(*restau.menuMidi_)),
menuSoir_(new Menu(*restau.menuSoir_))
{
	tables_.clear();
	for (unsigned i = 0; i < restau.tables_.size(); ++i)
		tables_.push_back(new Table(*restau.tables_[i]));
	for (unsigned i = 0; i < NB_ZONES_LIVR; i++) 
		fraisTransport_[i] = restau.getFraisTransports(i);
}

//destructeur 
Restaurant::~Restaurant() {
	delete nom_; 
	delete menuMatin_; 
	delete menuMidi_; 
	delete menuSoir_; 
	for (unsigned i = 0; i < tables_.size(); ++i)
		delete tables_[i];

}

//setter 
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment; 
}

void Restaurant::setNom(const string & nom){
	nom_ = new string(nom);
}

//getters 
string Restaurant::getNom() const {
	return *nom_; 
}

TypeMenu Restaurant::getMoment() const {
	return momentJournee_; 
}

double Restaurant::getFraisTransports(int index) const{
	return fraisTransport_[index];
}

//autres methodes 
void Restaurant::libererTable(int id) {
	bool livraison = false;
	for (unsigned i = 0; i < tables_.size(); ++i) {
		StatutClient statut = tables_[i]->getClientPrincipal()->getStatut();
		if (id == tables_[i]->getId()) {
			livraison = false;
			if (statut == Prestige) {
				if (i = INDEX_TABLE_LIVRAISON) {
					livraison = true;
				}
				chiffreAffaire_ += tables_[i]->getChiffreAffaire() + 
					calculerReduction(tables_[i]->getClientPrincipal(), 
						tables_[i]->getChiffreAffaire(), livraison);
			} else if (statut == Fidele) {
				chiffreAffaire_ += tables_[i]->getChiffreAffaire() +
					calculerReduction(tables_[i]->getClientPrincipal(),
						tables_[i]->getChiffreAffaire(), livraison);
			} else {
				chiffreAffaire_ += tables_[i]->getChiffreAffaire(); 
			}
			tables_[i]->libererTable(); 
			break;
		}
	}
}

ostream& operator<<(ostream& os, const Restaurant& restau){
	os << "Le restaurant " << *restau.nom_;
	if (restau.chiffreAffaire_ != 0)
		os << " a fait un chiffre d'affaire de : " << restau.chiffreAffaire_ << "$" << endl;
	else
		os << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;

	os << "-Voici les tables : " << endl;

	for (unsigned i = 0; i < restau.tables_.size(); i++) {
		os  << *restau.tables_[i] << endl;
	}
	os << endl;
	os << "-Voici son menu : " << endl;
	os << "Matin : " << endl
		<<*restau.menuMatin_<<endl << "Le plat le moins cher est : " << *restau.menuMatin_->trouverPlatMoinsCher() << endl;
	os << "Midi : " << endl
		<< *restau.menuMidi_<<endl << "Le plat le moins cher est : " << *restau.menuMidi_->trouverPlatMoinsCher() << endl;
	os << "Soir : " << endl
		<< *restau.menuSoir_<<endl << "Le plat le moins cher est : " << *restau.menuSoir_->trouverPlatMoinsCher() <<endl;

	return os;
}

void Restaurant::commanderPlat(const string& nom, int idTable,TypePlat type, int nbIngredients) {
	Plat* plat = nullptr; 
	int index; 
	for (unsigned i = 0; i < tables_.size(); i++) {
		if (idTable == tables_[i]->getId()) {
			index = i; 
			switch (momentJournee_) {
				case Matin :
					plat = menuMatin_->trouverPlat(nom); 
					break; 
				case Midi : 
					plat = menuMidi_->trouverPlat(nom); 
					break; 
				case Soir : 
					plat = menuSoir_->trouverPlat(nom); 
					break; 
			}
			break;
		}
	}

	if (plat == nullptr || !tables_[index]->estOccupee()) {
		cout << "Erreur : table vide ou plat introuvable" << endl << endl;
	} else {
		if (type == Custom) {
			PlatCustom* platCustom = static_cast<PlatCustom*>(plat);
			tables_[index]->commander(new PlatCustom(plat->getNom(), plat->getPrix(),
				plat->getCout(), nbIngredients));
		} else
			tables_[index]->commander(plat);
	}
}

bool Restaurant::operator<(const Restaurant & restau) const {
	return this->chiffreAffaire_ < restau.chiffreAffaire_;
}

Restaurant & Restaurant::operator=(const Restaurant & restau){
	if (this != &restau)
	{
		delete menuMatin_;
		delete menuMidi_;
		delete menuSoir_;

		chiffreAffaire_ = restau.chiffreAffaire_;
		momentJournee_ = restau.momentJournee_;
		menuMatin_ = new Menu(*restau.menuMatin_);
		menuMidi_ = new Menu(*restau.menuMidi_);
		menuSoir_ = new Menu(*restau.menuSoir_);
		for (unsigned i = 0; i < tables_.size(); ++i)
			delete tables_[i];

		tables_.clear();
		for (unsigned i = 0; i < restau.tables_.size(); ++i)
			tables_.push_back(new Table(*restau.tables_[i]));
		for (unsigned i = 0; i < NB_ZONES_LIVR; i++)
			fraisTransport_[i] = restau.getFraisTransports(i);

	}

	return *this;
}

void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in); 

	if (file) {
		string ligne; 
		
		string idString; 
		int id; 

		string nbPersonnesString; 
		int nbPersonnes; 

		int curseur; 
		while ( !file.eof()) {
			getline(file, ligne); 
			if (ligne == "-TABLES") {
					getline(file, ligne); 
				do {
					for (unsigned i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i; 
							break; 
						}
						idString += ligne[i]; 
					}

					id = stoi(idString); 

					nbPersonnesString = ligne.substr(curseur + 1); 
					nbPersonnes = stoi(nbPersonnesString); 

					*this+= new Table(id, nbPersonnes); 
					nbPersonnesString = ""; 
					idString = ""; 					
					getline(file, ligne);

				} while (ligne[0] != '-' && !file.eof());
			}
		}
		file.close(); 
	}
}

Restaurant& Restaurant::operator+=(Table* table) {
	tables_.push_back(new Table(*table)); 
	return *this;
}

void Restaurant::placerClients(Client* client) {
	int indexTable = -1;
	int minimum = 100;

	for (unsigned i = 0; i < tables_.size(); i++) {
		if (i != INDEX_TABLE_LIVRAISON) {
			if (!tables_[i]->estOccupee() && (tables_[i]->getNbPlaces() < minimum) 
				&& (tables_[i]->getNbPlaces() >= client->getTailleGroupe())) {
				minimum = tables_[i]->getNbPlaces();
				indexTable = i;
			}
		}
	}
	if (indexTable != -1) {
		tables_[indexTable]->placerClients(client->getTailleGroupe());
		tables_[indexTable]->setClientPrincipal(client);
	} else 
		cout << "Il n'y pas de table disponible pour les clients." << endl;
}

void Restaurant::livrerClient(Client * client, vector<string> commande){
	Table* tableLivraison = tables_[INDEX_TABLE_LIVRAISON];
	if (client->getStatut() == Prestige) {
		cout << "Début livraison ..." << endl;
		tableLivraison->setClientPrincipal(client);
		tableLivraison->placerClients(client->getTailleGroupe());
		for (unsigned i = 0; i < commande.size(); i++) {
			commanderPlat(commande[i], tableLivraison->getId());
		}

		cout << "Statut de la table de livraison : (table numéro " << tableLivraison->getId() << "):" << endl;
		cout << *tableLivraison << endl;
		cout << "Fin de la livraison!" << endl;
		libererTable(tableLivraison->getId());
	}
	else
		cout << "Le statut du client " << client->getPrenom() << " " << client->getNom() <<
		" ne lui permet pas la livraison." << endl;
}

double Restaurant::calculerReduction(Client* client, double montant, bool livraison) {
	if (client->getStatut() == Fidele) {
		if (static_cast<ClientRegulier*>(client)->getNbPoints() > SEUIL_DEBUT_REDUCTION) {
			return { -montant * TAUX_REDUC_REGULIER };
		} else
			return 0;
	} else {
		double fraisLiv = 0;
		if (static_cast<ClientPrestige*>(client)->getNbPoints() < SEUIL_LIVRAISON_GRATUITE && livraison) {
			fraisLiv = fraisTransport_[static_cast<ClientPrestige*>(client)->getAddresseCode()];
		}
		return { -montant * TAUX_REDUC_PRESTIGE + fraisLiv};
	}
}

void Restaurant::lireAdresses(const string & fichier){
ifstream file(fichier, ios::in);
	if (file) {
		string ligne;
		string addresseCodeStr;
		int addressCode;

		string fraisStrg;
		double frais;

		int curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-ADDRESSES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (unsigned i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						addresseCodeStr += ligne[i];
						addressCode = stoi(addresseCodeStr);
						}

					fraisStrg = ligne.substr(curseur + 1);
					frais = stod(fraisStrg);
					fraisTransport_[addressCode] = frais;
					addresseCodeStr = "";
					fraisStrg = "";
					}
				}
			}
		file.close();
	}
}