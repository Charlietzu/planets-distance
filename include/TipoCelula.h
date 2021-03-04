#ifndef TIPOCELULA_H
#define TIPOCELULA_H

#include "TipoItem.h"
#include <fstream>
#include <iostream>

class TipoCelula {
    public:
        TipoCelula();

    private:
        TipoItem item;
        TipoCelula *prox;

    friend class PilhaEncadeada;
};

#endif