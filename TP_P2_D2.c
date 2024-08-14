#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    int nr_stud, id_princ, id_sec, nr_coord;
    int *coords;
} stud;

typedef struct membru_comisie{
    int id_membru, nr_comp;
    int *comps;
} mem_com;

typedef struct comisii{
    mem_com membri[6];
} coms;

int are_competenta(mem_com membru, int competenta){
    for (int i = 0; i < membru.nr_comp; i++){
        if (membru.comps[i] == competenta)
            return 1;
    }
    return 0;
}

int comisie_potrivita(coms comisie, stud student){
    int gasit_principal = 0, gasit_secundar = 0;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < student.nr_coord; j++){
            if (comisie.membri[i].id_membru == student.coords[j])
                return 0;
        }
    }

    for (int i = 0; i < 6; i++){
        if (are_competenta(comisie.membri[i], student.id_princ))
            gasit_principal = 1;
        if (are_competenta(comisie.membri[i], student.id_sec))
            gasit_secundar = 1;
    }

    return gasit_principal && gasit_secundar;
}

int main(void){

    FILE *f = fopen("date.in", "r");
    FILE *d = fopen("data.out", "w");

    if (!f || !d)
        return 1;

    int nr_studs, curr_coords = 1, nr_com;
    char buff[253];
    char *p;
    fscanf(f, "%d", &nr_studs);

    stud studenti[nr_studs];

    for (int i = 0; i < nr_studs; i++){
        fscanf(f, "%d %d %d", &studenti[i].nr_stud, &studenti[i].id_princ, &studenti[i].id_sec);
        fgets(buff, 253, f);
        p = strtok(buff, " \n");
        curr_coords = 1;
        studenti[i].coords = NULL;
        while (p != NULL)
        {
            studenti[i].coords = realloc(studenti[i].coords, sizeof(int) * curr_coords);
            if (studenti[i].coords == NULL)
                return 1;
            studenti[i].coords[curr_coords - 1] = atoi(p);
            p = strtok(NULL, " \n");
            curr_coords++;
        }
        studenti[i].nr_coord = curr_coords - 1;
    }
/*
    for (int i = 0; i < nr_studs; i++){
        printf("%d %d %d ", studenti[i].nr_stud, studenti[i].id_princ, studenti[i].id_sec);
        for (int j = 0; j < studenti[i].nr_coord; j++)
            printf("%d ", studenti[i].coords[j]);
        printf("\n");
    }

    printf("\n");
*/
    fscanf(f, "%d", &nr_com);

    coms comisii[nr_com];
    for (int i = 0; i < nr_com; i++){
        for (int j = 0; j < 6; j++){
            fscanf(f, "%d %d", &comisii[i].membri[j].id_membru, &comisii[i].membri[j].nr_comp);
            comisii[i].membri[j].comps = malloc(sizeof(int) * comisii[i].membri[j].nr_comp);

            if (comisii[i].membri[j].comps == NULL)
                return 1;

            for (int k = 0; k < comisii[i].membri[j].nr_comp; k++){
                fscanf(f, "%d", &comisii[i].membri[j].comps[k]);
            }
        }
    }
/*
    for (int i = 0; i < nr_com; i++){
        for (int j = 0; j < 6; j++){
            printf("%d %d ", comisii[i].membri[j].id_membru, comisii[i].membri[j].nr_comp);
            for (int k = 0; k < comisii[i].membri[j].nr_comp; k++)
                printf("%d ", comisii[i].membri[j].comps[k]);
            printf("\n");
        }
        printf("\n");
    }
*/
    for (int i = 0; i < nr_studs; i++){
        int alocat = 0;
        fprintf(d, "Student %d poate fi alocat la comisiile: ", studenti[i].nr_stud);
        for (int j = 0; j < nr_com; j++){
            if (comisie_potrivita(comisii[j], studenti[i]))
            {
                fprintf(d, "%d ", j + 1);
                alocat = 1;
            }
        }
        if (!alocat){
            fprintf(d, "niciuna");
        }
        fprintf(d, "\n");
    }

    fclose(f);
    fclose(d);
    return 0;
}
