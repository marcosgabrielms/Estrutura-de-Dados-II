#ifndef ARV_HPP
#define ARV_HPP

#include <iostream>

typedef int Item; 

struct arv {
    arv *esq; 
    Item item;       
    arv *dir; 
};
typedef arv* Arv;              


Arv cria_arv(Arv e, Item x, Arv d) { 
    Arv n = new arv; 
    n->esq = e;  
    n->item = x; 
    n->dir = d;  
    return n;    
}

void emordem(Arv A) { 
    if (A == nullptr) return; 
    emordem(A->esq); 
    std::cout << A->item << " "; 
    emordem(A->dir); 
}

void preordem(Arv A) { 
    if (A == nullptr) return; 
    std::cout << A->item << " "; 
    preordem(A->esq); 
    preordem(A->dir); 
}

void posordem(Arv A) { 
    if (A == nullptr) return; 
    posordem(A->esq); 
    posordem(A->dir); 
    std::cout << A->item << " ";
}


void destroi(Arv& A) { 
    if (A == nullptr) return; 
    destroi(A->esq); 
    destroi(A->dir); 
    delete A; 
    A = nullptr; 
}

#endif