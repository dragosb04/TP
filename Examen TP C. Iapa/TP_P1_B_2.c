#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr (char* stack, int n, FILE* d){
    for (int i = 0; i < n; i++)
        fprintf(d, "%c", stack[i]);
    fprintf(d, "\n");
}

int areVowels(char a, char b) {
    return strchr("aeiouAEIOU", a) && strchr("aeiouAEIOU", b);
}

int isValid(char* stack, int n){
    for (int i = 0; i < n; i++)
        if (stack[i] == stack[n])
            return 0;
    
    for (int i = 0; i < n; i++)
        if (stack[i + 1] == stack[i] + 1 || stack[i + 1] == stack[i] - 1 || areVowels(stack[i], stack[i + 1]))
            return 0;
    return 1;
}

void arr_with_cond (char* s, char* stack, int n, int k, int start, FILE* d){
    for (int i = 0; i < n; i++){
        stack[start] = s[i];
        if (isValid(stack, start)){
            if (start == k){
                print_arr(stack, k, d);
                return;
            }
            else arr_with_cond (s, stack, n, k, start + 1, d);
        }
    }
}

int main (void){

    FILE* f = fopen("date.in", "r");
    FILE* d = fopen("date.out", "w");

    if (!f || !d)
        return 1;
    
    int n = 0, k = 0;
    fscanf(f, "%d %d ", &n, &k);

    if (n > 26 || k > n)
        return 1;
    
    char s[n], stack[k];
    for (int i = 0; i < n; i++)
        fscanf(f, "%c ", &s[i]);
    
    arr_with_cond(s, stack, n, k, 0, d);

    fclose(f);
    fclose(d);

    return 0;
}
