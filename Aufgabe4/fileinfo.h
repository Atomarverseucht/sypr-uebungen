/*
 * fileinfo.h
 *
 * struct & Übersicht über Funktionen der Library
 *
 * Author Tom Bonsiep
 * Erstellt am: 29.05.2025
 * Zuletzt geändert: 30.05.2025
 */
#ifndef FILEINFO_H
#define FILEINFO_H

#define _POSIX_C_SOURCE 200112L
#include <limits.h>
#include <stddef.h>

enum f_type {filetype_file, filetype_directory, filetype_other};

typedef struct f_info
{
    char name[NAME_MAX];
    enum f_type type;
    union
    {
        size_t fileLength; // wenn type = file
        struct f_info* down; // wenn type = directory
    };

    struct f_info* next;
} fileinfo;


fileinfo* fileinfo_create(const char* f_name);

void fileinfo_destroy(fileinfo* in);

void fileinfo_print(fileinfo* const in);

#endif