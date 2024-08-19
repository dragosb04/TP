#include <stdio.h>
int result = 0;

int isValid (int v[][5], int i, int j, int n){
    if (i > n || i < 0 || j > n || j < 0 || j > i)
        return 0;
    return 1;
}

void longest_road(int v[][5], int i, int j, int n, int actual){
    if (i == n + 1){
        result = (actual > result) ? actual : result;
        return;
    }

    if (isValid(v, i, j, n)){
        actual += v[i][j];
        longest_road(v, i + 1, j, n, actual);
        longest_road(v, i, j + 1, n, actual);
    }
}

int main (void){

    FILE* f = fopen("date.in", "r");

    if (!f)
        return 1;
    
    int n = 0;
    fscanf(f, "%d", &n);
    int v[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            fscanf(f, "%d", &v[i][j]);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++)
            printf("%d ", v[i][j]);
        printf("\n");
    }

    longest_road(v, 0, 0, n - 1, 0);
    printf("%d\n", result);
    return 0;
}
