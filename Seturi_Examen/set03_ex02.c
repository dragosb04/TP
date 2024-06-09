#include <stdio.h>
#include <stdlib.h>

void print_stuff (int v[], int c[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d ", c[i]);
    }
    printf("\n");
}

void bank_sum (int sum, int n, int v[], int c[]){
    int nr = 0;
    n--;
    while (sum && n >= 0){
        nr = 0;
        while (c[n] && v[n] <= sum){
            sum -= v[n];
            nr++;
            c[n]--;
        }
        printf("%d x %d\n", nr, v[n]);
        n--;
    }
}

int main (int argc, char** argv){

    if (argc != 2)
        exit(EXIT_FAILURE);
    
    FILE* f = fopen(argv[1], "r");

    if (f == NULL)
        exit(-1);

    int n = 0;
    fscanf(f, "%d", &n);

    int sum = 0;
    fscanf(f, "%d", &sum);

    int v[n], c[n];

    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &(v[i]));

    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &(c[i]));

    printf("%d %d\n", n, sum);
    print_stuff(v, c, n);
    bank_sum(sum, n, v, c);
    return 0;
}
