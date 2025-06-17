/*
 * fachnote.h
 *
 * Author Tom Bonsiep
 * Erstellt am: 17.06.2025
 * Zuletzt geändert: 17.06.2025
 */

#ifndef FACHNOTE_H
#define FACHNOTE_H

#include <string>
#include "benotung.h"

class fachnote final
{
public:
    const std::string fach;
    const benotung note;

    // invalid operations
    fachnote(const std::string& fach, const benotung& note);
    fachnote() = delete;
    fachnote(const fachnote &f) = delete;
    fachnote(fachnote &&f) = delete;
    fachnote &operator=(const fachnote &f) = delete;
    fachnote &operator=(fachnote &&f) = delete;
};
#endif