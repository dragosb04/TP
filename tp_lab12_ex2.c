#include <stdio.h>
#include <stdlib.h>

void perm_print(int data[], int n){
    for (int i = 0; i < n; i++)
        printf("%d", data[i]);
    printf("\n");
}

int is_valid (int data[], int n){
    for (int i = 0; i < n - 1; i++){
        if (data[i] == 1 && data[i + 1] == 1)
            return 0;
    }

    return 1;
}

void perm_back (int data[], int start, int n){
    if (start == n)
        return;
    
    for (int i = start; i < n; i++){
        if (data [i] == 1)
            data[i] = 0;
        
        perm_back(data, i + 1, n);
        
        if (is_valid(data, n))
            perm_print(data, n);
        data[i] = 1;
    }
}
void back (int n){
    int data[n];
    for (int i = 0; i < n; i++)
        data[i] =  1;
    perm_back(data, 0, n);
}

int main (int argc, char** argv){

    if (argc != 2)
        return -1;
    
    int n = atoi(argv[1]);

    back(n);

    return 0;
}
