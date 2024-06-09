#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
#define SEED 11
#define UPPER 20
#define LOWER 2
#define STEP 23

unsigned* makeRandArray(unsigned seed, unsigned n) {
    
    if (n == 0)
        return NULL;    

    unsigned* array = (unsigned*) malloc(sizeof(unsigned) * n);

    if (array == NULL)
        exit(EXIT_FAILURE);

    srand(seed);

    for (unsigned i = 0; i < n; i++)
        array[i] = rand();
    
    return array;
}

int* makeRandLimitArray(int seed, unsigned n, int a, int b){

    if (n == 0)
        return NULL;
    
    int* array = (int*) malloc(sizeof(int) * n);

    if (array == NULL)
        exit(EXIT_FAILURE);
    
    srand(seed);

    for (unsigned i = 0; i < n; i++)
        array[i] = a + rand() % (b - a);
    
    return array;
}

int crescator(int* array, unsigned n) {

    if (n == 0)
        return rand() % STEP;
    else
        return array[n-1] + rand() % STEP;
}

int decrescator(int* array, unsigned n) {

    if (n == 0)
        return rand() % STEP;
    else
        return array[n-1] - rand() % STEP;
}

int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned)){

    if (n == 0)
        return NULL;
    
    int* array = (int*) malloc(sizeof(int) * n);

    if (array == NULL)
        exit(EXIT_FAILURE);
    
    srand(SEED);

    for (unsigned i = 0; i < n; i++)
        array[i] = getNewElem(array, i);
    
    return array;
}

void print_Array(unsigned* array, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void print_int_Array(int* array, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void) {
    unsigned* array = makeRandArray(SEED, SIZE);
    print_Array(array, SIZE);
    
    int* range_array = makeRandLimitArray(SEED, SIZE, LOWER, UPPER);
    print_int_Array(range_array, SIZE);
    
    int* array_ad = makeRandFlexiArray(SIZE, crescator);
    print_int_Array(array_ad, SIZE);

    free(array_ad);

    array_ad = makeRandFlexiArray(SIZE, decrescator);
    print_int_Array(array_ad, SIZE);

    free(range_array);
    free(array);
    free(array_ad);

    return 0;
}
