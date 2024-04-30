#ifndef _STACK_H
#define _STACK_H

typedef struct Stack* StringStack_t;

StringStack_t create_Stack(unsigned);
char* gen_Element();
void add_Element(StringStack_t, char*);
char* copyK(StringStack_t, char*);
void printStack(StringStack_t);
char* gen_size_for_Random_string(char*);
void eliberare(StringStack_t, char*, char*);

#endif