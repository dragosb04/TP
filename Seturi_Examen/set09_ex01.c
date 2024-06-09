#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_valid(int v[], int n, int sum) {
    int s = 0;
    for (int i = 0; i <= n; i++) {
        if (v[i] == 1)
            s += (1 << i);
    }

    return s == sum;
}

void print_nr(int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (v[i] == 1)
            printf("%d ", 1 << i);
    }
    printf("\n");
}

void sol_back(int v[], int start, int n, int sum) {
    if (start == n + 1)
        return;

    if (is_valid(v, n, sum))
        print_nr(v, n);
    
    for (int i = start; i <= n; i++) {
        v[i] = 1;
        sol_back(v, i + 1, n, sum);
        v[i] = 0;
    }

}

void gen_back(int k, int n) {
    int v[k + 1];
    for (int i = 0; i <= k; i++) {
        v[i] = 0;
    }

    sol_back(v, 0, k + 1, n);
}

int main(int argc, char** argv) {
    
    if (argc != 2)
        return -1;

    int n = atoi(argv[1]);
    int k = log2(n);
    
    if (n == 0){
        printf("0");
        return 0;
    }

    gen_back(k, n);

    return 0;
}
