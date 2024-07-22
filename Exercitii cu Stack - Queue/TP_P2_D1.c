#include <stdio.h>
#include <stdlib.h>

typedef struct st{
    int capacity, size;
    int* vals;
} Stack;

int* add_value_by_id (Stack stack, int* size, int val){
    
    if (stack.size == stack.capacity){
        printf("\nLimita deja atinsa.\n");
        return stack.vals;
    }

    printf("\n=== Adaugat %d in stiva.\n", val);
    stack.vals[stack.size] = val;
    (*size)++;

    return stack.vals;
}

int* remove_value_by_id (Stack stack, int* size){
    if (*size == 0){
        printf("\nNu exista nimic de eliminat.\n");
        return stack.vals;
    }

    (*size)--;
    printf("\n=== Eliminat %d in stiva.\n", stack.vals[*size]);

    return stack.vals;
}

void print_stack_by_id (Stack stack){
    if (stack.size == 0){
        printf("\nNu exista valori.\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < stack.size; i++)
        printf("%d ", stack.vals[i]);
    printf("\n");
}


int main (void){

    int N = 0;
    printf("Numar stive: ");
    scanf("%d", &N);

    Stack stacks[N];
    int st_caps = 0;
    for (int i = 0; i < N; i++){
        printf("Capacitate stiva %d: ", i + 1);
        scanf("%d", &st_caps);
        stacks[i].capacity = st_caps;
        stacks[i].vals = malloc(sizeof(int) * st_caps);
        stacks[i].size = 0;
        if (stacks[i].vals == NULL){
            fprintf(stderr, "Eroare la alocarea memoriei pentru stiva %d.", i + 1);
            for (int j = 0; j < i; j++) {
                free(stacks[j].vals);
            }
            exit(EXIT_FAILURE);
        }
    }

    char opt;
    int id, val;
    do {
        printf("\n== LISTA DE OPTIUNI ==\n");
        printf("B: Introduce pe stiva valoare\nS: Elimina valoare din stiva\nP: Afiseaza stiva\nV: Goleste stiva\nE: Opreste procesul\n\n[Actiune] [Id] [Valoare]\n\n");
        for (int i = 0; i < N; i++){
            printf("%d - Id stiva %d; ", i, i + 1);
        }
        printf("\n\n");
        printf("Alegere: ");
        scanf(" %c %d %d", &opt, &id, &val);
        if (id < N)
            switch(opt){
                case 'B':
                case 'b':
                    stacks[id].vals = add_value_by_id(stacks[id], &stacks[id].size, val);
                break;
                case 'S':
                case 's':
                    stacks[id].vals = remove_value_by_id(stacks[id], &stacks[id].size);
                break;
                case 'P':
                case 'p':
                    print_stack_by_id(stacks[id]);
                break;
                case 'V':
                case 'v':
                    if (stacks[id].size == 0)
                        printf("\nLista este deja goala.\n");
                    else{
                        stacks[id].size = 0;
                        printf("\nStiva cu Id %d a fost golita.\n", id);
                    }
                break;
                case 'E':
                case 'e':
                    for (int i = 0; i < N; i++){
                        printf("\nStiva %d a fost golita.\n", i + 1);
                        free(stacks[i].vals);
                    }
                    printf("\nTerminat.\n");
                break;
                default:
                    printf("Optiune inexistenta. Incearca din nou.\n\n");
                break;
            }
        else printf ("\n**ID INDISPONIBIL.\n");
    } while(opt != 'E' && opt != 'e');

    return 0;
}
