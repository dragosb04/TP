#include <stdio.h>
#include "filme.h"

int main (void){

    Site_T site = NULL;
    site = adaugare(site, "Hazbin Hotel", "Drama, Comedy", 26000, 20);
    site = adaugare(site, "Overlord IV", "Actiune, Horror", 36000, 20);
    site = adaugare(site, "Komi-san", "Romance", 16000, 20);
    print_Filme(site);
    printf("\n\n");
    afisareFilme(site);
    printf("\n\n");
    print_Filme(site);
    free_Site(site); 
    return 0;
}