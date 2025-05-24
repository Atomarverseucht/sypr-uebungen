#include <limits.h>
#include <stdio.h>
#include <errno.h>  // errno
#include <string.h> // strerror
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

enum f_type = {filetype_file, filetype_directory, filetype_other};

typedef struct fileinfo{
    char[] name = malloc((NAME_MAX +1) * sizeof(char));
    enum f_type type;
    union{
        long long fileLength;
        struct fileinfo* down; // Ordner
    }file;

    struct fileinfo* next; 
} f_info;


f_info* fileinfo_create(char[] f_name);

void fileinfo_destroy(fileinfo* in);

void fileinfo_print(fileinfo* in);

