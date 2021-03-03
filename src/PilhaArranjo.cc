#include "PilhaArranjo.h"
#include <fstream>

using namespace std;


PilhaArranjo::PilhaArranjo(){
	tamanho = 0;
    topo = -1;
}

void PilhaArranjo::Empilha(Planeta* planeta){
	if(tamanho == MAXTAM){
        throw "A pilha está cheia!";
    }

    topo++;
    planetas[topo] = planeta;
    tamanho++;
}

Planeta* PilhaArranjo::Desempilha(){
	if(tamanho == 0){
        throw "A pilha está vazia!";
    }

    Planeta* aux;
    aux = planetas[topo];
    topo--;
    tamanho--;
    return aux;
}

void PilhaArranjo::Limpa(){
    topo = -1;
    tamanho = 0;
}

int PilhaArranjo::GetTamanho(){
    return tamanho;
}

