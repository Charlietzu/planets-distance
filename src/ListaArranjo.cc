#include "ListaArranjo.h"
#include <fstream>

using namespace std;


ListaArranjo::ListaArranjo(){
	tamanhoPreenchido = 0;
}

void ListaArranjo::InsereInicio(Planeta *planeta){
    if(tamanhoPreenchido == MAXTAM){
        throw "Erro: Lista Cheia!";
    }

    tamanhoPreenchido++;
    for(int i = tamanhoPreenchido; i>0; i--){
        planetas[i] = planetas[i-1];
    }

    planetas[0] = planeta;
}

void ListaArranjo::ImprimeLista(){
    for(int i = 0; i < tamanhoPreenchido; i++){
        planetas[i]->ImprimePlaneta();
    }
}

void ListaArranjo::LimpaLista(){
    for(int i = 0; i < tamanhoPreenchido; i++){
        delete planetas[i];
    }
    tamanhoPreenchido = 0;
}

void ListaArranjo::ProcessaEntrada(string nomeEntrada, int numeroLinhas) {
	int i = 0;
	string linha;
	ifstream arquivo;
	arquivo.open(nomeEntrada, ios::in);
	
	while (getline(arquivo, linha) && i < 7) {
		++i;
		ProcessaLinha(linha, i);
	}
}

void ListaArranjo::ProcessaLinha(string linha, int pos) {
	string nomePlaneta = "", distanciaStr = "";
	int numeroAux, tamanhoLinha = linha.length();
	for(int i = 0; i < tamanhoLinha; i++){
		if(linha[i] == ' '){
			numeroAux = i + 1;
			break;
		} else {
			nomePlaneta += linha[i]; 
		}
	}
	for(int i = numeroAux; i < tamanhoLinha; i++){
		if(isdigit(linha[i])){
			distanciaStr += linha[i];
		}
	}
	Planeta* planeta = new Planeta(nomePlaneta, stoi(distanciaStr));
	InsereInicio(planeta);
}

void ListaArranjo::InsertionSort(){
    Planeta* aux;
    int i, j;

    for(i = 1; i < tamanhoPreenchido; i++){
        aux = planetas[i];
        j = i - 1;
        while((j >= 0) &&
            (aux->GetDistanciaPlaneta() >= planetas[j]->GetDistanciaPlaneta())){
            planetas[j + 1] = planetas[j];
            j--;
        }
        planetas[j + 1] = aux;
    }
}