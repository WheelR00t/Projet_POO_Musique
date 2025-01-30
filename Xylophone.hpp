#ifndef XYLOPHONE_HPP
#define XYLOPHONE_HPP

#include "Instrument.hpp"

using namespace std;

class Xylophone : public Instrument {
public:
    Xylophone();
    void playNotes(string note) override;
    void simulate() override;
};

#endif
