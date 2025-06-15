#ifndef FACHNOTE_H
#define FACHNOTE_H

#include <string>
#include "benotung.h"

class fachnote final{
    public:
        const std::string fach;
        const benotung note;

        fachnote(const std::string& fach, const benotung& note);
};
#endif