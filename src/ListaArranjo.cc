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

void ListaArranjo::Particao(int Esq, int Dir, int *i, int *j){
    Planeta *x, *w;

    *i = Esq; 
    *j = Dir;
    x = planetas[(*i + *j)/2];

    do {
        while (x->GetDistanciaPlaneta() < planetas[*i]->GetDistanciaPlaneta() && planetas[*i] != NULL) (*i)++;
        while (x->GetDistanciaPlaneta() > planetas[*j]->GetDistanciaPlaneta() && planetas[*j] != NULL) (*j)--;
        if(*i <= *j){
            w = planetas[*i];
            planetas[*i] = planetas[*j];
            planetas[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void ListaArranjo::Ordena(int Esq, int Dir){
    int i, j;
    Particao(Esq, Dir, &i, &j);
    if(Esq < j) Ordena(Esq, j);
    if(i < Dir) Ordena(i, Dir);
}

void ListaArranjo::QuickSort(){
    Ordena(0, tamanhoPreenchido-1);
}

void ListaArranjo::MergeSort(int Esq, int Dir){
    if(Esq < Dir){
        int meio = (Esq + Dir)/2;
        MergeSort(Esq, meio);
        MergeSort(meio + 1, Dir);
        Merge(Esq, meio, Dir);
    }
}

void ListaArranjo::Merge(int Esq, int meio, int Dir){
    int n1 = meio - Esq + 1;
    int n2 = Dir - meio;

    Planeta *Esquerda[200000];
    Planeta *Direita[200000];

    for(int i = 0; i < n1; i++){
        Esquerda[i] = planetas[Esq + i];
    }
    
    for(int j = 0; j < n2; j++){
        Direita[j] = planetas[meio + 1 + j];
    }

    int i = 0, j = 0, k = Esq;

    while (i < n1 && j < n2){
        if(Esquerda[i] <= Direita[j]){
            planetas[k] = Esquerda[i];
        } else {
            planetas[k] = Direita[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        planetas[k] = Esquerda[i];
        i++;
        k++;
    }

    while(j < n2){
        planetas[k] = Direita[j];
        j++;
        k++;
    }
}

int ListaArranjo::GetTamanhoPreenchido(){
    return tamanhoPreenchido;
}