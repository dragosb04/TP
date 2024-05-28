#include <stdio.h>
#include <stdlib.h>

void print_matrix(int v[][100], int m){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++)
            printf("%3d ", v[i][j]);
        printf("\n");
    }
}

void assign_zeros(int v[][100], int start_row, int end_row, int start_col, int end_col, int n){
    if (n == 0 || start_row >= end_row || start_col >= end_col) {
        return;
    }

    int mid_row = (start_row + end_row) / 2;
    int mid_col = (start_col + end_col) / 2;

    for (int i = start_row; i < end_row; i++) {
        v[i][mid_col] = 0;
    }

    for (int j = start_col; j < end_col; j++) {
        v[mid_row][j] = 0;
    }

    v[mid_row][mid_col] = n;

    assign_zeros(v, start_row, mid_row, start_col, mid_col, n - 1);
    assign_zeros(v, start_row, mid_row, mid_col, end_col, n - 1);
    assign_zeros(v, mid_row, end_row, start_col, mid_col, n - 1);
    assign_zeros(v, mid_row, end_row, mid_col, end_col, n - 1);
}

void matr_n(int n){
    
    int m = 1, dim;
    for (int i = 1; i <= n; i++)
        m = m * 2;
    
    m--;

    int v[100][100];
    dim = m;

    assign_zeros(v, 0, m, 0, m, n);


    print_matrix(v, dim);
}

int main (int argc, char** argv){

    if (argc != 2)
        return -1;
    
    matr_n(atoi(argv[1]));
    
    return 0;
}
