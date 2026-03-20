#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. ESTRUTURAS DE DADOS
// ==========================================
typedef struct ArvoreNo {
    int el;
    struct ArvoreNo *left;
    struct ArvoreNo *right;
} ArvoreNo;

// Estruturas auxiliares da Fila (Para o Percurso em Extensão)
typedef struct FilaNo {
    ArvoreNo *noArvore;
    struct FilaNo *prox;
} FilaNo;

typedef struct {
    FilaNo *frente;
    FilaNo *tras;
} Fila;

// ==========================================
// 2. FUNÇÕES BÁSICAS DA ÁRVORE
// ==========================================
ArvoreNo* criarNo(int valor) {
    ArvoreNo* novo = (ArvoreNo*)malloc(sizeof(ArvoreNo));
    if (novo != NULL) {
        novo->el = valor;
        novo->left = NULL;
        novo->right = NULL;
    }
    return novo;
}

ArvoreNo* inserir(ArvoreNo* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    
    if (valor < raiz->el) {
        raiz->left = inserir(raiz->left, valor);
    } else if (valor > raiz->el) {
        raiz->right = inserir(raiz->right, valor);
    }
    return raiz;
}

void imprimirArvore2D_util(ArvoreNo *raiz, int espaco_atual) {
    if (raiz == NULL) return;
    
    int espaco_entre_niveis = 5;
    espaco_atual += espaco_entre_niveis;

    imprimirArvore2D_util(raiz->right, espaco_atual);

    printf("\n");
    for (int i = espaco_entre_niveis; i < espaco_atual; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->el);

    imprimirArvore2D_util(raiz->left, espaco_atual);
}

void imprimirArvore2D(ArvoreNo *raiz) {
    imprimirArvore2D_util(raiz, 0);
    printf("\n");
}

// ==========================================
// 3. PERCURSO EM EXTENSÃO (Nível a Nível)
// ==========================================
void enfileirar(Fila *f, ArvoreNo *no) {
    FilaNo *novo = (FilaNo*)malloc(sizeof(FilaNo));
    novo->noArvore = no;
    novo->prox = NULL;
    if (f->tras != NULL) f->tras->prox = novo;
    f->tras = novo;
    if (f->frente == NULL) f->frente = novo;
}

ArvoreNo* desenfileirar(Fila *f) {
    if (f->frente == NULL) return NULL;
    FilaNo *temp = f->frente;
    ArvoreNo *no = temp->noArvore;
    f->frente = temp->prox;
    if (f->frente == NULL) f->tras = NULL;
    free(temp);
    return no;
}

void percursoExtensao(ArvoreNo *raiz) {
    if (raiz == NULL) return;
    
    Fila f = {NULL, NULL};
    enfileirar(&f, raiz);
    
    while (f.frente != NULL) {
        ArvoreNo *atual = desenfileirar(&f);
        printf("%d ", atual->el);
        
        if (atual->left != NULL) enfileirar(&f, atual->left);
        if (atual->right != NULL) enfileirar(&f, atual->right);
    }
    printf("\n");
}

// ==========================================
// 4. REMOÇÃO EM CASCATA (Apaga nó e filhos)
// ==========================================
void apagarSubarvore(ArvoreNo **no) {
    if (*no != NULL) {
        apagarSubarvore(&((*no)->left));
        apagarSubarvore(&((*no)->right));
        free(*no);
        *no = NULL; 
    }
}

void removerNoEFilhos(ArvoreNo **raiz, int el) {
    ArvoreNo *node = *raiz;
    ArvoreNo *prev = NULL;

    while (node != NULL) {
        if (node->el == el) break;
        prev = node;
        if (el < node->el) node = node->left;
        else node = node->right;
    }

    if (node != NULL && node->el == el) {
        if (node == *raiz) apagarSubarvore(raiz);
        else if (prev->left == node) apagarSubarvore(&(prev->left));
        else apagarSubarvore(&(prev->right));
        printf("\n-> Cascata: No %d e subarvore removidos.\n", el);
    } else {
        printf("\n-> Elemento %d nao encontrado.\n", el);
    }
}

// ==========================================
// 5. REMOÇÃO POR FUSÃO (Preserva os filhos)
// ==========================================
void deleteByMerging(ArvoreNo **node) {
    ArvoreNo *tmp = *node;
    if (*node != NULL) {
        if (!(*node)->right) {
            *node = (*node)->left; 
        } else if (!(*node)->left) {
            *node = (*node)->right; 
        } else {
            tmp = (*node)->left; 
            while (tmp->right != NULL) tmp = tmp->right; 
            tmp->right = (*node)->right; 
            tmp = *node; 
            *node = (*node)->left; 
        }
        free(tmp); 
    }
}

void findAndDeleteByMerging(ArvoreNo **raiz, int el) {
    ArvoreNo *node = *raiz;
    ArvoreNo *prev = NULL;

    while (node != NULL) {
        if (node->el == el) break;
        prev = node;
        if (el < node->el) node = node->left;
        else node = node->right;
    }

    if (node != NULL && node->el == el) {
        if (node == *raiz) deleteByMerging(raiz);
        else if (prev->left == node) deleteByMerging(&(prev->left));
        else deleteByMerging(&(prev->right));
        printf("\n-> Fusao: No %d removido (filhos preservados).\n", el);
    } else {
        printf("\n-> Elemento %d nao encontrado.\n", el);
    }
}

// ==========================================
// 6. PROGRAMA PRINCIPAL
// ==========================================
int main() {
    ArvoreNo* raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 30);

    printf("[ Arvore Original ]");
    imprimirArvore2D(raiz);

    printf("\n[ Percurso em Extensao ]\nOrdem: ");
    percursoExtensao(raiz);

    // Você pode escolher qual remoção testar comentando/descomentando abaixo:
    
    // Teste de Remoção em Cascata (Atividade principal)
    removerNoEFilhos(&raiz, 20);
    
    // Teste de Remoção por Fusão (Material do slide)
    // findAndDeleteByMerging(&raiz, 20);

    printf("\n[ Arvore Apos Remocao ]");
    imprimirArvore2D(raiz);

    // Limpeza final de memoria
    apagarSubarvore(&raiz);

    return 0;
}