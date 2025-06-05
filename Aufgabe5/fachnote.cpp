#include "fachnote.h"
#include <string.h>

fachnote::fachnote(const std::string& fach, const benotung& note){
    if(strlen(fach) == 0){
        throw std::invalid_argument();
    }
    this.fach = fach;
    this.note = note;
}