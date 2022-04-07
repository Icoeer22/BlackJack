#ifndef CONTROLEJOGADORES_H
#define CONTROLEJOGADORES_H
#include <iostream>
#include "ControleCartas.h"


using namespace std;

struct Pessoa{
    string nome;
    TListaCarta MaoJogador;
    int SomaCartas;
};

struct TElementoJogador{
    Pessoa Jogador;
    TElementoJogador *proximo;
};

struct TListaJogador{
    TElementoJogador * inicio;
};

void Inicializar_Lista_Jogadores(TListaJogador &l){
    l.inicio = nullptr;
}

void Inserir_Posicao_LJogadores(TListaJogador &l, Pessoa j, int pos){
    TElementoJogador * novo = new TElementoJogador;
    novo ->Jogador = j; 
    novo -> proximo = nullptr;
    int cont = 0;
    for(TElementoJogador * nav  = l.inicio; nav != nullptr; nav = nav->proximo){
        cont = cont+1;
    }
    if (l.inicio == nullptr){
        l.inicio = novo;
    }
    else if(pos-1 > cont || pos < 0 ){
        cout << "Posição Invalida" << endl;
    }
    else{
        TElementoJogador * nav = l.inicio;
        nav = nav->proximo;
        for(int i = 0; i < pos-1; i++){
            nav = nav->proximo;
        }
        novo->proximo = nav->proximo;
        nav->proximo = novo;
    }
}

void Inserir_Fim_LJogadores(TListaJogador &l, Pessoa j){
    TElementoJogador * novo = new TElementoJogador;
    novo->Jogador  = j;
    novo->proximo = nullptr;
    if (l.inicio == nullptr){
        l.inicio = novo;
    }
    else{
        TElementoJogador * nav = l.inicio;
        while (nav->proximo != nullptr){
            nav = nav->proximo;
        }
        nav->proximo = novo;
    }
}

void Inserir_Inicio_LJogadores(TListaJogador &l, Pessoa j ){
    TElementoJogador * novo = new TElementoJogador;
    novo->Jogador  = j ;
    novo->proximo = nullptr;
    if (l.inicio == nullptr){
        l.inicio = novo;
    }
    else{
        novo->proximo = l.inicio;
        l.inicio= novo;
    }
}

void Remover_Fim_LJogadores(TListaJogador &l){
  if(l.inicio == nullptr){
    cout << "Não é possivel remover nenhum item";
  }
  else{
    TElementoJogador * nav = l.inicio;
    while (nav->proximo->proximo != nullptr){
        nav = nav->proximo;
    }
    nav->proximo = nullptr;
  }
}

void Remover_Inicio_LJogadores(TListaJogador &j){
    if(j.inicio == nullptr){
        cout << "Não é possivel remover nenhum item";
    }
    else {
       TElementoJogador * nav = j.inicio;
       j.inicio = nav->proximo;
       delete nav; 
    }
}

void Remover_Posicao_LJogadores(TListaJogador &j, int pos){
    int cont = 0;
    for (TElementoJogador * nav = j.inicio; nav != nullptr; nav = nav->proximo){
        cont = cont+1;
    }
    if (j.inicio == nullptr){
        cout << "Não é possivel remover nenhum item";
    }
    else if(pos > cont || pos < 0 ){
        cout << "Posição Invalida" << endl;
    }
    else{
        if(pos == cont){
            Remover_Fim_LJogadores(j);
        }
        else if(pos == 0){
            Remover_Inicio_LJogadores(j);
        }
        else{
            TElementoJogador * nav = j.inicio;
            for(int i = 0; i < pos - 1; i++){
                nav = nav->proximo;
            }
            TElementoJogador *Apagar = nav->proximo;
            nav->proximo = Apagar->proximo;
            delete Apagar;
        }
    }

}

bool Contem_Item_LJogadores(TListaJogador &j, string nomeJogador){
    if(j.inicio == nullptr){
        return false;
    }
    TElementoJogador * nav = j.inicio;
    while(nav->proximo != nullptr){
        if (nav->Jogador.nome == nomeJogador){
            return true;
        } 
        else {
            nav = nav->proximo;
        }
    }
    return false;
}

string Obter_Jogador_Posicao(TListaJogador &j, int pos){
    int cont = 0;
    for (TElementoJogador * nav = j.inicio; nav->proximo != nullptr; nav = nav->proximo){
        cont = cont+1;
    }
    if (j.inicio == nullptr){
        return "Lista vazia";
    }
    else if (pos > cont || pos < 0 ){
        return "Posição invalida";
    } 
    else {
        int contador = 0;
        TElementoJogador * nav = j.inicio;
        while(nav != nullptr){
            if(contador == pos){
                return nav->Jogador.nome;
            }
            contador++;
            nav = nav->proximo;
        }
    }
    return "Item não encontrado";
}

int Descobrir_Indice_LJogador(TListaJogador &j, string nomeJogador){
    if (j.inicio == nullptr){
        return -1;
    } 
    else {
        int contador = 0;
        TElementoJogador * nav = j.inicio;
        while(nav != nullptr){
            if(nav->Jogador.nome == nomeJogador){
                return contador;
            }
            contador++;
            nav = nav->proximo;
        }
    }
    return -1;
}



int Descobrir_Quantidade_Jogadores(TListaJogador &j){
    int contador = 0;
    if (j.inicio == nullptr){
        return -1;
    } 
    else {
        TElementoJogador * nav = j.inicio;
        while(nav != nullptr){
            contador++;
            nav = nav->proximo;
        }
    }
    return contador;
}

void DepurarLJogadores(TListaJogador l){
    int i = 0;
    for(TElementoJogador * nav = l.inicio; nav != nullptr; nav= nav->proximo){
        cout << "-----------------------------------------------------------------------\n\n";
        cout << "O jogador " << nav->Jogador.nome << " Possui as cartas:  ";
        for (int j = 0; j < nav->Jogador.MaoJogador.quantidade; j++){
            cout << endl << nav->Jogador.MaoJogador.v[j]; 
        }
        cout << "\nTotalizando: " << nav->Jogador.SomaCartas << endl;
        cout << endl;
    }
}

#endif