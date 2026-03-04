#include <iostream>
#include "../arv.h"

using namespace std;

bool eb(Arv A) {
    if(A == nullptr) {
        return true;
    }

    if (A->esq == nullptr && A->dir == nullptr) { 
        return true;
    }

    if(A->esq != nullptr && A->dir != nullptr) {
        return eb(A->esq) &&  eb(A->dir);
    }
    return false;
}

int main() {
    Arv R = cria_arv(
                cria_arv(cria_arv(nullptr, 4, nullptr), 2, cria_arv(nullptr, 5, nullptr)),
                1, 
                cria_arv(nullptr, 3, cria_arv(nullptr, 6, nullptr)) // Esquerda do 3 não tem filhos
    );

    if(eb(R)) {
        cout << "\nA arvore eh estritamente binaria." << endl;
    } else {
        cout << "\n A arvore nao eh estritamente binaria." << endl;
    }

    cout << "\nArvore: \n" << endl;
    exibe_arvore(R);
    destroi(R);
    return 0;
}