#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include "Planeta.h"
#include "TipoCelula.h"
#include <fstream>
#include <iostream>

class ListaEncadeada {
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        
        Planeta* GetPlaneta(int pos);
        void InsereFinal(Planeta *planeta);
        void InsereInicio(Planeta *planeta);
        void InserePosicao(Planeta *planeta, int pos);
        void LimpaLista();
        int GetTamanho();
        void ProcessaEntrada(string nomeEntrada, int numeroLinhas);
        void ProcessaLinha(string linha, int pos);
        void ImprimeLista();


    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
        int tamanho;
};

#endif