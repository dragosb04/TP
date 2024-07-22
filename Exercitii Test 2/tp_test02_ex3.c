#include <stdio.h>
#include <stdlib.h>
#define V_SIZE 10

void give_sum (int v[], int sum[], int n){
    scanf("%d", &v[0]);
    sum[0] = v[0];
    for (int i = 1; i < n; i++){
        scanf("%d", &v[i]);
        if (i != 0)
            sum[i] = sum[i - 1] + v[i];
    }
}

void print_arr_cond (int v[], int sum[], int n){
    int k = 0;
    printf("%3d %3d\n", v[0], 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            k = 0;
            if (v[i] == sum[j]){
                k = 1;
                printf("%3d %3d\n", v[i], j + 1);
                break;
            }
        }
        if (k == 0 && i != 0)
            printf("%3d %3d\n", v[i], 0);
    }
}

int main (int argc, char** argv){

    if (argc != 2)
        return -1;

    int v[V_SIZE], sum[V_SIZE];
    give_sum(v, sum, atoi(argv[1]));
    print_arr_cond(v, sum, atoi(argv[1]));
    return 0;
}
