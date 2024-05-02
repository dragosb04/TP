#include "distribution.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

float generate_normal_distribution(float medie, float deviatie) {
    
    float u1, u2;
    float z;

    u1 = rand() / (RAND_MAX + 1.0);
    u2 = rand() / (RAND_MAX + 1.0);

    z = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);

    return medie + z * deviatie;
}

int generate_poisson_distribution(float lambda){
    
    float L = exp(-lambda);
    float prob = 1.0;
    int k = 0;

    while (prob > L){
        k++;
        prob *= ((float) rand() / RAND_MAX);
    }

    return k - 1;
}

float* normal_distribution (int size, int medie, int deviatie){
    if (size > 0){
        float* array = NULL;

        if ((array = (float*) malloc (sizeof(float)*size)) == NULL)
            exit(EXIT_FAILURE);

        for (int i = 0; i < size; i++)
            array[i] = generate_normal_distribution(medie, deviatie);
        
        return array;
    }
    else return NULL;

}

int* poission_distribution(int size, float lambda){
    if (size > 0){
        int* array = NULL;

        if ((array = (int*) malloc (sizeof(int)*size)) == NULL)
            exit(EXIT_FAILURE);
        
        for (int i = 0; i < size; i++)
            array[i] = generate_poisson_distribution(lambda);
        
        return array;
    }
    else return NULL;
}

void print_normal_distribution(float* array, int size){
    FILE *file = fopen("rezultate_normal.csv", "w");
    
    if (file == NULL)
        exit(EXIT_FAILURE);

    fprintf(file, "Valori\n");
    for (int i = 0; i < size; i++)
        fprintf(file, "%.2f\n", array[i]);

    fclose(file);
}

void print_poisson_distribution (int* array, int size){
    FILE *file = fopen("rezultate_poisson.csv", "w");
    
    if (file == NULL)
        exit(EXIT_FAILURE);

    fprintf(file, "Valori\n");
    for (int i = 0; i < size; i++)
        fprintf(file, "%d\n", array[i]);
    
    fclose(file);
}

void free_normal(float* array){
    free(array);
}

void free_poisson(int* array){
    free(array);
}