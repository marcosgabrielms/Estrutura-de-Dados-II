#ifndef ARVORE_H
#define ARVORE_H

// --- Estruturas ---
typedef struct ArvoreNo {
    int el;
    struct ArvoreNo *left;
    struct ArvoreNo *right;
} ArvoreNo;

typedef struct FilaNo {
    ArvoreNo *noArvore;
    struct FilaNo *prox;
} FilaNo;

typedef struct {
    FilaNo *frente;
    FilaNo *tras;
} Fila;

// --- Funcoes Base (arvore_base.c) ---
ArvoreNo* criarNo(int valor);
ArvoreNo* inserir(ArvoreNo* raiz, int valor);
void imprimirArvore2D(ArvoreNo *raiz);

// --- Percurso (percurso.c) ---
void percursoExtensao(ArvoreNo *raiz);

// --- Remocao em Cascata (remocao_cascata.c) ---
void apagarSubarvore(ArvoreNo **no);
void removerNoEFilhos(ArvoreNo **raiz, int el);

// --- Remocao por Fusao (remocao_fusao.c) ---
void deleteByMerging(ArvoreNo **node);
void findAndDeleteByMerging(ArvoreNo **raiz, int el);

#endif