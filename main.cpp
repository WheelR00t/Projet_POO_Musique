#include "Instrument.cpp"

#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <filesystem>
#include <algorithm>
#include <string>
#include <conio.h>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

void listAvailableSheets(const string& directory) {
    cout << "Partitions disponibles dans " << directory << " :\n";
    for (const auto& entry : filesystem::directory_iterator(directory)) {
        if (entry.path().extension() == ".txt") {
            cout << " - " << entry.path().filename().string() << "\n";
        }
    }
}

void readSheetFromFile(const string& filePath) {
    ifstream file(filePath);
    if (!file) {
        cerr << "Erreur : impossible d'ouvrir le fichier " << filePath << ".\n";
        return;
    }

    int speedChoice;
    cout << "Choisissez la vitesse de lecture des notes (1 = très rapide, 5 = très lent) : ";
    cin >> speedChoice;

    if (speedChoice < 1 || speedChoice > 5) {
        cerr << "Vitesse invalide. La valeur doit être entre 1 et 5.\n";
        return;
    }

    double delay = 0.1 + (speedChoice - 1) * 0.475;

    cout << "Lecture de la partition...\n";
    string note;
    while (file >> note) {
        if (note == "Do" || note == "Ré" || note == "Mi" || note == "Fa" ||
            note == "Sol" || note == "La" || note == "Si" || note == ",") {
            if (note != ",") {
                cout << note << "\n";
            }
            this_thread::sleep_for(chrono::milliseconds(static_cast<int>(delay * 1000)));
        } else {
            cout << "Note invalide détectée : " << note << "\n";
        }
    }
    file.close();
    cout << "Fin de la lecture de la partition.\n";
}

void readSheet() {
    while (true) {
        cout << "Voulez-vous :\n";
        cout << "1. Lire les partitions par défaut\n";
        cout << "2. Importer une partition\n";
        cout << "3. Retour\n";
        cout << "Votre choix : ";

        int choice;
        cin >> choice;

        string filePath;

        if (choice == 1) {
            const string directory = "ressources/sheets";
            listAvailableSheets(directory);

            cout << "Entrez le nom du fichier (avec extension) à lire parmi les fichiers listés : ";
            string fileName;
            cin >> fileName;

            filePath = directory + "/" + fileName;

        } else if (choice == 2) {
            cout << "Entrez le chemin complet du fichier texte contenant la partition : ";
            cin >> filePath;
        } else if (choice == 3) {
            break;
        } else {
            cerr << "Choix invalide. Veuillez réessayer.\n";
            continue;
        }

        readSheetFromFile(filePath);

        char repeatChoice;
        cout << "Voulez-vous lire une autre partition ? (o/n) : ";
        cin >> repeatChoice;

        if (repeatChoice == 'n' || repeatChoice == 'N') {
            cout << "Retour au menu principal.\n";
            break;
        }
    }
}

void createMelody() {
    string melody;
    cout << "Entrez une suite de notes (séparées par un espace, ex : Do Ré Mi Mi Fa) : ";
    cin.ignore();
    getline(cin, melody);

    const string outputDir = "ressources/userSheets";
    const string outputPath = outputDir + "/MaPartition.txt";
    filesystem::create_directories(outputDir);

    ofstream outFile(outputPath);
    if (!outFile) {
        cerr << "Erreur : impossible de créer le fichier " << outputPath << ".\n";
        return;
    }

    outFile << melody;
    outFile.close();

    cout << "La mélodie a été enregistrée avec succès dans le fichier : " << outputPath << "\n";
}*/

void jouerNotes() {
    cout << "Souhaitez-vous essayer virtuellement l'instrument ? (o/n) : ";
    char choix;
    cin >> choix;
    if (choix == 'o' || choix == 'O') {
        string model = "Technica Llyit Shouldbefine II";
        cout << "Vous êtes actuellement en train de simuler le modèle : " << model << "\n";
        cout << "Appuyez sur les touches suivantes pour jouer des notes:\n";
        cout << "A - Do    Z - Ré  E - Mi  R - Fa  T - Sol Y - La  U - Si\nAppuyez sur 'Q' pour quitter.\n";

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
                        cout << "Touche non associée à une note.\n";
                        break;
                }
            }
        }
    }
}

int selectAction(const string& instrument) {
    int actionChoice;
    cout << "==================================================\n";
    cout << "Vous avez sélectionné l'instrument : " << instrument << "\n";
    cout << "Que souhaitez-vous faire ?\n";
    cout << "1. Essayer virtuellement l'instrument\n";
    cout << "2. Lire une partition\n";
    cout << "3. Créer une mélodie (à venir)\n";
    cout << "4. Consulter notre catalogue en ligne\n";
    cout << "5. Choisir un autre instrument\n";
    cout << "==================================================\n";
    cin >> actionChoice;
    return actionChoice;
}

string getInstrument(const unordered_map<string, string>& instruments) {
    cout << "Veuillez sélectionner un type d'instrument à essayer virtuellement\n";
    
    int index = 1;
    unordered_map<string, string> numToInstrument; // Map temporaire pour relier numéros et noms
    for (const auto& pair : instruments) {
        if (pair.first == "0" || pair.first == "quitter") continue; // Ignorer l'option de quitter ici
        if (isdigit(pair.first[0])) continue; // Ignorer les doublons liés aux chiffres déjà définis
        numToInstrument[to_string(index)] = pair.second;
        cout << index << ". " << pair.second << "\n";
        ++index;
    }

    cout << "0. Quitter l'application\n";
    cout << "==================================================\n";
    cout << "Entrez le chiffre ou le nom de l'instrument à essayer : ";
    
    string input;
    cin >> input;

    // Ignore la casse et vérifie dans le map temporaire des numéros
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    if (numToInstrument.find(input) != numToInstrument.end()) {
        return numToInstrument[input];
    }
    
    if (instruments.find(input) != instruments.end()) {
        return instruments.at(input);
    }

    return "invalide";
}

int main()
{
    unordered_map<string, string> instruments = {
        {"1", "piano"}, {"piano", "piano"},
        {"2", "xylophone"}, {"xylophone", "xylophone"},
        {"3", "guitare"}, {"guitare", "guitare"},
        {"0", "quitter"}, {"quitter", "quitter"}
    };

    cout << "==================================================\n";
    cout << "Bienvenue dans l'outil interactif de MusicaLau\n";    
    
    while (true) {
        string instrument = getInstrument(instruments);
        //Instrument piano, guitare;

        if (instrument == "quitter") {
            cout << "Sortie de l'application. Merci de votre visite !\n";
            break;
        } else if (instrument == "invalide") {
            cout << "Saisie invalide. Veuillez réessayer.\n";
        } else {
        
        int choiceAction = selectAction(instrument);
        if (choiceAction == 1) {
                jouerNotes();
            } else if (choiceAction == 2) {
                readSheet();
            } else if (choiceAction == 5) {
                break;
            } else if (choiceAction == 3) {
                //createMelody();
        }
        }
    }    
    return 0;
}