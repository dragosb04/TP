#include <stdio.h>

void comb_print(int data[], int k) {
    for (int i = 1; i <= k; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void comb_back(int stack[], int data[], int start, int k, int n) {
    if (start == k + 1) {
        comb_print(data, k);
    } else {
        for (int i = stack[start - 1] + 1; i <= n - k + start; i++) {
            data[start] = i;
            stack[start] = i;
            comb_back(stack, data, start + 1, k, n);
        }
    }
}

void generate_combinations(int n, int k) {
    int data[k + 1]; 
    int stack[k + 1]; 
    stack[0] = 0; 
    comb_back(stack, data, 1, k, n);
}

int main() {
    int n = 5; 
    int k = 3; 
    generate_combinations(n, k);
    return 0;
}
