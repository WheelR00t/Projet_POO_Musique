#include "Guitar.hpp"
#include <conio.h>
#include <iostream>

using namespace std;

Guitar::Guitar() : Instrument("Guitar", "ModelG", "String", true) {}

void Guitar::playNotes(string note) {
    cout << "Playing note " << note << " on the guitar." << endl;
}

void Guitar::simulate() {
    cout << "Souhaitez-vous essayer virtuellement l'instrument ? (o/n) : ";
    char choix;
    cin >> choix;
    if (choix == 'o' || choix == 'O') {
        string model = "Fender Stratocaster";
        cout << "Vous etes actuellement en train de simuler le modèle : " << model << "\n";
        cout << "Appuyez sur les touches suivantes pour jouer des notes:\n";
        cout << "A - Do / Z - Re / E - Mi / R - Fa / T - Sol / Y - La / U - Si\nAppuyez sur 'Q' pour quitter.\n";

        while (true) {
            if (_kbhit()) {
                char touche = _getch();
                if (touche == 'q' || touche == 'Q') {
                    cout << "Vous avez quitte l'essai de l'instrument.\n";
                    break;
                }

                switch (touche) {
                case 'a':
                    cout << "Do\n";
                    break;
                case 'z':
                    cout << "Re\n";
                    break;
                case 'e':
                    cout << "Mi\n";
                    break;
                case 'r':
                    cout << "Fa\n";
                    break;
                case 't':
                    cout << "Sol\n";
                    break;
                case 'y':
                    cout << "La\n";
                    break;
                case 'u':
                    cout << "Si\n";
                    break;
                default:
                    cout << "Touche non associee a une note.\n";
                    break;
                }
            }
        }
    }
}
