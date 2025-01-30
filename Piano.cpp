#include "Piano.hpp"
#include <conio.h>

using namespace std;

Piano::Piano() : Instrument("Piano", "Yamaha U1", "Percussion", true) {}

void Piano::playNotes(string note) {
    cout << "Le piano joue la note : " << note << endl;
}

void Piano::simulate() {
    cout << "Souhaitez-vous essayer virtuellement l'instrument ? (o/n) : ";
    char choix;
    cin >> choix;
    if (choix == 'o' || choix == 'O') {
        string model = "Technica Llyit Shouldbefine II";
        cout << "Vous êtes actuellement en train de simuler le modele : " << model << "\n";
        cout << "Appuyez sur les touches suivantes pour jouer des notes:\n";
        cout << "A - Do / Z - Re / E - Mi / R - Fa / T - Sol / Y - La / U - Si\nAppuyez sur 'Q' pour quitter.\n";

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
                        cout << "Ré\n";
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