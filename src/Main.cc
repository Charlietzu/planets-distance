#include <iostream>
#include "ListaArranjo.h"

FILE *arquivo_distancias;

int main(int argc, char* argv[]) {
    if (argc > 1){
        arquivo_distancias = fopen(argv[1], "rt");
        string nomeEntrada = argv[1];
        string numeroLinhaStr = argv[2];
        int numeroLinhas = stoi(numeroLinhaStr);

        ListaArranjo* listaPlanetas = new ListaArranjo();
        listaPlanetas->ProcessaEntrada(nomeEntrada, numeroLinhas);
        int tamanhoLista = listaPlanetas->GetTamanhoPreenchido();

        //listaPlanetas->InsertionSort();
        listaPlanetas->MergeSort(0, tamanhoLista - 1);
        //listaPlanetas->QuickSort();
        listaPlanetas->ImprimeLista();
    }

    return 0;
}