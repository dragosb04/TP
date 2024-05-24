#include <stdio.h>
#define STACK_SIZE 4 // aici modifici dimensiunea permutarilor

char stack[STACK_SIZE + 1];

void swap (char *a, char *b){
    char aux = *b;
    *b = *a;
    *a = aux;
}

void print_perm (char stack[], int n){
    for (int i = 1; i <=n; i++)
        printf("%c ", stack[i]);
    printf("\n");
}

void perm_back (char stack[], int k, int n){
    if (k == n)
        print_perm(stack, n);
    else
        for (int i = k; i <= n; i++){
            swap(&stack[i], &stack[k]);
            perm_back(stack, k + 1, n);
            swap(&stack[i], &stack[k]);
        }
}

int main (void){
    
    for (int i = 1; i <= STACK_SIZE; i++)
        stack[i] = 'a' + i - 1;
    

    int n = STACK_SIZE, k = 1;
    perm_back(stack, k, n);

    return 0;
}
