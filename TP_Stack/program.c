#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

int main (void){

    StringStack_t stack;
    char *string = NULL, *k = NULL, element[10];
    unsigned size = 0;

	string = gen_size_for_Random_string(string);
    srand(time(NULL));
    printf("Dimensiunea stivei: ");
    if (scanf("%u", &size) != 1){
        fprintf(stderr, "Eroare la citirea dimensiunii stivei.\n");
        exit(EXIT_FAILURE);
    }
    
    stack = create_Stack(size);
    
    for (unsigned i = 0; i < size; i++){
        string = gen_Element(string);
        add_Element(stack, string);
        printStack(stack);
    }

    printf("Verifica lexicografic elementul: ");
    element[9] = '\0';
    if (scanf("%9s", element) != 1){
        fprintf(stderr, "Eroare la citirea elementului.\n");
        exit(EXIT_FAILURE);
    }

    k = copyK(stack, element);
    printf("%s\n", k);

    eliberare(stack, string, k);
    return 0;
}