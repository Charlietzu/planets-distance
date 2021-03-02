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


        //listaPlanetas->InsertionSort();

        //listaPlanetas->QuickSort();

        //listaPlanetas->HeapSort();
       
        listaPlanetas->MergeSort(0, listaPlanetas->GetTamanhoPreenchido() - 1);

        listaPlanetas->ImprimeLista();
    }

    return 0;
}