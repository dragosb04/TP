#include <stdio.h>
#define STACK_SIZE 3 // aici modifici dimensiunea permutarilor

int stack[STACK_SIZE + 1];

void swap (int *a, int *b){
    int aux = *b;
    *b = *a;
    *a = aux;
}

void print_perm (int stack[], int n){
    for (int i = 1; i <=n; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

void perm_back (int stack[], int k, int n){
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
        stack[i] = i;
    
    int n = STACK_SIZE, k = 1;

    perm_back(stack, k, n);

    return 0;
}
