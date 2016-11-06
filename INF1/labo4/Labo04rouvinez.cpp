/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_04_rouvinez
 Fichier     : Labo04rouvinez.cpp
 Auteur(s)   : Sven Rouvinez
 Date        : 06.11.2016

 But         :

 Remarque(s) : -

 Compilateur : g++ (GCC) 6.2.1 20160916 (Red Hat 6.2.1-2)
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <iomanip>
#include <stdlib.h>

#define FLUSH_BUFFER while( cin.get() != '\n' )

using namespace std;

int main() {

	const double MIN_PRECISION = 10.0e-0;
	const double MAX_PRECISION = 10.0e-5;

	const int MIN_COUT_PRECISION = 0;
	const int MAX_COUT_PRECISION = 5;
	const int SET_W = 10;

	const string ERREUR = "Erreur dans la précision";

	char choixContinuer;

	double precision;
	bool saisieCtrl;

	cout.fixed;

	do {
		do {

			cout << "quelle précision [ 10^-" + to_string(MIN_COUT_PRECISION) + " … 10^-" +
			        to_string(MAX_COUT_PRECISION) +
			        "]: 10^-";
			saisieCtrl = bool(cin >> precision);


			if (!saisieCtrl) {
				cin.clear();
				cin.ignore(INT_MAX,'\n');
			}


		} while ((precision < MIN_COUT_PRECISION) || (precision > MAX_COUT_PRECISION) || !saisieCtrl);


		cout << "No" << setw(SET_W) << "Terme" << setw(SET_W) << "Pi/2" << setw(SET_W) << "Ecart" << endl;
		//TODO boucle calcul

		//TODO add var result
		cout << "Approximation de de Pi/2: " << endl;

		//TODO add var result
		cout << "Nombres de termes: " << endl;


		cout << "Voulez-vous continuer [o/n]:";
		saisieCtrl = bool(cin >> choixContinuer);
		if(!saisieCtrl){
			cin.clear();
			cin.ignore('n','\n');
		}

	} while (choixContinuer != 'n');


	return EXIT_SUCCESS;
}
