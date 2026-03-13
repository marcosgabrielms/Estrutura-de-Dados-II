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
        novo ->item = val;
        novo ->esq = NULL;
        novo ->dir = NULL;
    }
    return novo;
}

int contarNos(Arv* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);   
}

bool ehCompleta(Arv* raiz, int indice, int totalNos) {
    if (raiz == NULL) {
    return true;
    }
    if(indice >= totalNos) {
        return false;
    }
    return ehCompleta(raiz->esq, 2 * indice + 1, totalNos) &&
           ehCompleta(raiz->dir, 2 * indice + 2, totalNos);
}

int main() {
    Arv* raiz = criarNo(10);
    // raiz->dir = criarNo();
    raiz->esq = criarNo(30);

    int total = contarNos(raiz);

    if (ehCompleta(raiz, 0, total)) {
        printf("A arvore eh completa.\n");
    } else {
        printf("A arvore nao eh completa\n");
    }

    free(raiz->dir);
    free(raiz);

    return 0;
}