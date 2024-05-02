#include "distribution.h"
#include <stdlib.h>
#include <time.h>

int main (void){

    int* a = NULL;
    float* b = NULL;
    srand(time(NULL));
    
    int size = 500;
    float medie = 0, abatere = 10, lambda = 0.5;
    a = poission_distribution(size, lambda);
    print_poisson_distribution(a, size);
    
    b = normal_distribution(size, medie, abatere);
    print_normal_distribution(b, size);

    free_normal(b);
    free_poisson(a);

    return 0;
}
