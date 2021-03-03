#include "Planeta.h"

using namespace std;

Planeta::Planeta() {
    nomePlaneta = "";
    distanciaPlaneta = -1;
    esq = -1;
    dir = -1;
}

Planeta::Planeta(string nome, int distancia){
    nomePlaneta = nome;
    distanciaPlaneta = distancia;
}

void Planeta::SetNomePlaneta(string nome){
    nomePlaneta = nome;
}

void Planeta::SetDistanciaPlaneta(int distancia){
    distanciaPlaneta = distancia;
}

string Planeta::GetNomePlaneta(){
    return nomePlaneta;
}

int Planeta::GetDistanciaPlaneta(){
    return distanciaPlaneta;
}

void Planeta::ImprimePlaneta() {
    cout << "Nome: " << GetNomePlaneta() << " - Distancia: " << GetDistanciaPlaneta() << endl;
}

void Planeta::SetEsq(int valor){
    esq = valor;
}

void Planeta::SetDir(int valor){
    dir = valor;
}

int Planeta::GetDir(){
    return dir;
}

int Planeta::GetEsq(){
    return esq;
}