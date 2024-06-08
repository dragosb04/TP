#include "filme.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Film {
    char nume[40];
    int durata, cost;
    char genuri[30];
};

struct Site_t {
    Film_t* filme;
    int nr_filme;
};

int cmpfunc(const void *a, const void *b) {
    Film_t x = *(const Film_t*) a;
    Film_t y = *(const Film_t*) b;

    double ratio_x = (double)x->cost / x->durata;
    double ratio_y = (double)y->cost / y->durata;

    if (ratio_x > ratio_y)
        return 1;
    else if (ratio_x < ratio_y)
        return -1;
    return 0;
}

void print_Filme (Site_T site){
    for (int i = 0; i < site->nr_filme; i++){
        printf("Nume: %s\nGenuri: %s\nCost: %d\nDurata: %d\n\n", site->filme[i]->nume, site->filme[i]->genuri, site->filme[i]->cost, site->filme[i]->durata);
    }
}

Film_t make_Film (char* num, char* gen, int dur, int cost){
    Film_t filme = malloc (sizeof(struct Film));

    if (filme == NULL)
        exit(-1);

    filme->cost = cost;
    filme->durata = dur;
    strcpy(filme->nume, num);
    strcpy(filme->genuri, gen);

    return filme;
}

Site_T make_Site(char* num, char* gen, int dur, int cost){
    
    Site_T site = malloc (sizeof(struct Site_t));
    
    if (site == NULL)
        exit(-1);

    site->filme = malloc (sizeof(struct Film));

    if (site->filme == NULL)
        exit(-1);
    
    site->nr_filme = 1;
    site->filme[0] = make_Film(num, gen, dur, cost);

    return site;
}

Site_T adaugare(Site_T site, char* num, char* gen, int dur, int cost){
    
    if (site == NULL)
        return make_Site(num, gen, dur, cost);
    
    site->nr_filme++;
    site->filme = realloc(site->filme, site->nr_filme * sizeof(struct Film));

    if (site->filme == NULL)
        exit(-1);
    
    site->filme[site->nr_filme - 1] = make_Film(num, gen, dur, cost);

    return site;
}

Site_T copy_Site(Site_T site) {
    Site_T site_copy = malloc(sizeof(struct Site_t));
    if (site_copy == NULL)
        exit(-1);

    site_copy->nr_filme = site->nr_filme;
    site_copy->filme = malloc(site->nr_filme * sizeof(Film_t));
    if (site_copy->filme == NULL)
        exit(-1);

    for (int i = 0; i < site->nr_filme; i++) {
        site_copy->filme[i] = make_Film(site->filme[i]->nume, site->filme[i]->genuri, site->filme[i]->durata, site->filme[i]->cost);
    }

    return site_copy;
}

void free_Site(Site_T site) {
    for (int i = 0; i < site->nr_filme; i++) {
        free(site->filme[i]);
    }
    free(site->filme);
    free(site);
}

void afisareFilme(Site_T site) {
    Site_T site_copy = copy_Site(site);
    qsort(site_copy->filme, site_copy->nr_filme, sizeof(Film_t), cmpfunc);
    print_Filme(site_copy);
    free_Site(site_copy);
}