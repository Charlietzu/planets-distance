#include "TipoItem.h"
#include <fstream>

using namespace std;


TipoItem::TipoItem(){
	chave = -1;
}

void TipoItem::SetEsq(int valor){
    esq = valor;
}

void TipoItem::SetDir(int valor){
    dir = valor;
}

void TipoItem::SetChave(int valor){
    chave = valor;
}

int TipoItem::GetChave(){
    return chave;
}

int TipoItem::GetDir(){
    return dir;
}

int TipoItem::GetEsq(){
    return esq;
}