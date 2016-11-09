/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_05_Biefer_Rouvinez
Fichier     : Labo_04_Biefer_Rouvinez.cpp
Auteur(s)   : Julien Biefer et Sven Rouvinez
Date        : 09.11.2016

But         : Afficher un calendrier complet pour une année donnée par l'utilisateur

Remarque(s) : Utilisation de l'exercice 3.8 qui donne le nbr de jours dans un mois

Compilateur : Apple LLVM 8.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <limits>
// Il faudra include le fichier pour les fonctions

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

bool estBissextile(const int annee) {
    return (bool) !(annee % 400) || (!(annee % 4) && (annee % 100));
}

int main() {

    //==========================================
    // 1. Définition des variables et constantes
    //==========================================

    // 1.1 Définition des constantes
    unsigned int annee;     // L'année demandée par l'utilisateur
    char recommencer;
    enum class Jour {LU = 'L', MA = 'M', ME = 'M', JE = 'J', VE = 'V', SA = 'S', DI = 'D'};

    // 1.2 Définition de constantes
    const int NB_MOIS   =   12;
    const int MIN_ANNEE = 1900;
    const int MAX_ANNEE = 2100;

    // 1.3 Définition de l'affichage

    //=======================================================
    // 2. Bonjour et présentation programme
    //=======================================================
    cout << "Bonjour, ce programme affiche un calendrier pour une annee donnee." << endl;

    do {

        //=======================================================
        // 3. Saisie de l'année par l'utilisateur
        //=======================================================

        //            /!\ Il faudra include le fichier pour les fonctions !
        annee = saisieInt("Veuillez saisir une annee a afficher : ", MIN_ANNEE, MAX_ANNEE);

        //=======================================================
        // 4. Calculs
        //=======================================================
        // 4.1 L'année est-elle bissextile ? Si oui, février a 30 jours.
        cout << boolalpha << estBissextile(annee) << endl;

        //=======================================================
        // 5. Affichage de chaque mois
        //=======================================================
        for(int mois = 1; mois <= NB_MOIS; ++mois) {
            // Fonction pour affichage ?
            // afficherMois("mois", nbJour, premierJourSemaine) ?
            // afficherMois(numMois, premierJourSemaine) ?
        }

        //=======================================================
        // 6. Demande si l'utilisateur veut relancer le programme
        //=======================================================
        cout << "Voulez-vous afficher une autre annee [o|n] ? ";
        cin >> recommencer;
        cout << endl;

    } while(toupper(recommencer) == 'O');

    //==============
    // 7. Au revoir.
    //==============
    cout << "Merci d'avoir utilise le programme !"       << endl;
    cout << "Pressez ENTER pour quitter le programme..." << endl;
    VIDER_BUFFER;

    return EXIT_SUCCESS;
}

