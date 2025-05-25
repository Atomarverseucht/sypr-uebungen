#include <limits.h>
#define _POSIX_C_SOURCE 200112L

#ifndef FILEINFO_H
#define FILEINFO_H

enum f_type {filetype_file, filetype_directory, filetype_other};

typedef struct f_info{
    char name[NAME_MAX];
    enum f_type type;
    union{
        long long fileLength; // wenn type = file
        struct f_info* down; // wenn type = directory
    };

    struct f_info* next; 
} fileinfo;


fileinfo* fileinfo_create(const char* f_name);

void fileinfo_destroy(fileinfo* in);

void fileinfo_print(fileinfo* in);

#endif