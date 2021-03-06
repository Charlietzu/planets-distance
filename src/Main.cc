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
    
        /*  
            INÍCIO DOS ALGORITMOS DE ORDENAÇÃO

            - LEMBRANDO QUE SOMENTE UM MÉTODO PODE ESTAR DESCOMENTADO POR VEZ.
            - DESCOMENTAR APENAS O QUE DESEJA EXECUTAR.
        */

        //listaPlanetas->InsertionSort();

        listaPlanetas->QuickSort();
       
        //listaPlanetas->MergeSort(0, listaPlanetas->GetTamanhoPreenchido() - 1);

        //listaPlanetas->CockTailSort();

        //listaPlanetas->QuickSortNaoRecursivo();

        /*
            FIM DOS ALGORITMOS DE ORDENAÇÃO.
        */

        listaPlanetas->ImprimeLista();

        listaPlanetas->LimpaLista();

        delete listaPlanetas;
    }

    return 0;
}