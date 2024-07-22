#include <stdio.h>
#include <stdlib.h>
#define N 8
//idk de ce nu mere inca
void print_M(int v[][N], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }
}

void backtracking (int v[][N], int i_start, int j_start, int n){

    if (n == 1){
        v[i_start][j_start] = 1;
        return;
    }

    for (int i = i_start; i < n / 2; i++){
        for (int j = j_start; j < n / 2; j++)
            v[i][j] = 1;
    }

    backtracking(v, i_start + n / 2, j_start, n / 2);
    backtracking(v, i_start, j_start + n / 2, n / 2);
    backtracking(v, i_start + n / 2, i_start + n / 2, n / 2);
}

int main (int argc, char** argv){

    if (argc != 2)
        return 1;
    
    int n = 1 << atoi(argv[1]);

    int v[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            v[i][j] = 0;

    backtracking(v, 0, 0, n);

    print_M(v, n);
    return 0;
}
