#include <iostream>
#include "../arv.h"

int main() {
    Arv R = cria_arv(
                cria_arv(cria_arv(nullptr, 4, nullptr), 2, cria_arv(nullptr, 5, nullptr)),
                1, 
                cria_arv(nullptr, 3, cria_arv(nullptr, 6, nullptr))
    );

    std::cout << "Arvore em pre-ordem: ";
    preordem(R);
    std::cout << std::endl;

    destroi(R);

    return 0;
}