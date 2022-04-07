#include <iostream>
#include "carta.h"
#include "jogador.h"
using namespace std;



void RodarJogo(TListaJogador &j, TListaCarta &b, int quantidade_jogadores){
    bool verificar = false;

    //while(verificar != quantidade_jogadores ){
        TElementoJogador * nav = j.inicio;
        cout << "-----------------------------------------------------------------------\n";
        DepurarLJogadores(j);
        cout << "-----------------------------------------------------------------------\n";
        system("pause");
        system("cls");
        int contador = 0;
         
        while(quantidade_jogadores > 0){
            contador++;
            cout << "-----------------------------------------------------------------------\n";
            cout << "Rodada" << contador << endl;
            while(nav != nullptr){
                    if (nav->Jogador.SomaCartas < 17){
                        TCarta CartaAuxiliar = Obter_Carta_Posicao(b,b.quantidade -1);
                        Remover_Final_LCarta(b);
                        Inserir_Final_LCartas(nav->Jogador.MaoJogador, CartaAuxiliar);
                        nav->Jogador.SomaCartas += CartaAuxiliar.valor;
                        cout << "-----------------------------------------------------------------------\n";
                        cout << "Jogador " << nav->Jogador.nome << " recebeu: " << nav->Jogador.MaoJogador << endl << endl;
                        quantidade_jogadores = Descobrir_Quantidade_Jogadores(j);
                    }   else {
                        quantidade_jogadores--;

                    }
                nav = nav->proximo;
            }
            nav = j.inicio;
            cout << "-----------------------------------------------------------------------\n";
            DepurarLJogadores(j);
            cout << "-----------------------------------------------------------------------\n";

            system("pause");
            system("cls");
        }  

}

void verificar_vitoria(){

}