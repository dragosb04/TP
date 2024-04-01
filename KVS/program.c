#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    KVS_t *data = creeaza_KVS(100);
    El_t *element = create_Element(20, 11.1);
    unsigned item1 = 0, n = 0;
    float item2 = 0;
    do
    {
        printf("Alege:\n1. Adauga\n2. Cauta\n0. Opreste\n");
        if (scanf("%u", &n) != 1)
            exit(-1);
        switch (n)
        {
        case 1:
            printf("Cheie: ");
            if (scanf("%u", &item1) != 1)
                exit(-1);

            printf("Valoare: ");
            if (scanf("%f", &item2) != 1)
                exit(-1);

            element = create_Element(item1, item2);
            data = adauga(data, element);
            printKVS(data);
            break;
        case 2:
            printf("Cauta cheie: ");
            if (scanf("%u", &item1) != 1)
                exit(-1);

            if (cauta(data, item1) == -1)
                printf("Elementul nu exista.\n");
            else
                printf("Elementul exista.\n");

            break;
        case 0:
            printf("Oprit.\n");
            break;
        };
    } while (n != 0);

    eliberare(data);
    free(element);

    return 0;
}
