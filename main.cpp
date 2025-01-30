#include "Instrument.cpp"
#include "Piano.cpp"
#include "Guitar.cpp"
#include "Xylophone.cpp"

#include <unordered_map>
#include <iostream>
#include <filesystem>
#include <string>
#include <memory>
#include <algorithm>
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
        cout << "1. Lire les partitions par defaut\n";
        cout << "2. Importer une partition\n";
        cout << "3. Retour\n";
        cout << "Votre choix : ";

        int choice;
        cin >> choice;

        string filePath;

        if (choice == 1) {
            const string directory = "ressources/sheets";
            listAvailableSheets(directory);

            cout << "Entrez le nom du fichier (avec extension) à lire parmi les fichiers listes : ";
            string fileName;
            cin >> fileName;

            filePath = directory + "/" + fileName;

        } else if (choice == 2) {
            cout << "Entrez le chemin complet du fichier texte contenant la partition : ";
            cin >> filePath;
        } else if (choice == 3) {
            break;
        } else {
            cerr << "Choix invalide. Veuillez reessayer.\n";
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

unique_ptr<Instrument> createInstrument(const string& name) {
    if (name == "piano") return make_unique<Piano>();
    if (name == "guitare") return make_unique<Guitar>();
    if (name == "xylophone") return make_unique<Xylophone>();
    return nullptr;
}

string selectInstrument(const unordered_map<string, string>& instruments) {
    cout << "Veuillez selectionner un type d'instrument a essayer virtuellement\n";
    
    int index = 1;
    unordered_map<string, string> numToInstrument;
    unordered_map<string, string> nameToInstrument;
    for (const auto& pair : instruments) {
        if (pair.first == "0" || pair.second == "quitter") continue;
        numToInstrument[to_string(index)] = pair.second;
        nameToInstrument[pair.second] = pair.second;
        cout << index << ". " << pair.second << "\n";
        ++index;
    }

    cout << "0. Quitter l'application\n";
    cout << "==================================================\n";
    cout << "Entrez le chiffre ou le nom de l'instrument : ";
    
    string input;
    cin >> input;
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    
    if (numToInstrument.find(input) != numToInstrument.end()) {
        return numToInstrument[input];
    }
    if (nameToInstrument.find(input) != nameToInstrument.end()) {
        return nameToInstrument[input];
    }
    
    return "";
}

int main() {
    unordered_map<string, string> instruments = {
        {"1", "piano"}, {"2", "xylophone"}, {"3", "guitare"}, {"0", "quitter"}
    };

    cout << "==================================================\n";
    cout << "Bienvenue dans l'outil interactif de MusicaLau\n";    
    
    while (true) {
        string chosenInstrument = selectInstrument(instruments);
        if (chosenInstrument.empty() || chosenInstrument == "quitter") {
            cout << "Sortie de l'application. Merci de votre visite !\n";
            break;
        }

        auto instrument = createInstrument(chosenInstrument);
        if (!instrument) {
            cout << "Instrument invalide. Veuillez réessayer.\n";
            continue;
        }

        cout << "==================================================\n";
        cout << "Vous avez selectionne l'instrument : " << chosenInstrument << "\n";
        cout << "1. Essayer virtuellement l'instrument\n";
        cout << "2. Voir les details\n";
        cout << "3. Lire une partition\n";
        cout << "4. Choisir un autre instrument\n";
        cout << "==================================================\n";
        cout << "Entrez votre choix d'action : ";

        int action;
        cin >> action;

        if (action == 1) {
            instrument->simulate();
        } else if (action == 2) {
            instrument->displayDetails();
        } else if (action == 3) {
            readSheet();
        } else if (action == 4) {
            continue;
        }
    }
    return 0;
}
