#include <stdio.h>

void printChessboard(int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i / k) % 2 == (j / k) % 2) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }
}

int main() {
    int m, n, k;
    
    printf("Introduceti dimensiunile tablei de sah (m x n): ");
    scanf("%d %d", &m, &n);
    
    printf("Introduceti dimensiunea patratelor (k x k): ");
    scanf("%d", &k);
    
    printChessboard(m, n, k);
    
    return 0;
}
