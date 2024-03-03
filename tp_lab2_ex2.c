#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afiseaza_matrice (int **matrice, int size){
    printf("\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++)
            printf("%d ", matrice[i][j]);
        printf("\n");
    }
    printf("\n");
}

int **citeste_matrice(int **matrice, int size){

    if ((matrice = (int **) malloc (size * sizeof(int *))) == NULL){
        fprintf(stderr, "Eroare la alocarea dimensiunii matricei.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++){
        if ((matrice[i] = (int *) malloc (size * sizeof(int))) == NULL){
            fprintf(stderr, "Eroare la alocarea liniei matricei.\n");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < size; j++)
            matrice[i][j] = rand() % 10;
    }

    return matrice;
}

int main (void){
    int **matrice = NULL, size = 0, optiune = 0, sum = 0;

    printf("Dimensiune: ");
    if (scanf("%d", &size) != 1){
        fprintf(stderr, "Eroare la citirea dimensiunii matricei.\n");
        exit(EXIT_FAILURE);
    }

    matrice = citeste_matrice(matrice, size);

    afiseaza_matrice(matrice, size);

    printf("Alege zona din care doresti sa calculezi suma: \n");
    printf("zona 1, formata din elementele situate strict deasupra diagonalei principale si strict deasupra diagonalei secundare\n");
    printf("zona 2, formata din elementele situate strict deasupra diagonalei principale si strict sub diagonala secundara\n");
    printf("zona 3, formata din elementele situate strict sub diagonala principala si strict sub diagonala secundara\n");
    printf("zona 4, formata din elementele situate strict sub diagonala principala si strict deasupra diagonalei secundare\n\n");
    printf("Alege zona: ");

    if (scanf("%d", &optiune) != 1){
        fprintf(stderr, "Eroare la introducerea optiunii.\n");
        exit(EXIT_FAILURE);
    }

    switch(optiune){
        case 1:
            for (int i = 0; i < size / 2; i++){
                for (int j = 1; j < size - 1; j++){
                    if (i < j && i + j < size - 1)
                        sum += matrice[i][j];
                }
            }
        break;
        case 2:
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    if (i < j && i + j > size - 1)
                        sum += matrice[i][j];
                }
            }
        break;
        case 3:
            for (int i = size / 2; i < size; i++){
                for (int j = 1; j < size - 1; j++){
                    if (i > j && i + j > size - 1)
                        sum += matrice[i][j];
                }
            }
        break;
        case 4:
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size / 2; j++){
                    if (i > j && i + j < size - 1)
                        sum += matrice[i][j];
                }
            }
        break;
        default:
            printf("Nu exista aceasta zona.\n");
        break;
    }

    printf("Suma: %d\n", sum);

    return 0;
}
