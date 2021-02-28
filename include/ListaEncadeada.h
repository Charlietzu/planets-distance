#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "Planeta.h"
#include "TipoCelula.h"

class ListaEncadeada {
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        
        Planeta GetPlaneta(int pos);
        void SetPlaneta(Planeta planeta, int pos);
        void InsereFinal(Planeta planeta);
        void LimpaLista();
        int GetTamanho();


    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
        int tamanho;
};

#endif