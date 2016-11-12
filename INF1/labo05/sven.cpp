/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_05
 Fichier     : sven
 Auteur(s)   : Sven Rouvinez
 Date        : 09.11.2016

 But         :

 Remarque(s) : -

 Compilateur : g++ (GCC) 6.2.1 20160916 (Red Hat 6.2.1-2)
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>


using namespace std;


bool estBissextile(int annee) {
	return (bool) ! (annee % 400) || (! (annee % 4) && (annee % 100));
}


/**
 * Contrôle le flux d'entrée
 * @saisieUtilisateur: valeur entrée par l'utilisateur
 * @messageEntree: message d'invitation pour entrer la valeur
 * @messageErreur: message d'erreur si valeur fausse
 * @borneMax: borne maximum
 * @borneMin: borne minimum
 * @return: valeur si correct ou message d'erreur
 * */
int saisieInt(string messageEntree, string messageErreur, int borneMax, int borneMin) {

	int saisieUtilisateur;

	cout << messageEntree;
	cin >> saisieUtilisateur;

	bool saisieCtrl = (bool) saisieUtilisateur;


	while (saisieUtilisateur < borneMin || saisieUtilisateur > borneMax || ! saisieCtrl) {


		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		cerr << messageErreur << endl;
		cin >> saisieUtilisateur;
		(bool) saisieUtilisateur;

	}

	return saisieUtilisateur;
}


void afficherMois(int nbreJours, int annee, string mois) {

	const int SET_W = 3;

	enum class Jour {
		LU = 'L'
		, MA = 'M'
		, ME = 'M'
		, JE = 'J'
		, VE = 'V'
		, SA = 'S'
		, DI = 'D'
	};


	cout << mois<< " " << annee << endl;

	cout << (char) Jour::LU << setw(SET_W) << (char) Jour::MA << setw(SET_W) << (char) Jour::ME << setw(SET_W)
	     << (char) Jour::JE << setw(SET_W) << (char) Jour::VE << setw(SET_W) << (char) Jour::SA << setw(SET_W)
	     << (char) Jour::DI << endl;
if(mois == "Fevrier"){
	cout << setw(10);


}
	for (int jours = 1; jours <= nbreJours; jours ++) {

		if (! (jours % 7)) {
			cout << jours << '\n';

		} else {
			cout << jours << setw(SET_W);
		}

	}
	cout << endl;
}

int main() {

	const int NBRE_MOIS = 12;
	const int NBRE_JOURS_30 = 30;
	const int NBRE_JOURS_31 = 31;

	const int BORNE_MAX = 2100;
	const int BORNE_MIN = 1900;
	const string MESSAGE_ENTREE =
			"Veuillez entrer une date entre " + to_string(BORNE_MAX) + " et " + to_string(BORNE_MIN) + ": ";
	const string MESSAGE_ERREUR = "Erreur, entrez à nouveau votre date: ";

	int annee = 2014;

	//int dateUtilisateur=saisieInt(MESSAGE_ENTREE, MESSAGE_ERREUR, BORNE_MAX, BORNE_MIN);
	for (int moisActuel = 1; moisActuel <= NBRE_MOIS; moisActuel ++) {

		switch (moisActuel) {
			case 1:
				afficherMois(31, annee, "Janvier");
				break;

				//{} sont obligatoires car nombreJoursFev ne doit pas être disponible pour les autres cas
			case 2: {
				int nombreJoursFev = 28;
				if (estBissextile(annee)) { nombreJoursFev = 29; }
				afficherMois(nombreJoursFev, annee, "Fevrier");
				break;
			}
			case 3:
				afficherMois(31, annee, "Mars");
				break;
			case 4:
				afficherMois(30, annee, "Avril");
				break;
			case 5:
				afficherMois(31, annee, "Mai");
				break;
			case 6:
				afficherMois(30, annee, "Juin");
				break;
			case 7:
				afficherMois(31, annee, "Juillet");
				break;
			case 8:
				afficherMois(31, annee, "Aout");
				break;
			case 9:
				afficherMois(30, annee, "Septembre");
				break;
			case 10:
				afficherMois(31, annee, "Octobre");
				break;
			case 11:
				afficherMois(30, annee, "Novembre");
				break;
			case 12:
				afficherMois(31, annee, "Decembre");
				break;
			default:
				EXIT_FAILURE;
				break;
		}


		cout << endl;
	}


	return EXIT_SUCCESS;
}
