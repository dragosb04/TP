#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef enum StackCodes{ Q_OK, Q_EMPTY, Q_FULL} OpCode_t;

typedef int Elemen_T;

typedef struct {
	Elemen_T data[MAX];
	int head, tail, nr;
} Queue_T;

Queue_T make (Elemen_T element){
	Queue_T queue;
	queue.nr = 1;
	queue.data[0] = element;
	queue.tail = element;
	queue.head = element;

	return queue;
}

OpCode_t push (Queue_T *queue, Elemen_T element){
	if (queue->nr == MAX)
		return Q_FULL;
	
	queue->nr++;
	queue->data[queue->nr-1] = element;
	queue->head = element;

	return Q_OK; 
}

OpCode_t pop (Queue_T *queue){
	if (queue->nr == 0)
		return Q_EMPTY;
	queue->nr--;
	queue->head = queue->data[queue->nr - 1];
	
	return Q_OK;
}

OpCode_t enqueue(Queue_T *queue,  Elemen_T element){
	if (queue->nr == MAX)
		return Q_FULL;

	Queue_T copy;
	copy.nr = 0;
	while (queue->nr){
		push(&copy, queue->data[queue->nr - 1]);
		pop(queue);
	}

	copy.nr++;
	copy.data[copy.nr - 1] = element;

	while (copy.nr){
		push (queue, copy.data[copy.nr - 1]);
		pop(&copy);
	}
	
	return Q_OK;
}

OpCode_t dequeue (Queue_T *queue){
	if (queue->nr == 0)
		return Q_EMPTY;
	
	Queue_T copy;
	copy.nr = 0;

	while (queue->nr){
		push(&copy, queue->data[queue->nr - 1]);
		pop(queue);
	}
	
	copy.nr--;

	while (copy.nr){
		push (queue, copy.data[copy.nr - 1]);
		pop(&copy);		
	}

	return Q_OK;
}

void afisare_Queue (Queue_T queue){
	if (queue.nr != 0){
		printf("\n");
		for (int i = 0; i < queue.nr; i++){
			printf("%d ", queue.data[i]);
		}
		printf("\n\n");
	}
	else {
		printf("Nimic de afisat.\n");
	}

}

int main (void){

	Queue_T queue;
	queue.nr = 0;
	int n = 1;
	Elemen_T add = 0;
	OpCode_t err;
	do {
		printf("Alegeri\n1. Start \n2. Enqueue\n3. Dequeue\n0. Oprire\n\n");
		printf("Alegere: ");
		if (scanf("%d", &n) != 1)
			printf("Eroare la citirea optiunii.\n");
		switch (n)
		{
		case 1:
			queue = make(10);
			afisare_Queue(queue);
			break;
		case 2:
			printf("\nElement de adaugat: ");
			if (scanf("%d", &add) != 1){
				printf("\n\nEroare la introducerea elementului.\n\n");
			}
			if ((err = enqueue(&queue, add)) == Q_FULL)
				printf("Coada este plina.\n");
			else{
				printf("Element adaugat.\n");
				afisare_Queue(queue);
			}
			break;
		case 3:
			if ((err = dequeue(&queue)) == Q_EMPTY)
				printf("\nCoada este goala.\n\n");
			else{
				printf("Element scos.\n\n");
				afisare_Queue(queue);
			}
			break;
		case 0:
			printf("\nOprit.\n");
			break;
		default:
			printf("\nOptiune indisponibila.\n");
			break;
		}
	} while (n != 0);


	return 0;
}
