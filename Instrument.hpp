#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include <iostream>
#include <string>

using namespace std;

class Instrument {
protected:
    string name;
    string model;
    string soundType;
    bool soundBankAvailable;

public:
    Instrument(string name, string model, string soundType, bool soundAvailable);
    virtual ~Instrument() = default;

    virtual void playNotes(string note) = 0; 
    virtual void simulate() = 0; 
    virtual void displayDetails();
};

#endif
