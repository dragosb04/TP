#ifndef KVS_H
#define KVS_H


typedef struct KVS* KVS_t;
typedef struct Element* El_t;

void printKVS(KVS_t);
KVS_t adauga(KVS_t, El_t);
KVS_t creeaza_KVS(KVS_t, El_t);
El_t gen_element(unsigned, float);
int cauta(KVS_t, unsigned);
void eliberare(KVS_t*);
void meniu();

#endif // KVS_H
