#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef int Element_T;

typedef struct {
    Element_T *data;
    int top;
    int tail;
    int nr;
} Stack_T;

Stack_T makeStack(Element_T element) {
    Stack_T stack;
    stack.nr = 1;
    if ((stack.data = malloc(sizeof(Element_T))) == NULL) {
        fprintf(stderr, "\nEroare la alocarea memoriei pentru stiva.\n\n");
        exit(EXIT_FAILURE);
    }
    stack.data[0] = element;
    stack.top = 0;
    stack.tail = 0;
    return stack;
}

Stack_T push(Stack_T stack, Element_T element) {
    if (stack.nr == MAX) {
        fprintf(stderr, "\nStiva este depasita.\n\n");
        exit(EXIT_FAILURE);
    }
    stack.nr++;
    if ((stack.data = realloc(stack.data, sizeof(Element_T) * stack.nr)) == NULL) {
        fprintf(stderr, "\nEroare la realocarea memoriei pentru stiva.\n\n");
        exit(EXIT_FAILURE);
    }
    stack.data[stack.nr - 1] = element;
    stack.top = stack.nr - 1;
    stack.tail = 0;
    return stack;
}

Element_T pop(Stack_T *stack) {
    if (stack->nr == 0) {
        fprintf(stderr, "\nNu exista niciun element pe stiva.\n\n");
        exit(EXIT_FAILURE);
    }
    Element_T last = stack->data[stack->top];
    stack->nr--;
    if ((stack->data = realloc(stack->data, sizeof(Element_T) * stack->nr)) == NULL && stack->nr > 0) {
        fprintf(stderr, "\nEroare la realocarea memoriei pentru stiva.\n\n");
        exit(EXIT_FAILURE);
    }
    if (stack->nr == 0) {
        stack->top = -1;
        stack->tail = -1;
    } else {
        stack->top = stack->nr - 1;
        stack->tail = 0;
    }
    return last;
}

int main(void) {
    Stack_T stack;
    stack = makeStack(10);
    stack = push(stack, 20);
    stack = push(stack, 30);

    printf("\n");

    printf("Elementul eliminat: %d\n", pop(&stack));
    printf("Elementul eliminat: %d\n", pop(&stack));
    printf("Elementul eliminat: %d\n", pop(&stack));
    printf("Elementul eliminat: %d\n", pop(&stack));

    // Eliberarea memoriei alocate pentru stivă
    free(stack.data);
    return 0;
}
