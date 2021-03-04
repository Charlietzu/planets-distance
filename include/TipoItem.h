#ifndef TIPOITEM_H
#define TIPOITEM_H

#include <fstream>
#include <iostream>

class TipoItem {
    public:
        TipoItem();
        void SetChave(int c);
        void SetDir(int dir);
        void SetEsq(int esq);
        int GetChave();
        int GetEsq();
        int GetDir();
        
    private:
        int chave;
        int esq;
        int dir;
};

#endif