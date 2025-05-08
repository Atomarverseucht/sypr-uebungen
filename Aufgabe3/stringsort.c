#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubblesort(char **a, int n);
int main(int argc, const char *argv[]){
    if (argc != 2)
    {
        printf("Aufruf: stringsort.c Anzahl\n");
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 1)
    {
        printf("Ungültige Eingabe!\n");
        return 1;
    }
    char** a = malloc((size_t)n * sizeof(char*));
    if (a == NULL)
    {
        return 1;
    }
    int strL = strlen(argv[1])+1;
    for(int i = 0; i < n; i++){
        a[i] = malloc(strL * sizeof(char));
        if (a[i] == NULL)
        {
            return 1;
        }
    }

    printf("Unsortiertes Array:\n");
    srand((unsigned int) time(NULL));
    for (int k = 0; k < n; ++k)
    {
        int r = rand() % n;
        sprintf(a[k], "%d", r);
        printf("%s, ", a[k]);
    }

    printf("\nSortiertes Array:\n");
    bubblesort(a,n);
    printf("\n");
    char* out = malloc(n * (strL+2) * sizeof(char));
    if(!out){
        return -1;
    }
    out[0] = '\0';
    for(int i=0; i < n; i++){
        if(i > 0 && strcmp(a[i-1], a[i]) == 0){
            strcat(out, "*");
        } else{
            strcat(out, ", ");
            strcat(out, (a[i]));
        }
    }
    printf("%s\n", out);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(out);
}


void bubblesort(char **a, int n){
    for (int i = n; i > 0; --i)
    {
        for (int j = 0; j < i - 1; ++j)
        {
            if (strcmp(a[j], a[j+1]) > 0)
            {
                void* tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}