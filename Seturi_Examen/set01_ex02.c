#include <stdio.h>
#include <stdlib.h>

void print_arr(int v[], int n){
    for (int i = 0; i < n; i++)
        printf("%d", v[i]);
    
    printf("\n");
}

int is_valid (int v[], int n, int s){
    
    int sum = v[0];

    if (v[0] == 0)
        return 0;

    for (int i = 1; i < n; i++){
        if (v[i] % 2 == v[i - 1] % 2)
            return 0;
        sum+=v[i];
    }
    
    if (sum == s)
        return 1;
    else
        return 0;
}

void diff_par_to_s (int v[], int poz, int n, int s){
    
    if (poz == n + 1)
        return;
    
    if (is_valid(v, n, s))
        print_arr(v, n);
    
    for (int i = 0; i < 9; i++){
        v[poz] = i;
        diff_par_to_s(v, poz + 1, n, s);
    }

}

void generate_back (int n, int s){
    int v[n];
    
    for (int i = 0; i < n; i++)
        v[i] = 0;
    
    diff_par_to_s(v, 0, n, s);
}

int main (int argc, char** argv){

    if (argc != 3)
        return -1;
    
    int n = atoi(argv[1]), s = atoi(argv[2]);
    
    if (n <= 10 && s <= 20)
        generate_back(n, s);
    else
        return -1;

    return 0;
}
