#include <iostream>
#include "carta.h"
#include "jogador.h"
using namespace std;


void RodarJogo(TListaJogador &j, TListaCarta &b, int quantidade_jogadores){
    int verificar = 0;
   
    while(verificar != quantidade_jogadores ){
        TElementoJogador * nav = j.inicio;
        while(nav->proximo = nullptr){
            int soma_mao = 0;
            for(int i = 0; i < nav->Jogador.MaoJogador.quantidade; i++){
                soma_mao = soma_mao + nav->Jogador.MaoJogador.v[i].valor;
            }
            if(soma_mao < 17){
                TCarta CartaAuxiliar = Obter_Carta_Posicao(b,b.quantidade -1);
                Remover_Final_LCarta(b);
                Inserir_Final_LCartas(nav->Jogador.MaoJogador, CartaAuxiliar);
                verificar = verificar -1 ;
            }
            else{
                verificar = verificar +1;
                
            }
            nav= nav->proximo;
        }
            
    }
    DepurarLJogadores(j);
}

void Inicializar_Jogo(){
    TListaCarta Baralho_Mesa;
    Baralho_Mesa = Criar_Baralho();
    Embaralhar(Baralho_Mesa);
    //Imprimir_Lista_LCartas(Baralho_Mesa);
    int quantidade_jogadores = 4;
    TListaJogador Jogadores;
    Jogadores = Criar_Jogadores(quantidade_jogadores);
    Distribuir_Cartas(Baralho_Mesa, Jogadores);
    //DepurarLJogadores(Jogadores,2);
    RodarJogo(Jogadores,Baralho_Mesa,quantidade_jogadores);
}

