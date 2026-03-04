#include <iostream>
#include "../arv.h"

using namespace std;

bool tem(Arv A, Item x) {
    if (A == nullptr) {
        return false;
    }
    if (A->item == x) {
        return true;
    }
    return tem(A->esq, x) || tem(A->dir, x);
}

int main() {
    Arv R = cria_arv(
                cria_arv(cria_arv(nullptr, 4, nullptr), 
                2, 
                cria_arv(nullptr, 5, nullptr)),

                1, 
                cria_arv(nullptr, 3, cria_arv(nullptr, 6, nullptr))
    );

    int busca = 5;

    if (tem(R, busca)) {
        cout << "\nO item " << busca << " ESTA na arvore." << endl;
    } else {
        cout << "\nO item " << busca << " NAO esta na arvore" << endl;
    }

    cout << "\nArvore: \n" << endl;
    exibe_arvore(R);

    destroi(R);
    return 0;
}