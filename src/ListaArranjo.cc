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

int ListaArranjo::GetTamanhoPreenchido(){
    return tamanhoPreenchido;
}

void ListaArranjo::Troca(int i, int menor){
    Planeta *aux;

    aux = planetas[i];
    planetas[i] = planetas[menor];
    planetas[menor] = aux;
}

void ListaArranjo::Merge(int e, int m, int d){
    int numEsq = m - e + 1;
    int numDir = d - m;
 
    Planeta** esquerda = (Planeta**)malloc((numEsq) * sizeof(Planeta*));
    Planeta** direita = (Planeta**)malloc((numDir) * sizeof(Planeta*));

    for (int i = 0; i < numEsq; i++){
        esquerda[i] = planetas[e + i];
    }
    for (int j = 0; j < numDir; j++){
        direita[j] = planetas[m + 1 + j];
    }
 
    int i = 0, j = 0, k = e;
 
    while (i < numEsq && j < numDir) {
        if (esquerda[i]->GetDistanciaPlaneta() > direita[j]->GetDistanciaPlaneta()) {
            planetas[k] = esquerda[i];
            i++;
        } else {
            planetas[k] = direita[j];
            j++;
        }
        k++;
    }
 
    while (i < numEsq) {
        planetas[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < numDir) {
        planetas[k] = direita[j];
        j++;
        k++;
    }
}

void ListaArranjo::MergeSort(int esq,int dir){
    if(esq < dir){
        int m = esq + (dir - esq)/2;
        MergeSort(esq, m);
        MergeSort(m + 1, dir);
        Merge(esq, m, dir);
    }

}

void ListaArranjo::CockTailSort(){
    bool trocou = true;
    int inicio = 0;
    int final = tamanhoPreenchido - 1;
 
    while (trocou) {
        trocou = false;
 
        for (int i = inicio; i < final; ++i){
            if (planetas[i]->GetDistanciaPlaneta() < planetas[i + 1]->GetDistanciaPlaneta()) {
                Troca(i, i + 1);
                trocou = true;
            }
        }
 
        if (!trocou){
            break;
        }

        trocou = false;
        --final;

        for (int i = final - 1; i >= inicio; --i){
            if (planetas[i]->GetDistanciaPlaneta() < planetas[i + 1]->GetDistanciaPlaneta()) {
                Troca(i, i + 1);
                trocou = true;
            }
        }
        ++inicio;
    }
}