#include <stdio.h>
#include <stdlib.h>

void print_comb (int* v, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int is_valid(int* v, int n){
    for (int i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1])
            return 0;
    
    return 1;
}

void parti_numar (int n, int size, int* v, int* comb, int start, int length){
    if (n == 0){
        if (is_valid(comb, length))
            print_comb(comb, length);
        return;
    }
    
    for (int i = 0; start < size; i++){
        if (v[i] > n) break;
        comb[start] = v[i];
        parti_numar(n - v[i], size, v, comb, start + 1, length + 1);
    }
}

int main (int argc, char** argv){

    if (argc != 2)
        return 1;
    
    int n = atoi(argv[1]);
    int* v = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        v[i] = i + 1;

    int* comb = malloc(sizeof(int) * n);

    parti_numar(n, n, v, comb, 0, 0);

    return 0;
}
