#include "ListaEncadeada.h"
#include <fstream>

using namespace std;

ListaEncadeada::ListaEncadeada(){
	primeiro = new TipoCelula();
	ultimo = primeiro;
	tamanho = 0;
}

ListaEncadeada::~ListaEncadeada(){
	LimpaLista();
	delete primeiro;
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes = false) {
	TipoCelula* p;
	int i;

	if ((pos > tamanho) || (pos <= 0)) {
		throw "Erro: Posicao Invalida!";
	}

	p = primeiro;
	for (i = 1; i < pos; i++) {
		p = p->prox;
	}

	if (!antes) {
		p = p->prox;
	}

	return p;
}

Planeta* ListaEncadeada::GetPlaneta(int pos) {
	TipoCelula* p;

	p = Posiciona(pos);
	return p->planeta;
}

void ListaEncadeada::InsereInicio(Planeta *planeta){
	TipoCelula* nova;

	nova = new TipoCelula();
	nova->planeta = planeta;
	nova->prox = primeiro->prox;
	primeiro->prox = nova;
	tamanho++;

	if(nova->prox == NULL){
		ultimo = nova;
	}
}

void ListaEncadeada::InserePosicao(Planeta *planeta, int pos){
	TipoCelula* p;
	TipoCelula* nova;

	p = Posiciona(pos, true);

	nova = new TipoCelula();
	nova->planeta = planeta;
	nova->prox = p->prox;
	p->prox = nova;
	tamanho++;

	if(nova->prox == NULL){
		ultimo = nova;
	}
}

void ListaEncadeada::InsereFinal(Planeta *planeta) {
	TipoCelula* nova;

	nova = new TipoCelula();
	nova->planeta = planeta;
	ultimo->prox = nova;
	ultimo = nova;

	tamanho++;
}

int ListaEncadeada::GetTamanho() {
	return tamanho;
}

void ListaEncadeada::LimpaLista() {
	TipoCelula* p;

	p = primeiro->prox;
	while (p != NULL) {
		primeiro->prox = p->prox;
		delete p;
		p = primeiro->prox;
	}

	ultimo = primeiro;
	tamanho = 0;
}

void ListaEncadeada::ProcessaEntrada(string nomeEntrada, int numeroLinhas) {
	int i = 0;
	string linha;
	ifstream arquivo;
	arquivo.open(nomeEntrada, ios::in);
	
	while (getline(arquivo, linha) && i < 7) {
		++i;
		ProcessaLinha(linha, i);
	}
}

void ListaEncadeada::ProcessaLinha(string linha, int pos) {
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
	InserePosicao(planeta, pos);
}

void ListaEncadeada::ImprimeLista(){
	for(int i = 1; i < tamanho; i++){
		Planeta* planeta = GetPlaneta(i);
		planeta->ImprimePlaneta();
	}
}