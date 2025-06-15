#include "fachnote.h"
#include <string>

fachnote::fachnote(const std::string& fach, const benotung& note): fach(fach); note(note){
    if(strlen(fach) == 0){
        throw std::invalid_argument();
    }
}