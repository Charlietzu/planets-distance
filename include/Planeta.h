#ifndef PLANETA_H
#define PLANETA_H

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Planeta {
    public:
        Planeta();
        Planeta(string nome, int distancia);

        void SetNomePlaneta(string nome);
        void SetDistanciaPlaneta(int dist);
        string GetNomePlaneta();
        int GetDistanciaPlaneta();
        void ImprimePlaneta();
        void SetEsq(int esq);
        void SetDir(int dir);
        int GetEsq();
        int GetDir();
        
    private:
        int distanciaPlaneta;
        string nomePlaneta;
        int esq;
        int dir;
    
};

#endif