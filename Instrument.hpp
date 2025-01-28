#ifndef DEF_INSTRUMENT
#define DEF_INSTRUMENT

#include <string>
#include <iostream>

using namespace std;

class Instrument {
    private :

    int position;
    string name;
    string model;
    string soundType;
    bool soundBankAvailable;
    //string typeInstrument;

    public :

    Instrument();
    ~Instrument();

    void playNotes(string note);
    void simulate(string nomInstrument);
    void displayDetails();

};

#endif