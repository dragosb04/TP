#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} inter;
 
int cmpf(const void *a, const void *b){
    return *(int *) a - *(int *) b;
}

void print_arr(int v[], int n){
    for (int i = 0; i < n; i++)
        printf("%-3d ", v[i]);
    printf("\n");
}

void print_inter(inter p[], int n){
    for (int i = 0; i < n; i++)
        printf("%3d %3d\n", p[i].a, p[i].b);
}
int main (void){
    FILE* f = fopen("nr.txt", "r");
    int nr = 0;

    if (f == NULL)
        exit(-1);
    
    fscanf(f, "%d", &nr);
    int v[100], dim = 0;
    inter x[20];

    for (int i = 0; i < nr; i++)
        fscanf(f, "%d", &v[i]);

    while (fscanf(f, "%d %d", &(x[dim].a), &(x[dim].b)) == 2){
        dim++;
    }

    print_arr(v, nr);
    print_inter(x, dim);
    printf("\n");
    
    int found;
    
    for (int i = 0; i < dim; i++){
        found = 0;
        for (int j = 0; j < nr; j++){
            if (x[i].a < v[j] && x[i].b > v[j]){
                found++;
                if (found > 1)
                    break;
            }
        }
        if (found == 1)
            printf("%3d %3d\n", x[i].a, x[i].b);
    }

    fclose(f);
}
