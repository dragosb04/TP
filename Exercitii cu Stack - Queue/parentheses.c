#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAR_SIZE 10

typedef struct {
    char par[PAR_SIZE];
    int size;
} stack;

int push (stack* parenthese, char first_check){
    
    if (parenthese->size >= PAR_SIZE)
        return 0;

    parenthese->par[parenthese->size] = first_check;
    (parenthese->size)++;

    return 1;
}

int pop (stack* parenthese, char last_check){
    
    if (parenthese->size == 0)
        return 0;
    
    char par_check;
    switch(last_check){
        case '}':
            par_check = '{';
        break;
        case ']':
            par_check = '[';
        break;
        case ')':
            par_check = '(';
        break;
    }

    if (parenthese->par[parenthese->size - 1] != par_check)
        return 0;
    else {
        (parenthese->size)--;
        return 1;
    }
}

int main (void){

    char string[] = "{{{{[()]}}}}";
    stack parentheses;
    parentheses.size = 0;

    for (int i = 0; i < strlen(string); i++){
        if (strchr("{[(", string[i]) != NULL){
            if(push(&parentheses, string[i]) == 0){
                printf("Overflow.\n");
                return 1;
            }
        }
        else if (strchr("})]", string[i]) != NULL)
            if (pop(&parentheses, string[i]) != 1){
                printf("Inconsistenta.\n");
                return 0;
            }
    }

    if (parentheses.size == 0)
        printf("Consistent.\n");
    else
        printf("Inconsistent.\n");
    return 0;
}
