#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Stack {
    char** elements;
    unsigned max, current_size;
};

StringStack_t create_Stack (unsigned size){
    StringStack_t stack = NULL;
    if ((stack = (StringStack_t) malloc(sizeof(struct Stack))) == NULL){
        fprintf(stderr, "Eroare la alocarea spatiului pentru stiva.\n");
        exit(EXIT_FAILURE);
    }

    if ((stack->elements = (char**)malloc(sizeof(char*)*size)) == NULL){
        fprintf(stderr, "Eroare la alocarea spatiului pentru numarul de elemente din stiva.\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned i = 0; i < size; i++){
        if ((stack->elements[i] = (char*)malloc(5 * sizeof(char))) == NULL){
            fprintf(stderr, "Eroare la alocarea spatiului pentru numarul de elemente din stiva.\n");
            exit(EXIT_FAILURE);
        }        
    }
    stack->current_size = 0;
    stack->max = size;
    return stack;
}

char* gen_size_for_Random_string(char* random_string){

    if ((random_string = (char*) malloc(5)) == NULL)
        exit(-1);

		return random_string;
}



char* gen_Element(char* random_string){

    random_string[4] = '\0';

    for (unsigned i = 0; i < 4; i++)
        random_string[i] = 'A' + rand() % 26;

    return random_string;
}

void add_Element(StringStack_t stack, char* item){
    if (stack->current_size < stack->max){
        strcpy(stack->elements[stack->current_size], item);
        (stack->current_size)++;
        printf("Adaugat: %s\n", stack->elements[stack->current_size - 1]);
    }
    else
        printf("Limita atinsa.\n");
}

void printStack(StringStack_t stack){
    printf("\n");
    for (int i = stack->current_size - 1; i >= 0; i--)
        printf("%s - %u / %u\n", stack->elements[i], i + 1, stack->current_size);
    
    printf("\n");
}

char* copyK(StringStack_t stack, char* item){
    char* string_To_return = NULL;
    int k = 1;

    if ((string_To_return = (char*) malloc(5 * sizeof(char))) == NULL){
        fprintf(stderr, "Eroare la alocarea memoriei pentru string_To_return.\n");
        exit(EXIT_FAILURE);
    }
    string_To_return[0] = '\0';

    int i = stack->current_size - 1;

    while (i >= 0 && strcmp(stack->elements[i], item) > 0){
        if ((string_To_return = (char*) realloc(string_To_return, 5 * k * sizeof(char) + 1)) == NULL){
            fprintf(stderr, "Eroare la realocarea memoriei pentru elementul cu k-elemente.\n");
            exit(EXIT_FAILURE);
        }
        strcat(string_To_return, stack->elements[i--]);
        strcat(string_To_return, " ");
        k++;
    }
    string_To_return[strlen(string_To_return) - 1] = '\0';
    if (i == stack->current_size - 1){
        printf("\nNu exista niciun element mai mare lexicografic decat %s.\n", item);
        return NULL;
    }
    else
        return string_To_return;
}

void eliberare(StringStack_t stack, char* string, char* k){
    for (unsigned i = 0; i < stack->current_size; i++)
        free(stack->elements[i]);
    free(stack->elements);

    free(stack);
    free(string);
    free(k);
}