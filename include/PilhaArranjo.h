#ifndef PILHAARRANJO_H
#define PILHAARRANJO_H

#include "Planeta.h"
#include <fstream>
#include <iostream>

class PilhaArranjo {
    public:
        PilhaArranjo();
        ~PilhaArranjo();
        
        void Empilha(Planeta* planeta);
        Planeta* Desempilha();
        void Limpa();
        int GetTamanho();

    private:
        int topo;
        int tamanho;
        static const int MAXTAM = 200000;
        Planeta *planetas[MAXTAM];
};

#endif