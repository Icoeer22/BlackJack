#include <iostream>
#include "carta.h"
#include "jogador.h"
using namespace std;

int verificar_vitoria(TListaJogador &j){
    TElementoJogador * nav = j.inicio;
    while(nav != nullptr){
        if(nav->Jogador.SomaCartas == 21){
            cout << "O jogador " << nav->Jogador.nome << " Ganhou!" << endl; 
        } 
        else{ 
            if(nav->Jogador.SomaCartas > 21){
                int indice_jogador = Descobrir_Indice_LJogador(j, nav->Jogador.nome);
                Remover_Posicao_LJogadores(j,indice_jogador);
                system("pause");
                system("cls");
            }
        }
        nav= nav->proximo;
    }
    
    

    if(j.inicio == NULL){
        cout << "Não há vencedor";
        system("pause");
        system("cls");
        return 0;
    }

}


void Jogador_Jogando(TElementoJogador * &nav, TListaCarta &b){
    TCarta CartaAuxiliar = Obter_Carta_Posicao(b,b.quantidade -1);
    Remover_Final_LCarta(b);
    Inserir_Final_LCartas(nav->Jogador.MaoJogador, CartaAuxiliar);
    nav->Jogador.SomaCartas += CartaAuxiliar.valor;
    cout << "-----------------------------------------------------------------------\n";
    cout << "Jogador " << nav->Jogador.nome << " recebeu: " << nav->Jogador.MaoJogador << endl << endl;
}

void RodarJogo(TListaJogador &j, TListaCarta &b, int quantidade_jogadores){
    bool verificar = false;

    //while(verificar != quantidade_jogadores ){
        TElementoJogador * nav = j.inicio;
        int contador = 0;
        int agressividade = 0;
        while(quantidade_jogadores > 0){
            contador++;
            cout << "\n-----------------------------------------------------------------------\n\n";
            DepurarLJogadores(j);
            cout << "-----------------------------------------------------------------------\n";

            system("pause");
            system("cls");


            while(nav != nullptr){
                int Indice_Jogador = Descobrir_Indice_LJogador(j, nav->Jogador.nome);
                if(Indice_Jogador % 2 == 0){
                    agressividade = 16;
                } else {
                    agressividade = 19;
                }

                if (nav->Jogador.SomaCartas < agressividade){
                    Jogador_Jogando(nav, b);
                    quantidade_jogadores = Descobrir_Quantidade_Jogadores(j);
                    } else {
                    quantidade_jogadores--;
                }
                nav = nav->proximo;
            } 
            nav = j.inicio;

        }  
    verificar_vitoria(j);
    DepurarLJogadores(j);
}
