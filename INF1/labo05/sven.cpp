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


#define FLUSH_BUFFER cin.ignore(numeric_limits<streamsize>::max(),'\n')

using namespace std;


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


int afficherMois() {
	cout.fixed;
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

	cout << (char) Jour::LU << setw(SET_W) << (char) Jour::MA << setw(SET_W) << (char) Jour::ME << setw(SET_W)
	     << (char) Jour::JE << setw(SET_W) << (char) Jour::VE << setw(SET_W) << (char) Jour::SA << setw(SET_W)
	     << (char) Jour::DI<< endl;

	for(int i =1;i<=30;i++){
		if(!(i%7)){
			cout << '\n';

		}
		cout << i<<setw(SET_W);

	}

}

int main() {


	const int BORNE_MAX = 2100;
	const int BORNE_MIN = 1900;
	int saisieUtilisateur;
	const string MESSAGE_ENTREE =
			"Veuillez entrer une date entre " + to_string(BORNE_MAX) + " et " + to_string(BORNE_MIN) + ": ";
	const string MESSAGE_ERREUR = "Erreur, entrez à nouveau votre date: ";


	//int dateUtilisateur=saisieInt(MESSAGE_ENTREE, MESSAGE_ERREUR, BORNE_MAX, BORNE_MIN);


	afficherMois();
	return EXIT_SUCCESS;
}
