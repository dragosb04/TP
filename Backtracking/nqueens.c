#include <stdio.h>
#include <stdlib.h>

void print_queens(int v[][5], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (v[j][i] == 1)
                printf("%d ", j);
    }
    printf("\n");
}

int isvalid(int v[][5], int starti, int startj, int n) {
    
    for (int j = 0; j < startj; j++) {
        if (v[starti][j] == 1)
            return 0;
    }

    for (int i = starti, j = startj; i >= 0 && j >= 0; i--, j--) {
        if (v[i][j] == 1)
            return 0;
    }

    for (int i = starti, j = startj; i < n && j >= 0; i++, j--) {
        if (v[i][j] == 1)
            return 0;
    }

    return 1;
}

void nqueen(int v[][5], int col, int n) {
    if (col == n) {
        print_queens(v, n);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isvalid(v, i, col, n)) {
            v[i][col] = 1;
            nqueen(v, col + 1, n);
            v[i][col] = 0;
        }
    }
}

void back (int n){
    int v[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            v[i][j] = 0;
    
    nqueen(v, 0, n);
}

int main (int argc, char**argv){

    if (argc != 2)
        return 1;
    
    int n = atoi(argv[1]);
    back(n);
    return 0;
}
