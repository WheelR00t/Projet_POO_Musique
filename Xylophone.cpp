#include "Xylophone.hpp"
#include <conio.h>
#include <iostream>

Xylophone::Xylophone() : Instrument("Xylophone", "ModelX", "Percussion", true) {}

void Xylophone::playNotes(string note) {
    cout << "Playing note " << note << " on the xylophone." << endl;
}

void Xylophone::simulate() {
    cout << "Souhaitez-vous essayer virtuellement l'instrument ? (o/n) : ";
    char choix;
    cin >> choix;
    if (choix == 'o' || choix == 'O') {
        string model = "Yamaha YX-135";
        cout << "Vous etes actuellement en train de simuler le modele : " << model << "\n";
        cout << "Appuyez sur les touches suivantes pour jouer des notes:\n";
        cout << "A - Do / Z - Ré / E - Mi / R - Fa / T - Sol / Y - La / U - Si\nAppuyez sur 'Q' pour quitter.\n";

        while (true) {
            if (_kbhit()) {
                char touche = _getch();
                if (touche == 'q' || touche == 'Q') {
                    cout << "Vous avez quitté l'essai de l'instrument.\n";
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
                    cout << "Touche non associee à une note.\n";
                    break;
                }
            }
        }
    }
}
