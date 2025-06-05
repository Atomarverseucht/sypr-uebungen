/*
 * fileinfo.c
 *
 * Library-Implementation
 *
 * Author Tom Bonsiep
 * Erstellt am: 29.05.2025
 * Zuletzt geändert: 30.05.2025
 */

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

static void fin_print(const char* path, fileinfo* in, _Bool pMode);

fileinfo* fileinfo_create(const char* f_name)
{
    fileinfo* out = malloc(sizeof(fileinfo));
    if (!out)
    {
        errno = ENOMEM;
        return NULL;
    }
    struct stat sb;
    if (strlen(f_name) > NAME_MAX)
    {
        free(out);
        errno = ENAMETOOLONG;
        return NULL;
    }

    strncpy(out->name, f_name, NAME_MAX);
    if (lstat(f_name, &sb) != 0)
    {
        free(out);
        errno = ENOENT;
        return NULL;
    }
    out->next = NULL;
    if (S_ISREG(sb.st_mode))
    {
        out->type = filetype_file;
        out->fileLength = sb.st_size;
    }
    else if (S_ISDIR(sb.st_mode))
    {
        out->type = filetype_directory;
        out->down = NULL;
        // Hier Ordner öffnen
        list_directory(f_name, out);
    }
    else
    {
        out->type = filetype_other;
    }
    //next wird von list_directory übernommen
    return out;
}

static void list_directory(const char* f_name, fileinfo* in)
{
    if (chdir(f_name) != 0)
    {
        errno = ENOENT;
        return;
    }
    DIR *dir_ = opendir(".");
    if (dir_ == NULL)
    {
        errno = ENOMEM;
        return;
    }
    fileinfo* this = NULL;
    fileinfo* last = NULL;
    _Bool first = true;
    const struct dirent *d_;

    while ((d_ = readdir(dir_)) != NULL)
    {
        if (strcmp(d_->d_name, ".") == 0 || strcmp(d_->d_name, "..") == 0)
        {
            continue;
        }
        this = fileinfo_create(d_->d_name);
        if (first)
        {
            in->down = this;
            first = false;
        }
        else
        {
            last->next = this;
        }
        last = this;
    }

    closedir(dir_);
    if (chdir("..") != 0)
    {
        errno = ENOENT;
        return;
    }
}

static void fin_destroy(fileinfo* in){
    if (in == NULL)
    {
        return;
    }
    if (in->type == filetype_directory)
    {
        fin_destroy(in->down);
    }
    fin_destroy(in->next);
    free(in);
}
void fileinfo_destroy(fileinfo* in)
{
    if (in == NULL)
    {
        return;
    }
    if (in->type == filetype_directory)
    {
        fin_destroy(in->down);
    }
    free(in);
}

static void print_regular(const char* f_name, size_t f_length)
{
    printf("%s (regular, %zu Byte)\n", f_name, f_length);
}

static void print_directory(const char* path, const char* f_name, fileinfo* const in)
{
    char* n_path = malloc(strlen(path) + strlen(f_name) + 2);
    if (!n_path)
    {
        printf("%s/%s: Path too long", path, f_name);
        errno = ENOMEM;
        return;
    }
    strcpy(n_path, path);
    if (strcmp("", path) != 0)
    {
        strcat(n_path, "/");
    }
    strcat(n_path, f_name);
    printf("\n%s:\n", n_path);
    fileinfo* in_ = in;
    in_ = in_->down;
    if (in_ != NULL)
    {
        fin_print(n_path, in_, false);
        while ((in_ = in_->next) != NULL)
        {
            fin_print(n_path, in_, false);
        }
    }
    in_ = in->down;
    if (in_ != NULL)
    {
        fin_print(n_path, in_, true);
        while ((in_ = in_->next) != NULL)
        {
            fin_print(n_path, in_, true);
        }
    }
    free(n_path);
}

static void fin_print(const char* path,const fileinfo* const in, _Bool pMode)
{
    if (in->type == filetype_directory)
    {
        if (pMode)
        {
            print_directory(path, in->name, in);
        }
        else
        {
            printf("%s (directory)\n", in->name);
        }

    }
    else
    {
        if (!pMode)
        {
            fileinfo_print(in);
        }
    }
}

static void print_other(const char* const f_name)
{
    printf("%s (other)\n", f_name);
}

void fileinfo_print(fileinfo* const in)
{
    if (in == NULL)
    {
        return;
    }
    if (in->type == filetype_directory)
    {
        print_directory("", in->name, in);
    }
    else if (in->type == filetype_file)
    {
        print_regular(in->name, in->fileLength);
    }
    else
    {
        print_other(in->name);
    }
}