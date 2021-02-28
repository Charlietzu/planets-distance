#ifndef TIPOCELULA_H
#define TIPOCELULA_H

#include "Planeta.h"

class TipoCelula {
    public:
        TipoCelula();

    private:
        Planeta planeta;
        TipoCelula *prox;

    friend class ListaEncadeada;
};

#endif