#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M_SIZE 5 //aici se modifica dimensiunea matricei


void create_matrix(int (*m)[][M_SIZE], int (*vf)[], int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            (*m)[i][j] = rand() % 1001;
            if (i > j && i + j > n - 1)
                (*vf)[(*m)[i][j]]++;
        }   
}

void print_matrix(int m[][M_SIZE], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%3d ", m[i][j]);
        printf("\n");
    }
}

void repeated (int vf[], int n){
    for (int i = 0; i < n; i++)
        if (vf[i] >= 2)
            printf("%-3d %d\n", i, vf[i]);
}

int main (void){
    int vf[1001] = {0};
    int m[M_SIZE][M_SIZE];
    int n = M_SIZE;

    create_matrix(&m, &vf, n);
    print_matrix(m, n);
    
    repeated(vf, n);


    return 0;
}
