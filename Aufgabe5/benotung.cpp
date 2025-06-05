#include "benotung.h"
#include <stdexcept>

benotung::beste = new benotung(10);
benotung::schlechteste = new benotung(50);

benotung::benotung(int note): note(note)
{
    switch(note){
        case 10, 13, 17, 20, 23, 27, 30, 33, 37, 40, 50:
            break;
        default: throw std::invalid_argument("unzulaessige Note " + note);
    }
    
}

int benotung::int_value(){
    return this.note;
}

bool benotung::ist_bestanden(){
    return !(this == schlechteste);
}

bool benotung::operator==(benotung b1, benotung b2){
    return b1.int_value() == b2.int_value();
}