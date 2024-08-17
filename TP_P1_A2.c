#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cand {
    int nr;
    int oferte[100];
} candid;

int main (int argc, char** argv){

    if (argc != 2)
        return 1;
    
    FILE* f = fopen(argv[1], "r");

    if (!f)
        return 1;

    int alegator[10], n = 0, nr_candid = 0, nr = 0;
    candid candidati[100];
    char buff[253];
    char* p = NULL;

    fgets(buff, 253, f);

    p = strtok(buff, " \n");
    while (p != NULL){
        alegator[n++] = atoi(p);
        p = strtok(NULL, " \n");
    }

    fscanf(f, "%d\n", &nr_candid);

    for (int i = 0; i < nr_candid; i++){
        fgets(buff, 253, f);
        p = strtok(buff, " \n");
        nr = 0;
        while (p != NULL){
            candidati[i].oferte[nr++] = atoi(p);
            p = strtok(NULL, " \n");
        }
        candidati[i].nr = nr;
    }

    int doleante[nr_candid], nr_check;
    for (int i = 0; i < nr_candid; i++)
        doleante[i] = 0;
    
    for (int i = 0; i < nr_candid; i++){
        nr_check = 0;
        for (int j = 0; j < candidati[i].nr; j++){
            for (int k = 0; k < n; k++){
                if (candidati[i].oferte[j] == alegator[k])
                    nr_check++;
            }
        }
        doleante[i] = nr_check;
    }

    int aux;
    int pozitii_doleante[nr_candid];
    for (int i = 0; i < nr_candid; i++)
        pozitii_doleante[i] = i;
    

    for (int i = 0; i < nr_candid - 1; i++)
        for (int j = i; j < nr_candid; j++){
            if (doleante[i] < doleante[j]){
                aux = doleante[j];
                doleante[j] = doleante[i];
                doleante[i] = aux;

                aux = pozitii_doleante[i];
                pozitii_doleante[i] = pozitii_doleante[j];
                pozitii_doleante[j] = aux;
            }
        }

    int nr_minim = 0, is_checked = 0, used = 0;
    for (int i = 0; i < nr_candid; i++){
        used = 0;
        for (int j = 0; j < candidati[pozitii_doleante[i]].nr; j++){
            for (int k = 0; k < n; k++){
                if (alegator[k] == candidati[pozitii_doleante[i]].oferte[j]){
                    alegator[k] = -1;
                    used = 1;
                }
            }
        }
        is_checked = 0;
        for (int ij = 0; ij < n; ij++){
            if (alegator[ij] == -1)
                is_checked++;
        }
        
        if (used == 1)
            nr_minim++;
        
        if (is_checked == n)
            break;
    }

    for (int i = 0; i < n; i++)
        if (alegator[i] != -1){
            printf("0\n");
            return 0;
        }
    printf("%d\n", nr_minim);
    fclose(f);
    
    return 0;
}
