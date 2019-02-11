/*
* Titre : Restaurant.cpp - Travail Pratique #2
* Date : 11 Fevrier 2019
* Auteurs : Diab Khanafer et Charles-Etienne Desormeaux
* Description : Creer un restaurant ainsi que ses attributs.
*/

#include "Restaurant.h"

/*
* Constructeur par défaut de la classe Restaurant
* Le nom sera "inconnu", le moment de la journée est MATIN et le chiffre d'affaire est null
* Les menu du matin, midi et soir pointent vers rien
*/
Restaurant::Restaurant() {
	nom_ = new string("Inconnu");

	chiffreAffaire_ = 0;

	momentJournee_ = Matin;

	menuMatin_ = new Menu("menu.txt", Matin);
	menuMidi_ = new Menu("menu.txt", Midi);
	menuSoir_ = new Menu("menu.txt",  Soir);

	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
}

/*
* Constructeur avec paramétres de la classe Restauraut
* Prend en paramètre l'adresse d'un fichier, l'addresse d'un nom et le moment de la journée (Matin, midi, soir)
* Les variables correspondantes au paramètres sont initialisées
* La liste de table est initialisé avec une capacité
* Les différents menu de la journée sont initialisés
* La fonction lireTable charge les valeurs des tables progvenant du document
*/
Restaurant::Restaurant(const string& fichier,  const string& nom, TypeMenu moment) {
	nom_ = new string(nom);

	chiffreAffaire_ = 0;

	momentJournee_ = moment;

	menuMatin_ = new Menu(fichier, Matin);
	menuMidi_ = new Menu(fichier,  Midi);
	menuSoir_ = new Menu(fichier,  Soir);

	capaciteTables_ = INTTABLES;
	nbTables_ = 0;
	
	lireTable(fichier);
}
/*
* In: Variable de type Restaurant
* Creer un objet Restaurant ayant les memes attributs que ce restaurant-ci
* et ajoute ses tables dans le vecteur de tables
*/
Restaurant::Restaurant(const Restaurant& resto){
	menuMatin_ = new Menu(*resto.menuMatin_);
	menuMidi_ = new Menu(*resto.menuMidi_);
	menuSoir_ = new Menu(*resto.menuSoir_);
	nom_ = new string(*resto.nom_);
	chiffreAffaire_ = resto.chiffreAffaire_;
	momentJournee_ = resto.getMoment();
	capaciteTables_ = resto.capaciteTables_;
	nbTables_ = resto.nbTables_;

	for (int i = 0; i < resto.nbTables_; i++) {
		Table* table = new Table(resto.tables_[i]->getId(), resto.tables_[i]->getNbPlaces());
		*table = *resto.tables_[i];
		tables_.push_back(table);
	}
}

//destructeur de la classe
Restaurant::~Restaurant() {
	delete nom_;
	delete menuMatin_;
	delete menuMidi_;
	delete menuSoir_;
	
	tables_.clear();
}

/*
* in: moment de la journee de type TypeMenu
* out: variable privee de la classe ayant la valeur du in
* Set la variable privee momentJournee_ à la variable in
*/
void Restaurant::setMoment(TypeMenu moment) {
	momentJournee_ = moment;
}

/*
* in: nom du restautant
* out: variable privee de la classe ayant la valeur du in
* Set la variable privee nom_ à la variable in
*/
void Restaurant::setNom(const string& nom){
	nom_ = new string(nom);
}

/*
* Out: pointeur string
* Renvoie un pointeur vers nom_
*/
string Restaurant::getNom() const {
	return *nom_;
}

/*
* Out: variable de type TypeMenu
* Renvoie la variable privee momentJournee
*/
TypeMenu Restaurant::getMoment() const {
	return momentJournee_;
}

//autres methodes
/*
* In: id de la table
* Libere un table de ses clients, calcule le chiffre d'affaire produit par cette table
* et la "reset"
*/
void Restaurant::libererTable(int id) {
	for (int i = 0; i < nbTables_; i++) {
		if (id == tables_[i]->getId()) {
			chiffreAffaire_ += tables_[i]->getChiffreAffaire();
			tables_[i]->libererTable();
		}
	}
}

/*
* In: nom du plat et l'id de la table
* Commande un plat pout la table selon l'id recu en paramètre, ajoute le plat à la liste de commande
*/
void Restaurant::commanderPlat(const string& nom, int idTable) {
	Plat* plat = nullptr;
	int index;
	for (int i = 0; i < nbTables_; i++) {
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
		}
	}
	if (plat != nullptr && tables_[index]->estOccupee()) {
		tables_[index]->commander(plat);
	}
	else cout << "Erreur : table non occupee ou plat introuvable" << endl;
}

/*
* In: nom du fichier
* Lit les tables provenant du fichier, les creer et les place dans la liste de table
*/
void Restaurant::lireTable(const string& fichier) {
	ifstream file(fichier, ios::in);

	if (file) {
		string ligne, idString, nbPersonnesString;
		int id, nbPersonnes, curseur;
		while (!file.eof()) {
			getline(file, ligne);
			if (ligne == "-TABLES") {
				while (!file.eof()) {
					getline(file, ligne);
					for (int i = 0; i < ligne.size(); i++) {
						if (ligne[i] == ' ') {
							curseur = i;
							break;
						}
						idString += ligne[i];
					}
					id = stoi(idString);
					nbPersonnesString = ligne.substr(curseur + 1);
					nbPersonnes = stoi(nbPersonnesString);
					Table* table = new Table(id, nbPersonnes);
					*this += table;
					nbPersonnesString = "";
					idString = "";
				}
			}
		}
		file.close();
	}
}

/*
* In: nombre de client
* Place les clients à la table approprié, sinon affiche qu'il n'est pas possible
*/
void Restaurant::placerClients(int nbClients) {
	int indexTable = -1;
	int minimum = 100;

	for (int i = 0; i < nbTables_; i++) {
		if (tables_[i]->getNbPlaces() >= nbClients && !tables_[i]->estOccupee() && tables_[i]->getNbPlaces() < minimum) {
			indexTable = i;
			minimum = tables_[i]->getNbPlaces();
		}
	}
	if (indexTable == -1) {
		cout << "Erreur : il n'y a plus/pas de table disponible pour le client. " << endl;
	}else
	tables_[indexTable]->placerClient(nbClients);
}

/*
* In/out: stream de l'output
* In: Restaurant a afficher
* Out: string contenant les informations du menu
* Surcharge de l'operateur <<. Remplace la methode d'affichage.
*/
ostream & operator<<(ostream & o, const Restaurant & resto){
	cout << "Le restaurant " << *resto.nom_;
	if (resto.chiffreAffaire_ != 0) {
		cout << " a fait un chiffre d'affaire de : " << resto.chiffreAffaire_ << "$" << endl;
	} else {
		cout << " n'a pas fait de benefice ou le chiffre n'est pas encore calcule." << endl;
	}
	cout << "-Voici les tables : " << endl;
	for (int i = 0; i < resto.nbTables_; i++) {
		cout << "\t";
		cout << *resto.tables_[i];
	}
	cout << "-Voici son menu : " << endl;
	cout << *resto.menuMatin_;
	cout << *resto.menuMidi_;
	cout << *resto.menuSoir_;
	return o;
}

/*
* In: Table a ajouter
* Surcharge de l'operateur +=. Ajoute la table a la liste de table
*/
void Restaurant::operator+=(Table* table) {
	tables_.push_back(table);
	nbTables_++;
}

/*
* In: Restaurant a comparer
* Out: Return vrai ou faux si le restaurant en parametre a un plus gros chiffre d'affaire
* Surcharge de l'operateur <. Compare les deux chiffres d'affaires
*/
bool Restaurant::operator<(const Restaurant & resto) {
	return (chiffreAffaire_ < resto.chiffreAffaire_);
}

/*
* In: Restaurant a copier
* Out: Return la reference au restaurant copie
* Surcharge de l'operateur =. Copie le restaurant dans un autre objet.
*/
Restaurant& Restaurant::operator=(const Restaurant& resto) {
	menuMatin_ = new Menu(*resto.menuMatin_);
	menuMidi_ = new Menu(*resto.menuMidi_);
	menuSoir_ = new Menu(*resto.menuSoir_);
	nom_ = resto.nom_;
	chiffreAffaire_ = resto.chiffreAffaire_;
	capaciteTables_ = resto.capaciteTables_;
	momentJournee_ = resto.momentJournee_;
	nbTables_ = resto.nbTables_;

	tables_.clear();
	for (int i = 0; i < resto.tables_.size(); i++){
		tables_.push_back(resto.tables_[i]);
    }
	return *this;
}
