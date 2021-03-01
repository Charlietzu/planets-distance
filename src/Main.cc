#include <iostream>
#include "ListaEncadeada.h"

FILE *arquivo_distancias;

int main(int argc, char* argv[]) {
    if (argc > 1){
        arquivo_distancias = fopen(argv[1], "rt");
        string nomeEntrada = argv[1];
        string numeroLinhaStr = argv[2];
        int numeroLinhas = stoi(numeroLinhaStr);

        ListaEncadeada* listaPlanetas = new ListaEncadeada();
        listaPlanetas->ProcessaEntrada(nomeEntrada, numeroLinhas);
        listaPlanetas->ImprimeLista();
    }

    return 0;
}