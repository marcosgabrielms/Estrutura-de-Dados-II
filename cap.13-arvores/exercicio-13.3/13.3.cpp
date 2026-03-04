#include <iostream>
#include "../arv.h"

using namespace std;

int folhas(Arv A) {
    if (A == nullptr) {
        return 0;
    }

if (A->esq == nullptr && A->dir == nullptr) {
    return 1;
}

return folhas(A->esq) + folhas(A->dir);
}

int main() {
    Arv R = cria_arv(cria_arv(cria_arv(nullptr, 4, nullptr), 2, cria_arv(nullptr, 5, nullptr)), 1, cria_arv(nullptr, 3, cria_arv(nullptr, 6, nullptr)));

    cout << "Total de folhas na arvore: " << folhas(R) << endl;

    destroi(R);
    
    return 0;
}