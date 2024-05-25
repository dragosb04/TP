#include <stdio.h>

void arr_print(int data[], int k){
    for (int i = 1; i <= k; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");    
}

int not_used (int data[], int end, int curr){
    for (int i = 1; i < end; i++)
        if (data[i] == curr)
            return 0;
    
    return 1;
}

void arr_back(int data[], int start, int k, int n){
    if (start == k + 1)
        arr_print(data, k);
    else{
        for (int i = 1; i <= n; i++){
            if (not_used(data, start, i)){
                data[start] = i;
                arr_back(data, start + 1, k, n);
            }
        }
    }
}

void generate_arr(int n, int k){
    int data[n + 1];
    arr_back(data, 1, k, n);
}

int main() {
    int n = 3; 
    int k = 2; 
    generate_arr(n, k);
    return 0;
}
