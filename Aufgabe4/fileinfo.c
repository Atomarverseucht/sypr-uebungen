/*
f_info* fileinfo_create(char[] f_name){
    DIR *dir_ = opendir(f_name);
    if(dir_ == NULL){
        printf("Fehler dir");
        exit(1);
    }
    struct dirent d_ = readdir(dir_);
    if(d_ = NULL)
    fileinfo_createHelp()
}*/

f_info* fileinfo_create(char[] f_name){
    struct f_info* out = malloc(sizeof(f_info));
    struct stat sb;
    if(strlen(f_name) > NAME_MAX) { errno = ENAMETOOLONG; return null;}
    out.name = f_name;
    //next


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
        list_directory(f_name);
    } else{
        out.type = filetype_other;
    }
}

static void list_directory(char[] f_name){
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
    fileinfo_create(d_.d_name);
    closedir(f_name);
    free(dir_);
    free(d_);
}

void fileinfo_destroy(fileinfo* in){
    
}