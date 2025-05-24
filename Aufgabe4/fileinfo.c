#include <limits.h>
#include <stdio.h>
#include <errno.h>  // errno
#include <string.h> // strerror
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include "fileinfo.h"

static f_info* fileinfo_create(char[] f_name){
    struct f_info* out = malloc(sizeof(f_info));
    struct stat sb;
    if(strlen(f_name) > NAME_MAX) { errno = ENAMETOOLONG; return null;}
    out.name = f_name;
    
    if(lstat(f_name, &sb) == -1){
        printf("Fehler lstat");
        exit(1);
    }
    if(s_ISFILE(sb.st_mode)){
        out.type = filetype_file;
        out.fileLength = sb.st_size;
    } else if(s_ISDIR(sb.st_mode)){
        out.type = filetype_directory;
        // Hier Ordner öffnen
        list_directory(f_name, out);
    } else{
        out.type = filetype_other;
    }
    //next wird von list_directory übernommen
}

static void list_directory(char[] f_name, f_info* in){
    DIR *dir_ = opendir(f_name);
    if(dir_ == NULL){
        printf("Fehler dir");
        exit(1);
    }

    struct dirent d_ = readdir(dir_);
    if(d_ = NULL){
        printf("Fehler rd");
        exit(1);
    }

    f_info* this = f_info_create(d_.d_name, dir_);
    f_info* last = NULL;
    in.down = this;
    this = last;

    while((d_ = readdir(dir_)) != NULL){
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        this = f_info_create(d_.d_name, dir_); 
        last.next = this;
        last = this;
    }

    closedir(f_name);
    free(dir_);
    free(d_);
}

void fileinfo_destroy(fileinfo* in){
    if(in = NULL){return;}
    if(in.type = filetype_directory){
        fileinfo_destroy(in.down);
        free(in.down);
    } else{
        free(in.fileLength);
    }
    fileinfo_destroy(in.next);
    free(in.name);
}

void fileinfo_print(f_info* in){

}

static void print_regular(char[] f_name, long long f_length){

}

static void print_directory(char[] path, char[] f_name, f_info* in){

}

static void print_other(char[] f_name){
    
}