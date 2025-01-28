#include "Instrument.hpp"

using namespace std;

Instrument::Instrument()
    : position(1), name("Piano"), model("Itshould Work II"), soundType(""), soundBankAvailable(true)
{
}

Instrument::~Instrument()
{
}


void Instrument::playNotes(string note) {
}

void Instrument::simulate(string nomInstrument) {
}

void Instrument::displayDetails() {
        cout << "Instrument : " << name << endl;;
        cout << "Modèle : " << model << endl;
        cout << "Type de son : " << soundType << endl;
        cout << "Etat de la banque son : ";
        if (soundBankAvailable == true) {
            cout << "entièrement disponible" << endl;
        } else {
            cout << "non disponible" << endl;
        }
        std::cout << endl;
}