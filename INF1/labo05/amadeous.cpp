/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_05_Biefer_Rouvinez
Fichier     : Labo_04_Biefer_Rouvinez.cpp
Auteur(s)   : Julien Biefer et Sven Rouvinez
Date        : 13.11.2016

But         : Afficher un calendrier complet pour une année donnée par l'utilisateur

Remarque(s) : Les paramètres donnés aux fonctions ne sont pas vérifiées.
              Utilisation de l'exercice 3.8 qui donne le nbr de jours dans un mois

Compilateur : Apple LLVM 8.0
-----------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <string>

#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

// Renvoie le jour de la semaine (0-6) pour une date donnée
// Tiré de http://mathforum.org/library/drmath/view/55837.html
int jourSemaine(const int jour, const int mois, const int annee) {
    int d = jour,
            m = mois,
            y = annee;

    if (mois <= 2) {
        m += 12;
        --y;
    }

    return (d + 2*m + (3*(m+1)/5) + y + (y/4) - (y/100) + (y/400)) % 7;
}

// Renvoie true si l'année donnée est bissextile et false sinon
bool estBissextile(const int annee) {
    return (bool) (!(annee % 400) || (!(annee % 4) && (annee % 100)));
}


// Gère la saisie par l'utilisateur d'un int compris entre deux bornes (incluses)
int saisieInt(const string messageSaisie, const int borneMin, const int borneMax) {

    // Définition des variables nécessaires à la saisie
    int  saisie;        // Variable qui contiendra la valeur saisie
    bool saisieOK,
         erreurFlux;

    // Définition des constantes
    const string MSG_ERREUR_FLUX = "Veuillez entrer un nombre entier.";
    const string MSG_ERREUR_SAISIE = "La valeur saisie n'est pas comprise dans l'intervalle.";

    do {
        cout << messageSaisie;
        erreurFlux = bool(cin >> saisie);
        saisieOK = true;

        if (!erreurFlux) {
            cin.clear();
            cout << MSG_ERREUR_FLUX << endl << endl;
            saisieOK = false;
        }
        else if (saisie < borneMin || saisie > borneMax) {
            cout << MSG_ERREUR_SAISIE << endl << endl;
            saisieOK = false;
        }
        VIDER_BUFFER;

    } while(!saisieOK);

    return saisie;
}


// Retourne le nombre de jour pour un mois donné en prenant en compte les années bissextiles
int nbrJoursMois(const int mois, const int annee) {
    int nbrJours;

    switch (mois) {
        case 2:
            nbrJours = estBissextile(annee) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            nbrJours = 30;
            break;
        default :
            nbrJours = 31;
            break;
    }

    return nbrJours;
}


// Retourne le string du mois correspondant au nombre passé en paramètre. Affiche un message s'il ne match à aucun mois
string intMoisEnString(const int numMois) {
    string mois = "";

    switch (numMois) {
        case 0:
            mois = "Janvier";
            break;
        case 1:
            mois = "Fevrier";
            break;
        case 2:
            mois = "Mars";
            break;
        case 3:
            mois = "Avril";
            break;
        case 4:
            mois = "Mai";
            break;
        case 5:
            mois = "Juin";
            break;
        case 6:
            mois = "Juillet";
            break;
        case 7:
            mois = "Aout";
            break;
        case 8:
            mois = "Septembre";
            break;
        case 9:
            mois = "Octobre";
            break;
        case 10:
            mois = "Novembre";
            break;
        case 11:
            mois = "Decembre";
            break;
        default:
            cerr << "Le numero (" << numMois << ") ne correspond a aucun mois de l'annee.";
    }

    return mois;
}


// Retourne la premère lettre (char) du jour de la semaine correspondant au numero passé en paramètre
// Affiche un message s'il ne match à aucun jour
char intJourEnChar(const int numJourSemaine) {
    char jour = 'a';

    // On match le jour de la semaine-1 avec la première lettre du jour en char
    switch (numJourSemaine) {
        case 0:
            jour = 'L';
            break;
        case 1:
        case 2:
            jour = 'M';
            break;
        case 3:
            jour = 'J';
            break;
        case 4:
            jour = 'V';
            break;
        case 5:
            jour = 'S';
            break;
        case 6:
            jour = 'D';
            break;
        default:
            cerr << "Le numero (" << numJourSemaine << ") ne correspond à aucun jour de la semaine.";
    }

    return jour;
}


// Affiche un mois donné en fonction du nombre de jours contenu dans celui-ci et ajoute renvoie le dernier jour
// de la semaine qu'il affiche afin de démarrer le mois suivant le jour d'après.
int afficherMois(const int mois, const int annee, const int debutDuMois) {

    // Définition des variables
    int nbrJours = nbrJoursMois(mois, annee);

    // Définition des constantes
    const int NBR_JOUR_SEMAINE = 7;
    const int W_NUMERO         = 3;

    cout << intMoisEnString(mois) << " " << annee << endl;

    // On affiche les lettres des jours de la semaine
    for(int jour = 0; jour < NBR_JOUR_SEMAINE; ++jour)
        cout << setw(W_NUMERO) << intJourEnChar(jour);

    cout << endl;

    // On affiche les jours du mois dans les bonnes colonnes
    for(int jourMois = 1, compteur = 1; jourMois <= nbrJours; ++compteur) {

        // On affiche d'abord les espaces pour commencer le mois le bon jour
        if (compteur <= debutDuMois) {
            cout << setw(W_NUMERO) << " ";
        }
        // Puis on affiche les dates
        else {
            cout << setw(W_NUMERO) << jourMois++;
        }

        if (!(compteur % 7))
            cout << endl;
    }

    return ((nbrJours + debutDuMois) % 7);
}


//====================================================================================================================
//====================================================================================================================

int main() {

    //==========================================
    // 1. Définition des variables et constantes
    //==========================================

    // 1.1 Définition des constantes
    int annee;                  // L'année demandée par l'utilisateur
    int premierJourAnnee = 0;   // 0 correspond au lundi
    char recommencer;

    // 1.2 Définition de constantes
    const int NB_MOIS = 12;
    const int MIN_ANNEE = 1900;
    const int MAX_ANNEE = 2100;

    //=======================================================
    // 2. Bonjour et présentation programme
    //=======================================================
    cout << "Bonjour, ce programme affiche un calendrier pour une annee donnee." << endl;

    do {

        //=======================================================
        // 3. Saisie de l'année par l'utilisateur
        //=======================================================
        annee = saisieInt("Quelle annee voulez-vous afficher [" + to_string(MIN_ANNEE) +
                                                            "-" + to_string(MAX_ANNEE) + "] : ", MIN_ANNEE, MAX_ANNEE);

        //=======================================================
        // 4. Détermination du jour de la semaine au 1er janvier
        //=======================================================
        premierJourAnnee = jourSemaine(1, 1, annee);

        //=======================================================
        // 5. Affichage de chaque mois
        //=======================================================
        cout << "Voici le calendrier pour l'annee " << annee << "." << endl;

        for(int mois = 0, premierJourMoisSuivant = premierJourAnnee; mois < NB_MOIS; ++mois) {
            premierJourMoisSuivant = afficherMois(mois, annee, premierJourMoisSuivant);
            cout << endl << endl;
        }
        cout << endl;

        //=======================================================
        // 6. Demande si l'utilisateur veut relancer le programme
        //=======================================================
        cout << "Voulez-vous afficher une autre annee [o|n] ? ";
        cin >> recommencer;
	VIDER_BUFFER;
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

