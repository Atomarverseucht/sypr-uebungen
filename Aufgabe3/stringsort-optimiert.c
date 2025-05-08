#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char* kp(char* a, size_t strL, int i) {
    return (char*) (a + strL * i);
}
void bubblesort(void *a, size_t n, size_t strL, int(*comp)(const void*, const void*));
int comp_str(const void* a, const void* b){ return strcmp((char*)a, (char*)b);}

int main(int argc, const char *argv[]){
    if (argc != 2)
    {
        printf("Aufruf: stringsort.c Anzahl\n");
        return 1;
    }

    size_t n = atoi(argv[1]);
    size_t strL = strlen(argv[1])+1;
    if (n < 1)
    {
        printf("Ungültige Eingabe!\n");
        return 1;
    }
    char* a = malloc(strL * n * sizeof(char));
    if (a == NULL)
    {
        return 1;
    }

    printf("Unsortiertes Array:\n");
    srand((unsigned int) time(NULL));
    for (int i = 0; i < (int)n; ++i)
    {
        int r = rand() % n;
        sprintf(kp(a, strL, i), "%d", r);
        printf("%s, ", kp(a, strL, i));
    }

    printf("\nSortiertes Array:\n");
    bubblesort((void*)a,n, strL, comp_str);
    printf("\n");
    char* out = malloc(n * (strL+2) * sizeof(char));
    if(!out){
        return -1;
    }
    out[0] = '\0';
    for(int i=0; i < (int)n; i++){
        if(i > 0 && strcmp(kp(a, strL, i-1), kp(a, strL, i)) == 0){
            strcat(out, "*");
        } else {
            strcat(out, ", ");
            strcat(out, (kp(a, strL, i))); 
        }
    }
    printf("%s\n", out);
    free(out);
    free(a);
}


void bubblesort(void *a, size_t n, size_t strL, int(*comp)(const void*, const void*)){
    for (int j = n; j > 0; --j)
    {
        for (int i = 0; i < j - 1; ++i)
        {
            const void* p1 = (void*)kp((char*) a, strL, i);
            const void* p2 = (void*)kp((char*) a, strL, i+1);

            if (comp(p1, p2) > 0)
            {
                void* tmp = (void*)malloc(strL*sizeof(char));
                if(!tmp){printf("Fehler"); return;}
                memcpy((char*)tmp, (char*)p2, strL);
                memcpy((char*)p2, (char*)p1, strL);
                memcpy((char*)p1, (char*)tmp, strL);
                free(tmp);
            }
        }
    }
}