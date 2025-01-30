#ifndef PIANO_HPP
#define PIANO_HPP

#include "Instrument.hpp"

using namespace std;

class Piano : public Instrument {
public:
    Piano();
    void playNotes(string note) override;
    void simulate() override;
};

#endif
