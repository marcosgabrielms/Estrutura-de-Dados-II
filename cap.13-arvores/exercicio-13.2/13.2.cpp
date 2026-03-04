#include <iostream>
#include "../arv.h"

int nos(Arv A) {
    if (A == nullptr) {
        return 0;
    }
    return 1 + nos(A->esq) + nos(A->dir);
}

int main() {
    Arv R = cria_arv(
                cria_arv(cria_arv(nullptr, 4, nullptr), 2, cria_arv(nullptr, 5, nullptr)), // Árvore esquerda
                1,                                                                         // Raiz
                cria_arv(nullptr, 3, cria_arv(nullptr, 6, nullptr))                        // Árvore Direita
    );
    
    std::cout << "Total de nos na arvore: " << nos(R) << std::endl;

    destroi(R);

    return 0;
}