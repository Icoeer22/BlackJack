// Alunos: Bernardo Henrique Gaya, Guilherme Victor Butzke e Pablo Augusto de Quadros
#ifndef CARTA_H
#define CARTA_H
#include "ControleCartas.h"
#include <iostream>
#include "time.h"

using namespace std;

TListaCarta Criar_Baralho(){
    TListaCarta Baralho;
    Inicializar_Lista_Cartas(Baralho);
    for (int i = 0; i < 104; i++) {
    TCarta carta;
    carta.naipe = i / 26;
    carta.valor = (i % 13) + 1;
    if (carta.valor > 10){
      carta.valor = 10;
    }
    Inserir_Final_LCartas(Baralho, carta);
  }
  return Baralho;
}

void Embaralhar(TListaCarta &baralho){
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
    int posicao1 = rand() % 104;
    int posicao2 = rand() % 104;
    Trocar_Posicoes_LCartas(baralho, posicao1, posicao2);
  }
}

#endif