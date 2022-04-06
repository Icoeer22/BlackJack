// Alunos: Bernardo Henrique Gaya, Guilherme Victor Butzke e Pablo Augusto de Quadros
#ifndef CONTROLECARTAS_H
#define CONTROLECARTAS_H
#define MAX 104
#include <iostream>
using namespace std;

const string NAIPES[] = {"Espada", "Copas", "Ouro", "Paus"};

struct TCarta{
	int naipe;
	int valor;
};

ostream &operator<<(ostream &os, TCarta c) {
  os << "Carta: {" << c.valor << " De " << NAIPES[c.naipe] << "}";
  return os;
}

struct TListaCarta{
    TCarta v[MAX];
    int quantidade;
};

void Inicializar_Lista_Cartas(TListaCarta &l){
    l.quantidade = 0;
}

void Inserir_Posicao_LCartas(TListaCarta &l,int pos, TCarta c){
     if (l.quantidade > MAX){
        throw "List Overflow";
    }
    if (pos > l.quantidade || pos < 0){
        throw  "Invalid Index";
    }
    for (int i = l.quantidade; i > pos; i--){
        l.v[i] = l.v[i-1];
    }

    l.v[pos] = c;
    l.quantidade++;
}

void Inserir_Inicio_LCartas(TListaCarta &l, TCarta c) {
  Inserir_Posicao_LCartas(l, 0, c);
}

void Inserir_Final_LCartas(TListaCarta &l, TCarta c) {
 Inserir_Posicao_LCartas(l, l.quantidade, c);
}

void Remover_Posicao_LCartas(TListaCarta &l, int pos) {
  if (l.quantidade > MAX) {
    throw "List Overflow";
  }
  if (pos > l.quantidade || pos < 0) {
    throw "Invalid index";
  }
  for (int i = pos; i < l.quantidade; i++) {
    l.v[i] = l.v[i + 1];
  }
  l.quantidade--;
}

void Remover_Inicio_LCartas(TListaCarta &l) {
  Remover_Posicao_LCartas(l, 0);
}


void Remover_Final_LCarta(TListaCarta &l) {
  Remover_Posicao_LCartas(l, l.quantidade);
}


void Trocar_Posicoes_LCartas(TListaCarta &l, int pos1, int pos2) {
  swap(l.v[pos1], l.v[pos2]);
}


void Imprimir_Lista_LCartas(TListaCarta &l) {
  for (int i = 0; i < l.quantidade; i++) {
    cout << endl << l.v[i] << endl;
  }
}

TCarta Obter_Carta_Posicao(TListaCarta &l, int pos){
    if(pos > l.quantidade || pos < 0){
        throw "Invalid Index";
    }
    return l.v[pos];
}

#endif