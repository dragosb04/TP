#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void swap (char *a, char *b){
    char aux = *b;
    *b = *a;
    *a = aux;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(char*)a - *(char*)b );
}

void perm_print (char data[], int n){
    for (int i = 0; i < n; i++)
        printf("%c", data[i]);
    printf("\n");
}

int is_v(char c){
    char vocale[] = "AEIOUaeiou";
    if (strchr(vocale, c) == NULL)
        return 0;
    
    return 1;
}

int is_c(char c){
    if (!is_v(c) && isalpha(c))
        return 1;
    
    return 0;
}

int is_valid (char data[], int n){
    for (int i = 0; i < n - 1; i++){
        if ((is_v(data[i]) && is_v(data[i + 1])) || (is_c(data[i]) && is_c(data[i + 1])))
            return 0;
    }
    return 1;
}

void perm_back (char stack[], int start, int n){
    if (start == n - 1)
        if (is_valid(stack, n))
            perm_print(stack, n);
    
    for (int i = start; i < n; i++){
        swap(&stack[i], &stack[start]);
        perm_back(stack, start + 1, n);
        swap(&stack[i], &stack[start]);
    }
}

void back (char data[], int n){
    int c = 0, v = 0;

    for (int i = 0; i < n; i++){
        if (is_v(data[i]))
            v++;
        else if (is_c(data[i]))
            c++;
    }

    if ((c == v + 1) || (v == c + 1)){
        qsort(data, n, sizeof(char), cmpfunc);
        perm_back(data, 0, n);
    }
    else
        printf("IMPOSIBIL");
}

int main (int argc, char** argv){
    if (argc != 2){
        printf("Lipsa cuvant.\n");
        return -1;
    }

    back(argv[1], strlen(argv[1]));

    return 0;
}
