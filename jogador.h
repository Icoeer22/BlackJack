#ifndef JOGADOR_H
#define JOGADOR_H
#include "carta.h"
#include "ControleJogadores.h"
#include <iostream>


using namespace std;

TListaJogador Criar_Jogadores(int quantidade_jogadores){
    TListaJogador Jogadores;
    Inicializar_Lista_Jogadores(Jogadores);
    for (int i = 0 ; i < quantidade_jogadores; i ++){
        Pessoa Jogador;
        Jogador.nome = "Player" + to_string(i+1);
        Jogador.SomaCartas = 0;
        Inicializar_Lista_Cartas(Jogador.MaoJogador);
        Inserir_Fim_LJogadores(Jogadores, Jogador);
    }
    return Jogadores;
}



void Distribuir_Cartas(TListaCarta &b, TListaJogador &j){
    TElementoJogador * nav = j.inicio;
    while (nav != nullptr){
        for(int i = 0 ; i < 2 ; i++){
            TCarta CartaAuxiliar = Obter_Carta_Posicao(b,b.quantidade -1);
            Remover_Final_LCarta(b);
            Inserir_Final_LCartas(nav->Jogador.MaoJogador, CartaAuxiliar);
            nav->Jogador.SomaCartas += CartaAuxiliar.valor;
        }
        nav = nav->proximo;
    }
}


















#endif