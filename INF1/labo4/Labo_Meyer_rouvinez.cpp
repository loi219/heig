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
#include <cmath>

#define FLUSH_BUFFER while( cin.get() != '\n' )

using namespace std;

int main() {

    const int   MIN_COUT_PRECISION  = 1;
    const int   MAX_COUT_PRECISION  = 5;
    const int   SET_W               = 10;
    const int   SET_W_FIRST         = 3;

    const       string ERREUR = "Erreur dans la precision";

    char        choixContinuer;
    double      sum,
                valPrecedente       = 2.,
                ecart;
    int         num,
                denum,
                terme,
                precision;
    bool        saisieCtrl;

    cout.fixed;

    do {
        do {

            cout << "quelle precision [ 10^-"  << MIN_COUT_PRECISION << " 10^-" << MAX_COUT_PRECISION << "]: 10^-";
            saisieCtrl = bool(cin >> precision);


            if (!saisieCtrl){
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }


        } while (precision < MIN_COUT_PRECISION || precision > MAX_COUT_PRECISION || !saisieCtrl);


        cout << setw(SET_W_FIRST) << "No" << setw(SET_W) << "Terme" << setw(SET_W) << "Pi/2" << setw(SET_W) << "Ecart"
             << endl;

        num     = 2;
        denum   = 1;
        sum     = terme = 1;
        while (true) {
            sum *= (double) num / denum;

            ecart = abs(sum - valPrecedente);
            if (ecart <= pow(10, -precision) && ecart)
                break;

            cout << setw(SET_W_FIRST) << terme << setw(SET_W) << num << "/" << setw(SET_W_FIRST) << denum << setw(SET_W)
                 << setprecision(1 + precision) << sum << setprecision(5) << setw(SET_W) << ecart << endl;

            if (num > denum) {
                denum += 2;
            } else {
                num += 2;
            }

            valPrecedente = sum;
            ++terme;
        }
        cout << "Approximation de de Pi/2: " << setprecision(1 + precision) << sum << endl;

        cout << "Nombres de termes: " << terme << endl;


        cout << "Voulez-vous continuer [o/n]:";
        saisieCtrl = bool(cin >> choixContinuer);
        if (!saisieCtrl) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

    } while (choixContinuer != 'n');


    return EXIT_SUCCESS;
}
