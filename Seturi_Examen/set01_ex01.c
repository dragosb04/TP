#include <stdio.h>
#include <stdlib.h>

void print_array(int v[], int n, int iter){
    if (n != 0){
        printf("Iteratia %d: ", iter);
        for (int i = 0; i < n; i++)
            printf("%d ", v[i]);
        printf("\n");
    }
}

void sum_until_1 (int v[], int n, int iter){
    if (n == 1)
        return;

    int x[n - 1];
    for (int i = 1; i < n; i++)
        x[i - 1] = v[i] + v[i - 1];

    print_array(x, n - 1, iter + 1);
    sum_until_1(x, n - 1, iter + 1); 
}

int main (int argc, char** argv){
    
    if (argc != 2)
        return -1;

    FILE* f = fopen(argv[1], "r");
    
    if (f == NULL)
        return -1;

    int n = 0;

    if (fscanf(f, "%d", &n) != 1)
        return -1;
    
    if (n > 100000)
        return -1;

    int v[n];

    for (int i = 0; i < n; i ++)
        if(fscanf(f, "%d", &v[i]) != 1)
            return -1;

    sum_until_1(v, n, 0);

    fclose(f);
    
}
