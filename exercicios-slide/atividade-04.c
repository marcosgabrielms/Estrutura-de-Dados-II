#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Arv {
    int item;
    struct Arv* esq;
    struct Arv* dir;
} Arv;

Arv* criarNo(int val) {
    Arv* novo = (Arv*) malloc(sizeof(Arv));
    if (novo != NULL) {
        novo->item = val;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

int contarNos(Arv* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
}

int calcularAltura(Arv* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    
    int altEsq = calcularAltura(raiz->esq);
    int altDir = calcularAltura(raiz->dir);
    
    return 1 + (altEsq > altDir ? altEsq : altDir);
}

bool ehCheia(Arv* raiz) {
    if (raiz == NULL) {
        return true; 
    }

    int n = contarNos(raiz);
    int h = calcularAltura(raiz);

    // O deslocamento de bits (1 << h) calcula 2^h
    int nosEsperados = (1 << h) - 1; 

    return (n == nosEsperados);
}

int main() {
    // Teste 1: Árvore cheia (h=2, n=3)
    Arv* raiz = criarNo(10);
    raiz->esq = criarNo(5);
    raiz->dir = criarNo(15);
    
    if (ehCheia(raiz)) {
        printf("A arvore 1 eh CHEIA.\n");
    } else {
        printf("A arvore 1 NAO eh cheia.\n");
    }

    // Teste 2: Adiciona um nó, tornando a árvore incompleta (h=3, n=4)
    raiz->esq->esq = criarNo(2);
    
    if (ehCheia(raiz)) {
        printf("A arvore 2 eh CHEIA.\n");
    } else {
        printf("A arvore 2 NAO eh cheia.\n");
    }

    // Liberação de memória
    free(raiz->esq->esq);
    free(raiz->esq);
    free(raiz->dir);
    free(raiz);

    return 0;
}