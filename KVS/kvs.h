#ifndef KVS_H
#define KVS_H


typedef struct KVS KVS_t;
typedef struct Element El_t;

KVS_t* creeaza_KVS(unsigned maximum);
KVS_t* adauga(KVS_t *data, El_t *element);
void printKVS(KVS_t *data);
int cauta(KVS_t *data, unsigned int cheie);
void eliberare(KVS_t *array);
El_t* create_Element(unsigned key, float value);

#endif // KVS_H
