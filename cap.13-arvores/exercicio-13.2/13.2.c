#include <stdio.h>
#include "../arv.h"

int nos (Arv A) {
    if (A == NULL) {
        return 0;
    }

    return 1 + nos(A->esq) + nos(A->dir);
}

int main() {
    Arv R = arv(arv(arv(NULL, 4, NULL), 2 , arv(NULL, 5, NULL)), // Árvore esquerda
    1,                                                           // Raiz
    arv(NULL, 3, arv(NULL, 6 , NULL)));                          // Árvore Direita
    
    printf("Total de nos na arvore: %d", nos(R));

    destroi(&R);

    return 0;
}

