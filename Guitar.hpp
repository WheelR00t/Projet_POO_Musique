#ifndef GUITAR_HPP
#define GUITAR_HPP

#include "Instrument.hpp"

using namespace std;

class Guitar : public Instrument {
public:
    Guitar();
    void playNotes(string note) override;
    void simulate() override;
};

#endif
