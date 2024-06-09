#include <stdio.h>
#define N 4

int ind = 1, n = N;
int array[(1 << N) + 1];

void back(int n, int start, int putere) {
    if (n == putere)
        return;
    int end = (1 << putere);
    for (int i = 1; i <= end; i++) {
        array[ind++] = start;
        printf("%d ", start++);
        if (end / 2 == i)
            back(n, (1 << (putere + 1)) + 1, putere + 1);
    }
}

int main(void) {
    array[ind++] = 1;
    printf("1 ");
    back(n, 3, 1);
    printf("2");
    array[ind++] = 2;
    printf("\n\n");
    for (int i = 1; i < ind; i++) { 
        printf("%d ", array[i]);
    }

    return 0;
}
