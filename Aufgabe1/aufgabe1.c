#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdalign.h>

int main(void){
    //Variabel-Definitionen
    const char *s = "Hallo";
    const int a = 1234;
    const short int b = 123;
    const long int c = 128L;
    const long long int d = 355LL;

    const unsigned int e = 12;
    const unsigned short int f = 1;
    const unsigned long int g = 12;
    const unsigned long long int h = 200;

    const char i = 'k';
    const signed char j = -100;
    const unsigned char k = 0x20;

    const _Bool l = 1;
    const bool m = true;

    const float n = 1.25;
    const double o = 2.5;
    const long double p = 3.75;

    //Print-Statements
    printf("Ausgabe im folgenden Format:\nAdresse, Platzbedarf, Alignment, Typ, Namen, Wert\n");
    printf("%p, %zu, %ld, pointer, s, %s\n", (void*) &s, sizeof(s), alignof(s), s );
    printf("%p, %zu, %ld, int, a, %i\n", (void*) &a, sizeof(a), alignof(a), a );
    printf("%p, %zu, %ld, short int, b, %hd\n", (void*) &b, sizeof(b), alignof(b), b );
    printf("%p, %zu, %ld, long int, c, %ld\n", (void*) &c, sizeof(c), alignof(c), c );
    printf("%p, %zu, %ld, long long int, d, %lld\n", (void*) &d, sizeof(d), alignof(d), d );

    printf("%p, %zu, %ld, unsigned int, e, %u\n", (void*) &e, sizeof(e), alignof(e), e );
    printf("%p, %zu, %ld, unsigned short int, f, %hu\n", (void*) &f, sizeof(f), alignof(f), f );
    printf("%p, %zu, %ld, unsigned long int, g, %lu\n", (void*) &g, sizeof(g), alignof(g), g );
    printf("%p, %zu, %ld, unsigned long long int, h, %llu\n", (void*) &h, sizeof(h), alignof(h), h );

    printf("%p, %zu, %ld, char, i, %c\n", (void*) &i, sizeof(i), alignof(i), i );
    printf("%p, %zu, %ld, signed char, j, %hhd\n", (void*) &j, sizeof(j), alignof(j), j );
    printf("%p, %zu, %ld, unsigned char, k, %hhu\n", (void*) &k, sizeof(k), alignof(k), k );

    printf("%p, %zu, %ld, _Bool, l, %s\n", (void*) &l, sizeof(l), alignof(l), l ? "true" : "false");
    printf("%p, %zu, %ld, bool, m, %s\n", (void*) &m, sizeof(m), alignof(m), m ? "true" : "false" );

    printf("%p, %zu, %ld, float, n, %f\n", (void*) &n, sizeof(n), alignof(n), n );
    printf("%p, %zu, %ld, double, o, %lf\n", (void*) &o, sizeof(o), alignof(o), o );
    printf("%p, %zu, %ld, long double, p, %Lf\n", (void*) &p, sizeof(p), alignof(p), p );

    //Ausgabe C-Datenmodell
    printf("C-Datenmodell: ");
    if(sizeof(int) == 4){
        if(sizeof(long int) == 4 ){
            if(sizeof(char*) == 4){
                printf("ILP32");
            } else if(sizeof(long long int) == 8 && sizeof(char*) == 8){
                printf("LLP64");
            }
        }
        else if(sizeof(long int) == 8 && sizeof(char*) == 8){
            printf("LP64");
        }
    } else{
        printf("unbekannt");
    }
    printf("\n");
}