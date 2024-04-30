#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    KVS_t kvs = NULL;

    int optiune = 0;
    int cheie = 0;
    float valoare = 0;
    srand(time(NULL));

    do {
        meniu();
        if (scanf("%d", &optiune) != 1)
            exit(EXIT_FAILURE);
        
        switch(optiune){
            case 1:
                cheie = rand() % 1000000000;
                valoare = cheie / 8.1;
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
                eliberare(&kvs);
            break;
            default:
                printf("Optiune necunoscuta.\n");
            break;
        }
    } while(optiune != 3);
    return 0;
}
