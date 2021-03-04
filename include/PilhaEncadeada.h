#ifndef PILHAENCADEADA_H
#define PILHAENCADEADA_H

#include "TipoItem.h"
#include "TipoCelula.h"
#include <fstream>
#include <iostream>

class PilhaEncadeada {
    public:
        PilhaEncadeada();
        ~PilhaEncadeada();
        
        void Empilha(TipoItem item);
        TipoItem Desempilha();
        void Limpa();
        int GetTamanho();
        bool Vazia();

    private:
        TipoCelula* topo;
        int tamanho;
};

#endif