#define _POSIX_C_SOURCE 200112L
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>  // errno
#include <string.h> // strerror
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include "fileinfo.h"
#include <stdbool.h>

static void list_directory(const char* f_name, fileinfo* in);

void fileinfo_print(fileinfo* in);

fileinfo* fileinfo_create(const char* f_name){
    fileinfo* out = malloc(sizeof(fileinfo));
    struct stat sb;
    if(strlen(f_name) > NAME_MAX) { errno = ENAMETOOLONG; return NULL;}
    
    strncpy(out->name, f_name, NAME_MAX);
    lstat(f_name, &sb);
    if(S_ISREG(sb.st_mode)){
        out->type = filetype_file;
        out->fileLength = sb.st_size;
    } else if(S_ISDIR(sb.st_mode)){
        out->type = filetype_directory;
        // Hier Ordner öffnen
        list_directory(f_name, out);
    } else{
        out->type = filetype_other;
    }
    //next wird von list_directory übernommen
    return out;
}

static void list_directory(const char* f_name, fileinfo* in){
    if (chdir(f_name) != 0) {
        perror("chdir");
        exit(1);
    }
    DIR *dir_ = opendir(".");
    if(dir_ == NULL){
        printf("Fehler dir");
        exit(1);
    }
    
    struct dirent *d_ = NULL;
    fileinfo* this = NULL;
    fileinfo* last = NULL;
    _Bool first = true;

    while((d_ = readdir(dir_)) != NULL){
        if (strcmp(d_->d_name, ".") == 0 || strcmp(d_->d_name, "..") == 0) {
            continue;
        }
        this = fileinfo_create(d_->d_name); 
        if(first){
            in->down = this;
            first = false;
        } else{
            last->next = this;
        }
        last = this;
    }

    closedir(dir_);
    chdir("..");
}

void fileinfo_destroy(fileinfo* in){
    if(in == NULL){return;}
    if(in->type == filetype_directory){
        fileinfo_destroy(in->down);
    }
    fileinfo_destroy(in->next);
    
    free(in);
}

static void print_regular(const char* f_name, long long f_length){
    printf("%s (regular, %lld Byte)\n", f_name, f_length);
}

static void print_directory(const char* path, const char* f_name, fileinfo* in){
    printf("%s/%s:\n", path, f_name);
    in = in->down;
    if(in == NULL){
        return;
    }
    fileinfo_print(in);
    while((in = in->next) != NULL){
        fileinfo_print(in);
    }
}

static void print_other(const char* f_name){
    printf("%s (other)\n", f_name);
}

void fileinfo_print(fileinfo* in){
    if(in == NULL){ 
        return;
    }
    if(in->type == filetype_directory){
        print_directory("", in->name, in);
    } else if(in->type == filetype_file){
        print_regular(in->name, in->fileLength);
    } else{
        print_other(in->name);
    }
}

