#ifndef LISTAARRANJO_H
#define LISTAARRANJO_H

#include "Planeta.h"
#include <fstream>
#include <iostream>

class ListaArranjo {
    public:
        ListaArranjo();
        ~ListaArranjo();
        
        Planeta* GetPlaneta(int pos);
        void InsereInicio(Planeta *planeta);
        void LimpaLista();
        int GetTamanhoPreenchido();
        void ProcessaEntrada(string nomeEntrada, int numeroLinhas);
        void ProcessaLinha(string linha, int pos);
        void ImprimeLista();
        void InsertionSort();

    private:
        int tamanhoPreenchido;
        static const int MAXTAM = 200000;
        Planeta *planetas[MAXTAM];
};

#endif