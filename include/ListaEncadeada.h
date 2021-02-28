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
        
        Planeta GetPlaneta(int pos);
        void SetPlaneta(Planeta planeta, int pos);
        void InsereFinal(Planeta planeta);
        void LimpaLista();
        int GetTamanho();
        void ProcessaEntrada(string nomeEntrada, int numeroLinhas);
        void ProcessaLinha(string linha);


    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
        int tamanho;
};

#endif