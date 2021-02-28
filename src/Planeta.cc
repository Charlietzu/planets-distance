#include "Planeta.h"

using namespace std;

Planeta::Planeta() {
    nomePlaneta = "";
    distanciaPlaneta = -1;
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