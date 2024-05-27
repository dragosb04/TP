#include <stdio.h>
#include <stdlib.h>

#define debug 0

typedef unsigned long long Payload_t;

typedef struct node {
    Payload_t data;
    struct node *next;
} Node_t;

typedef Node_t* List_t;

List_t makeNode (Payload_t data){
    
    Node_t* nod = NULL;
    if ((nod = malloc(sizeof(Node_t))) == NULL)
        exit(EXIT_FAILURE);
    
    nod->data = data;
    nod->next = NULL;
    
    return nod;
}

List_t addFront(List_t list, Payload_t value) {
    List_t new_node = makeNode(value), p;

    if (new_node != NULL) {
        if (list == NULL)
            list = new_node;
        else {
            p = list;
            while (p->next != NULL)
                p = p->next;
            p->next = new_node;
        }
    }

    return list;
}

List_t deleteFront(List_t list, int poz){
    
    List_t p = list;
    
    if (p == NULL){
        printf("Lista inexistenta.\n");
        return NULL;
    }

    if (poz == 0)
        return p->next;
    
    for (int i = 0; i < poz - 1; i++){
        if (p->next == NULL){
            printf("Pozitie inexistenta.\n");
            return NULL;
        }
        p = p->next;
#if debug == 1
        printf("Pozitia: %d.\n", i);
#endif
    }

    if (p->next != NULL)
        p->next = p->next->next;
    else
        return NULL;
    
    return list;
}


List_t insert(List_t list, int value, int poz){
    if (poz >= 0){
        List_t p = list, new_node = makeNode(value);

        if (new_node == NULL)
            exit(EXIT_FAILURE);
        if (poz == 0){
            new_node->next = list;
            return new_node;
        }
        for (int i = 0; i < poz - 1; i++){
            if (p == NULL){
                printf("Nu exista pozitia.\n");
                exit(EXIT_FAILURE);
            }
            p = p->next;
        }
        List_t aux = p->next;
        p->next = new_node;
        new_node->next = aux;
        return list;
    }
    else {
        printf("Pozitie inexistenta.\n");
        exit(-1);
    }

}

void printList(List_t lista) {
    while (lista != NULL) {
        printf("%lld ", lista->data);
        lista = lista->next;
    }
    printf("\n\n");
}

void mesaj() {
    printf("Alege ce vrei sa faci.\n1. Adauga nod la lista in coada\n2. Sterge nod din lista\n3. Insereaza nod pe pozitie specifica\n4. Opreste\n\nAlegerea ta: ");
}

int main (void) {

    List_t nod = NULL;
    unsigned choice = 4;
    int value = 0, _value = 0;
    printf("\n\n");
    do {
        mesaj();
        if (scanf("%u", &choice) != 1)
            exit(EXIT_FAILURE);
        
        switch(choice){
            case 1:
                printf("\nValoare de adaugat: ");
                if (scanf("%u", &value) != 1)
                    exit(EXIT_FAILURE);
                nod = addFront(nod, value);
                printList(nod);
                break;
            case 2:
                printf("Pozitia de sters: ");
                if (scanf("%u", &value) != 1)
                    exit(EXIT_FAILURE);
                nod = deleteFront(nod, value);
                printList(nod);
                break;
            case 3:
                printf("Valoare: ");
                if (scanf("%u", &value) != 1)
                    exit(EXIT_FAILURE);
                
                printf("Pozitie: ");
                if (scanf("%u", &_value) != 1)
                    exit(EXIT_FAILURE);
                nod = insert(nod, value, _value);
                printList(nod);
                break;
            case 4:
                printf("Oprit.\n");
                break;
            default:
                printf("Optiune necunoscuta.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}
