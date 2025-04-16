#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Aufruf: Bubblesort.c Anzahl\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int *a = (int*) malloc((size_t)n * sizeof(int));
    if(!a){return 1;}
    
    printf("Bitte %d ganze Zahlen eingeben: ", n);
    int k = 0;
    for(int i = 0; i < n; ++i){
        if(!scanf("%d\n", &a[i])){
            goto out;
        }
        ++k;
    }
    out: printf("k=%d\n", k);
    srand((unsigned int) time(NULL));
    for(; k < n; ++k){
        a[k] = rand();
        int m = a[k];
        printf("Zufall: %d\n", m);
    }

    for(int i = n; i > 1; --i){
        for(int j = 0; j < i - 1; --i){
            if (a[j] > a[j + 1]) {
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
    printf("Sortierte Zahlenfolge: ");
    for (int i = 0; i < n; i++) {
        int m = a[i];
        printf("%d, ",m);
    }
    free(a);
}