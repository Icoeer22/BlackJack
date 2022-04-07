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
<<<<<<< HEAD
=======
    //Imprimir_Lista_LCartas(Baralho_Mesa);
>>>>>>> b3c6bb31c14095ee5063bd89de82db986f4ddc1a
    int quantidade_jogadores = 4;
    TListaJogador Jogadores;
    Jogadores = Criar_Jogadores(quantidade_jogadores);
    Distribuir_Cartas(Baralho_Mesa, Jogadores);
<<<<<<< HEAD
=======
    //DepurarLJogadores(Jogadores,2);
>>>>>>> b3c6bb31c14095ee5063bd89de82db986f4ddc1a
    RodarJogo(Jogadores,Baralho_Mesa, quantidade_jogadores);
   
}

