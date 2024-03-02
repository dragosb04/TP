#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afisare_matrice(int **matrice, int SIZE){
    printf("\n");
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)
            printf("%d ", matrice[i][j]);
        printf("\n");
    }
    printf("\n");
}

int **citire_matrice(int **matrice, int SIZE){

    if ((matrice = (int **) malloc (SIZE * sizeof(int*))) == NULL){
        fprintf(stderr, "Eroare la dimensiunea matricei.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < SIZE; i++)
        if ((matrice[i] = (int *) malloc (SIZE * sizeof(int))) == NULL){
            fprintf(stderr, "Eroare la dimensiunea matricei pe linii.\n");
            exit(EXIT_FAILURE);            
        }

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrice[i][j] = rand () % 10;
    
    return matrice;
}

void suma_cea_mai_mica(int **matrice, int SIZE){
    int maxim = 0, suma = 0;
    for (int i = 0; i < SIZE; i++){
        maxim = matrice[i][0];
        suma = 0;
        for (int j = 0; j < SIZE; j++){
            if (maxim < matrice[i][j])
                maxim = matrice[i][j];
            suma += matrice[i][j];
        }
        printf("Suma minima pe linia %d este: %d\n", i, suma - maxim);
    }
    printf("\n");
}

int este_prim(int element){
    for (int i = 2; i <= element / 2; i++)
        if (element % i == 0)
            return 0;
    return 1;
}

void afla_nr_prime_pe_pozitii_pare (int **matrice, int SIZE){
    int count = 0;
    for (int i = 0; i < SIZE; i+=2)
        for (int j = 0; j < SIZE; j+=2)
            if (este_prim(matrice[i][j]) == 1){
                count++;
                printf("%d : matrice[%d][%d]\n", matrice[i][j], i, j);
            }
    printf("\n");
    
    printf("Numere prime pe pozitii pare: %d\n", count);
}

int **permuta_coloana_la_stanga(int **matrice, int SIZE){
    int col1[SIZE];
    for (int i = 0; i < SIZE; i++)
        col1[i] = matrice[i][0];
    
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE - 1; j++)
            matrice[i][j] = matrice[i][j+1];
    
    for (int i = 0; i < SIZE; i++)
        matrice[i][SIZE-1] = col1[i];
    
    return matrice;
}

int **interschimba_min1c_maxnc(int **matrice, int SIZE){
    int minim = matrice[0][0], maxim = matrice[0][SIZE-1];
    for (int i = 0; i < SIZE; i++){
        if (minim > matrice[i][0])
            minim = matrice[i][0];
        
        if (maxim < matrice[i][SIZE-1])
            maxim = matrice[i][SIZE-1];
    }

    printf("Minim: %d\nMaxim: %d\n", minim, maxim);

    for (int i = 0; i < SIZE; i++){
        if(matrice[i][SIZE-1] == maxim)
            matrice[i][SIZE-1] = minim;

        if (matrice[i][0] == minim)
            matrice[i][0] = maxim;
    }

    return matrice;
}

void afla_nr_linii_elem_egale(int **matrice, int SIZE){
    int count = 0, check = 0;
    for (int i = 0; i < SIZE; i++){
        check = 1;
        for (int j = 0; j < SIZE; j++)
            if (matrice[i][j] != matrice[i][0]){
                check = 0;
                break;
            }
        if (check == 1)
            count++;
    }
    printf("\nNumar de linii cu toate elementele egale: %d\n", count);
}

int main (void){

    int SIZE = 0, optiune = 0;
    printf("Dimensiunea matricei: ");
    if (scanf("%d", &SIZE) != 1){
        fprintf(stderr, "Eroare la introducerea dimensiunii matricei.\n");
        exit(EXIT_FAILURE);
    }

    int **matrice = NULL;
    matrice = citire_matrice(matrice, SIZE);
    afisare_matrice(matrice, SIZE);
    do {
        printf("\n");
        printf("== ALEGE OPTIUNE ==\n");
        printf("1. Determina suma pe linii eliminand maximul\n");
        printf("2. Afla numerele prime de pe pozitii pare\n");
        printf("3. Permuta matricea cu o coloana la stanga\n");
        printf("4. Interschimba minimul de pe prima coloana cu maximul de pe ultima coloana\n");
        printf("5. Afla numarul de linii cu toate elementele egale\n");
        printf("6. Opreste procesul\n\n");
        printf("Alegerea ta: ");

        if (scanf("%d", &optiune) != 1){
            fprintf(stderr, "Eroare la introducerea optiunii.\n");
            exit(EXIT_FAILURE);
        }

        switch (optiune) {
            case 1:
                suma_cea_mai_mica(matrice, SIZE);
                break;
            case 2:
                afla_nr_prime_pe_pozitii_pare(matrice, SIZE);
                break;
            case 3:
                matrice = permuta_coloana_la_stanga(matrice, SIZE);
                afisare_matrice(matrice, SIZE);
                break;
            case 4:
                matrice = interschimba_min1c_maxnc(matrice, SIZE);
                afisare_matrice(matrice, SIZE);
                break;
            case 5:
                afla_nr_linii_elem_egale(matrice, SIZE);
                break;
            case 6:
                printf("Operatiune finalizata.\n");
                break;
            default:
                printf("Valoare nedefinita pentru optiune.");
                break;
        }
    } while (optiune != 6);

    free(matrice);
    
    return 0;
}
