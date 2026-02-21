#ifndef ARV_H
#define ARV_H

#include <stdio.h>
#include <stdlib.h>

#define fmt "%d " 
typedef int Item; 


typedef struct arv {
    struct arv *esq; 
    Item item;       
    struct arv *dir; 
} *Arv;              


Arv arv(Arv e, Item x, Arv d) { 
    Arv n = (Arv)malloc(sizeof(struct arv)); 
    n->esq = e;  
    n->item = x; 
    n->dir = d;  
    return n;    
}


void emordem(Arv A) { 
    if (A == NULL) return; 
    emordem(A->esq); 
    printf(fmt, A->item); 
    emordem(A->dir); 
}


void preordem(Arv A) { 
    if (A == NULL) return; 
    printf(fmt, A->item); 
    preordem(A->esq); 
    preordem(A->dir); 
}


void posordem(Arv A) { 
    if (A == NULL) return; 
    posordem(A->esq); 
    posordem(A->dir); 
    printf(fmt, A->item);
}


void destroi(Arv *A) { 
    if (*A == NULL) return; 
    destroi(&(*A)->esq); 
    destroi(&(*A)->dir); 
    free(*A); 
    *A = NULL; 
}

#endif