#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>


struct Element {
    unsigned key;
    float value;
};

struct KVS {
    El_t *array;
    unsigned size;
    unsigned maximum;
};

KVS_t* creeaza_KVS(unsigned maximum) {
    KVS_t *data = NULL;
    if ((data = (KVS_t*) malloc (sizeof(KVS_t))) == NULL){
        fprintf(stderr, "Eroare la alocarea memoriei pentru KVS.\n");
        exit(EXIT_FAILURE);
    }
    data->array = NULL;
    data->size = 0;
    data->maximum = maximum;
    return data;
}

KVS_t* adauga(KVS_t *data, El_t *element) {
    if (data->size != data->maximum) {
        data->size++;
        if ((data->array = (El_t*) realloc(data->array, data->size * sizeof(El_t))) == NULL) {
            fprintf(stderr, "Eroare la adăugarea unui nou element.\n");
            exit(EXIT_FAILURE);
        }
        data->array[data->size - 1] = *element;
    }
    return data;
}

void printKVS(KVS_t *data) {
    for (unsigned i = 0; i < data->size; i++)
        printf("Cheie: %-12u Valoare: %-10.2f\n", data->array[i].key, data->array[i].value);
}

int cauta(KVS_t *data, unsigned int cheie) {
    for (unsigned i = 0; i < data->size; i++)
        if (data->array[i].key == cheie)
            return i;
    return -1;
}

void eliberare(KVS_t *array) {
    free(array->array);
    free(array);
}

El_t* create_Element(unsigned key, float value) {
    El_t *element;
    element = malloc(sizeof(El_t));
    element->key = key;
    element->value = value;
    return element;
}
