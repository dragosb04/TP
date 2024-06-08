#ifndef FILME_T
#define FILME_T

typedef struct Film* Film_t;
typedef struct Site_t* Site_T;

Site_T adaugare(Site_T, char*, char*, int, int);
void afisareFilme(Site_T);
void print_Filme(Site_T);
void afisareMaxim(Site_T);
Film_t make_Film (char*, char*, int, int);
void free_Site(Site_T);

#endif