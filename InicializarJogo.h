#include <iostream>
#include "carta.h"
#include "jogador.h"
using namespace std;

<<<<<<< HEAD
int verificar_vitoria(TListaJogador &j){
    TElementoJogador * nav = j.inicio;
    bool ganhou = false;
    while(nav != nullptr){
        if(nav->Jogador.SomaCartas == 21){
            cout << "O jogador " << nav->Jogador.nome << " Ganhou!" << endl << endl;
            ganhou = true;
        }
        nav= nav->proximo;
    }
    if (ganhou == true){
        return 0;
    } 

    nav = j.inicio;
    while(nav != nullptr){
        if(nav->Jogador.SomaCartas > 21){
            cout << "-----------------------------------------------------------------------\n\n";
            cout << "O jogador " << nav->Jogador.nome << " passou de 21 e foi eliminado!" << endl << endl;
            Remover_Posicao_LJogadores(j,Descobrir_Indice_LJogador(j,nav->Jogador.nome));

        }
        nav= nav->proximo;
    }



    system("pause");
    system("cls");


=======
<<<<<<< HEAD
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
    
    
>>>>>>> b3c6bb31c14095ee5063bd89de82db986f4ddc1a

    if(j.inicio == NULL){
        cout << "Não há vencedor";
        system("pause");
        system("cls");
        return 0;
    }
<<<<<<< HEAD
    
}



void RodarJogo(TListaJogador &j, TListaCarta &b, int quantidade_jogadores){
    srand(time(NULL));
    bool verificar = false;

    TElementoJogador * nav = j.inicio;
    int agressividade = 0;
    while(quantidade_jogadores > 0){
        DepurarLJogadores(j);
        cout << "-----------------------------------------------------------------------\n";

        system("pause");
        system("cls");


        while(nav != nullptr){
            int Indice_Jogador = Descobrir_Indice_LJogador(j, nav->Jogador.nome);
            if(Indice_Jogador % 2 == 0){
                agressividade = rand()%8+12;
            } else {
                agressividade = rand()%5+15;
            }
            if (nav->Jogador.SomaCartas < agressividade){
                TCarta CartaAuxiliar = Obter_Carta_Posicao(b,b.quantidade -1);
                Remover_Final_LCarta(b);
                Inserir_Final_LCartas(nav->Jogador.MaoJogador, CartaAuxiliar);
                nav->Jogador.SomaCartas += CartaAuxiliar.valor;                    
                cout << "-----------------------------------------------------------------------\n";
                cout << "\nO jogador " << nav->Jogador.nome << " comprou a carta: " << nav->Jogador.MaoJogador << endl << endl;
                quantidade_jogadores = Descobrir_Quantidade_Jogadores(j);
                } else {
                cout << "-----------------------------------------------------------------------\n";
                cout << "\nO jogador " << nav->Jogador.nome << " não realizou nenhuma jogada " << endl << endl;               
                quantidade_jogadores--;
            }
            nav = nav->proximo;
        } 
        nav = j.inicio;
    }  
    system("pause");
    system("cls");
    verificar_vitoria(j);
    DepurarLJogadores(j);
}
=======

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
=======


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
>>>>>>> 80ed5c5f49cbfcd7e2c6972f2ccefb10c1475fd3
>>>>>>> b3c6bb31c14095ee5063bd89de82db986f4ddc1a
