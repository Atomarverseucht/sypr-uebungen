/*
 * fachnote.cpp
 *
 * Author Tom Bonsiep
 * Erstellt am: 17.06.2025
 * Zuletzt geändert: 17.06.2025
 */

#include "fachnote.h"
#include <string>
#include <stdexcept>

fachnote::fachnote(const std::string& fach, const benotung& note): fach(fach), note(note)
{
    if (fach.length() == 0)
    {
        throw std::invalid_argument("Fach darf nicht die Länge 0 haben!");
    }
}