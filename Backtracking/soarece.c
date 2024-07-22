#include <stdio.h>
#include <stdlib.h>

int nr;

int is_valid (int** v, int row, int col, int n, int m){
    if (row >= 0 && col >= 0 && row < n && col < m && v[row][col] == 0)
        return 1;
    
    return 0;
}

void print_poz (int** v, int is, int js, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            if (i == is && j == js)
                printf("X ");
            else
                printf("%d ", v[i][j]);
        printf("\n");
    }
    printf("%d\n\n", nr);
}

void soarece (int** v, int is, int js, int ib, int jb, int n, int m){
    if (is == ib && js == jb){
        nr++;
        return;
    }
    if (is_valid(v, is, js, n, m)){
        //print_poz(v, is, js, n, m);
        v[is][js] = 1;
        soarece(v, is + 1, js, ib, jb, n, m);
        soarece(v, is, js + 1, ib, jb, n, m);
        soarece(v, is - 1, js, ib, jb, n, m);
        soarece(v, is, js - 1, ib, jb, n, m);
    }
}

int main (void){

    FILE *f = fopen("soarece.in", "r");
    FILE *d = fopen("soarece.out", "w");

    int n, m;
    if (fscanf(f, "%d %d", &n, &m) != 2)
        return 1;
    int** v;
    v = malloc (sizeof(int*) * n);

    for (int i = 0; i < m; i++)
        v[i] = malloc(sizeof(int) * m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(f, "%d", &v[i][j]);

    int is, js, ib, jb;

    if (fscanf(f, "%d %d %d %d", &is, &js, &ib, &jb) != 4)
        return 1;
    
    soarece(v, is, js, ib, jb, n, m);
    fprintf(d, "%d", nr);
    fclose(d);
    fclose(f);
    
    return 0;
}
