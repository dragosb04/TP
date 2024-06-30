#include <stdio.h>
#include <stdlib.h>

void print_combs(int* v, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void partisum (int n, int size, int *nums, int* comb, int start, int length){
    if (n == 0){
        print_combs(comb, length);
        return;
    }

    for (int i = start; i < size; i++){
        if (nums[i] > n) break;
        comb[length] = nums[i];
        partisum(n - nums[i], size, nums, comb, i, length + 1);
    }
}

int main (void){

    int n;
    if (scanf("%d", &n) != 1)
        return 1;
    
    if (n % 2 || n > 40 || n < 1){
        printf("imposibil.");
        return 1;
    }

    int* nums = malloc(sizeof(int) * (n / 2 + 1));
    int* comb = malloc (sizeof(int) * (n / 2 + 1));
    
    for (int i = 0; i < n / 2 + 1; i++)
        nums[i] = (i + 1) * 2;

    partisum(n, n / 2 + 1, nums, comb, 0, 0);
    
    free(nums);
    free(comb);

    return 0;
}
