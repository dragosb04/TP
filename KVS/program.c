#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    KVS_t kvs = NULL;
    kvs = adauga(kvs, gen_element(10, 20));
    kvs = adauga(kvs, gen_element(30, 40));
    kvs = adauga(kvs, gen_element(1234567890, 11.1));

    printKVS(kvs);
    cauta(kvs, 20);
    cauta(kvs, 1234567890);
    eliberare(kvs);

    int optiune = 0;
    int cheie = 0, valoare = 0;
    do {
        meniu();
        if (scanf("%d", &optiune) != 1)
            exit(EXIT_FAILURE);
        
        switch(optiune){
            case 1:
                printf("\nCheie: ");

                if (scanf("%u", &cheie) != 1){
                    fprintf(stderr, "Eroare la citire.\n");
                    exit(EXIT_FAILURE);
                }

                printf("Valoare: ");

                if (scanf("%u", &valoare) != 1){
                    fprintf(stderr, "Eroare la citire.\n");
                    exit(EXIT_FAILURE);
                }

                kvs = adauga(kvs, gen_element(cheie, valoare));
                printKVS(kvs);
            break;
            case 2:
                printf("\nCheie de cautat: ");
                if (scanf("%u", &cheie) != 1){
                    fprintf(stderr, "Eroare la citire.\n");
                    exit(EXIT_FAILURE);
                }
                cauta(kvs, cheie);
            break;
            case 3:
                printf("Se opreste...\n");
                eliberare(kvs);
            break;
            default:
                printf("Optiune necunoscuta.\n");
            break;
        }
    } while(optiune != 3);
    return 0;
}
