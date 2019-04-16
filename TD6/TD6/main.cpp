#include "mainwindow.h"
#include "Menu.h"
#include "Filtre.h"
#include "Commande.h"
#include <QString>
#include <QApplication>
#include "erreurfichierintrouvable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString chemin = "C:\\Users\\diabk\\Dropbox\\Poly\\Hiver 2019\\INF1010 - Programmation orientée objet\\TD\\INF1010_TD\\TD6\\TD6"; // INSERER CHEMIN ABSOLU VERS polyFood.txt
    try {
        Menu menu = Menu(chemin+FICHIER_POLYFOOD);
        Filtre filtre(&menu);
        Commande commande;
        MainWindow mainGui(&commande, &filtre, &menu);


        //TODO
        //Connecter les mises a jour de la vue en fonction du modele (plats filtres + plats commande + prix)
        QObject::connect(&commande, SIGNAL(commandeModifie()), &mainGui, SLOT(mettreAJourPlatsCommande()));
        QObject::connect(&commande, SIGNAL(commandeModifie()), &mainGui, SLOT(mettreAJourPrix()));
        QObject::connect(&commande, &Filtre::choixFiltrageModifie, &mainGui, &MainWindow::mettreAJourPlatsFiltres);

        mainGui.show();
        return a.exec();

    } catch (ErreurFichierIntrouvable erreur) {
        QMessageBox mbox;
        mbox.setText(erreur.what());
        mbox.show();
        return a.exec();
    }

}
