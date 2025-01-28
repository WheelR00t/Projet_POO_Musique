#ifndef DEF_PIANO
#define DEF_PIANO

#include "Instrument.hpp"
#include <string>
#include <iostream>

class Piano : public Instrument {        
    public:
        void playPedal() const;
};

#endif