// Alunos: Bernardo Henrique Gaya, Guilherme Victor Butzke e Pablo Augusto de Quadros
#include <iostream>
#include "carta.h"
#include "jogador.h"
#include "InicializarJogo.h"
using namespace std;

int main(){
   TListaCarta Baralho_Mesa;
    Baralho_Mesa = Criar_Baralho();
    Embaralhar(Baralho_Mesa);
    //Imprimir_Lista_LCartas(Baralho_Mesa);
    int quantidade_jogadores = 4;
    TListaJogador Jogadores;
    Jogadores = Criar_Jogadores(quantidade_jogadores);
    Distribuir_Cartas(Baralho_Mesa, Jogadores);
    //DepurarLJogadores(Jogadores,2);
    RodarJogo(Jogadores,Baralho_Mesa, quantidade_jogadores);
   
}

