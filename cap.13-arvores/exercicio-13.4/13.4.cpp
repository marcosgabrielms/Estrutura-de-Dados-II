#include <iostream>
#include <algorithm>
#include "../arv.h"

using namespace std;

int altura(Arv A) {
    if (A == nullptr) {
        return 0;
    }

    return 1 + max(altura(A->esq), altura(A->dir));
}

int main(){
    Arv R = cria_arv(
                cria_arv(cria_arv(nullptr,4,nullptr), 2, cria_arv(nullptr,5,nullptr)), 1, cria_arv(nullptr,3, cria_arv(nullptr, 6, nullptr))
    );

    cout << "Altura da Arvore: " << altura(R) << endl;

    return 0;
}