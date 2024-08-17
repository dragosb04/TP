#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int val;
    struct list* next;
} lista;

lista* make_node (int value){
    lista* element = malloc(sizeof(lista));
    element->val = value;
    element->next = NULL;
    return element;
}

lista* add_node (lista* list, int value){
    if (list == NULL)
        return make_node(value);
    
    lista* temp = make_node(value);
    lista* p = list;

    while (p->next != NULL){
        p = p->next;
    }
    p->next = temp;

    return list;
}

void afisare (lista* list){
    lista* p = list;
    while (p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

lista* sum_until_one(lista* list, int size){
    if (list->next == NULL)
        return list;

    lista* p = list;
    while(p->next->next != NULL){
        p->val += p->next->val;
        p = p->next;
    }
    p->val += p->next->val;
    p->next = NULL;
    afisare(list);
    return sum_until_one(list, size);
}

int main (int argc, char** argv){
    
    if (argc != 2)
        return 1;
    
    FILE* f = fopen(argv[1], "r");
    
    if (!f)
        return 1;

    lista* list = NULL;

    int value = 0, size = 0;
    
    fscanf(f, "%d", &size);
    while (fscanf(f, "%d", &value) == 1)
        list = add_node(list, value);
    
    afisare(list);
    sum_until_one(list, size);

    return 0;
}
