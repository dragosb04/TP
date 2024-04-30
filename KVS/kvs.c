#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>

struct Element {
    unsigned cheie;
    float valoare;
};

struct KVS {
    El_t *array;
    unsigned current_size;
};

El_t gen_element(unsigned cheie, float valoare){
    
    El_t item = NULL;
    
    if ((item = malloc(sizeof(struct Element))) == NULL)
        return NULL;
    
    item->cheie = cheie;
    item->valoare = valoare;

    return item;
}

KVS_t creeaza_KVS(KVS_t data, El_t item){
    
    if ((data = malloc(sizeof(struct KVS))) == NULL){
        fprintf(stderr, "Eroare la alocarea memoriei pentru KVS.\n");
        exit(EXIT_FAILURE);
    }

    if ((data->array = malloc(sizeof(struct Element))) == NULL){
        fprintf(stderr, "Eroae la alocarea memoriei pentru Element.\n");
        exit(EXIT_FAILURE);
    }

    data->array[0] = item;
    data->current_size = 1;

    return data;
}

KVS_t adauga(KVS_t data, El_t item){

    if (data == NULL)
        return creeaza_KVS(data, item);
    
    if ((data->array = realloc (data->array, data->current_size + sizeof(struct Element))) == NULL){
        fprintf(stderr, "Eroare la alocarea memoriei pentru Element.\n");
        exit(EXIT_FAILURE);
    }

    data->array[(data->current_size)++] = item;
    
    return data;

}

int cauta(KVS_t data, unsigned k){
    for (unsigned i = 0; i < data->current_size; i++){
        if (k == data->array[i]->cheie){
            printf("%10u gasit pe pozitia %u.\n\n", k, i);
            return i;
        }
    }
    printf("%10u inexistent.\nreturnat -1\n\n", k);
    return -1;
}

void printKVS(KVS_t data) {
    printf("\n");
    for (unsigned i = 0; i < data->current_size; i++){
        printf("%u. %10u --- %.3f\n", i, data->array[i]->cheie, data->array[i]->valoare);
    }
    printf("\n");
}

void eliberare(KVS_t data){
    if (data != NULL){
        for (unsigned i = 0; i < data->current_size; i++){
            printf("%u. Se elibereaza %u\n", i, data->array[i]->cheie);
            free(data->array[i]);
        }
        
        free(data->array);
        printf("Array eliberat.\n");
        free(data);
        printf("Pointer eliberat.\n");
        data = NULL;
    }
    else printf("Nefolosit.\n");
    
}

void meniu(){
    printf("\nOPTIUNI\n\n1. Adauga element\n2. Cauta dupa cheie\n3. Opreste\n\nAlegere: ");
}