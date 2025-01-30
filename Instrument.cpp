#include "Instrument.hpp"

using namespace std;

Instrument::Instrument(string name, string model, string soundType, bool soundAvailable)
    : name(name), model(model), soundType(soundType), soundBankAvailable(soundAvailable) {}

void Instrument::displayDetails() {
    cout << "Instrument : " << name << endl;
    cout << "Modèle : " << model << endl;
    cout << "Type de son : " << soundType << endl;
    cout << "État de la banque son : " << (soundBankAvailable ? "Disponible" : "Non disponible") << endl;
}
