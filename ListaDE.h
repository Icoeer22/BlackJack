#ifndef LISTA_LDE_H
#define LISTA_LDE_H
#include <iostream>

using namespace std;


struct TElemento{
    int num;
    TElemento * proximo;
    TElemento * anterior;
};

struct TLista{
    TElemento * inicio;
    TElemento * fim;
};

void Inicializar_Lista_LDE(TLista &l){
    l.inicio = l.fim = nullptr;
}

void Inserir_Inicio_LDE(TLista &l, int num){
    TElemento * novo = new TElemento;
    novo ->num = num;
    novo->anterior = novo->proximo = nullptr;
    if (l.inicio == nullptr){
        l.inicio = novo;
        l.fim = novo;
    }
    else{
        TElemento * nav = l.inicio;
        novo->proximo = l.inicio;
        l.inicio = novo;
        nav-> anterior = novo;
    }
}

void Inserir_Fim_LDE(TLista &l, int num){
  if (l.inicio == nullptr){
    Inserir_Inicio_LDE(l,num);
  }
  else{
    TElemento * novo = new TElemento;
    novo ->num = num;
    novo->anterior = novo->proximo = nullptr;
    TElemento * nav = l.fim;
    nav->proximo = novo;
    novo-> anterior = nav;
    l.fim = novo;
  }
}


void Inserir_Posicao_LDE(TLista &l, int num, int pos){
  TElemento * nav = l.inicio;
  int cont = 0;
  while (nav->proximo != nullptr){
    nav = nav->proximo;
    cont = cont+1;
  }
  if(pos-1 == cont){
    Inserir_Fim_LDE(l,num);
  }
  else if (l.inicio == nullptr || pos == 0){
   Inserir_Inicio_LDE(l,num);
 } 
  else if(pos-1 < 0 || pos-1 > cont){
    cout<< "Posição Inválida" << endl;
  }
 else{
   TElemento * novo = new TElemento;
   novo ->num = num;
   novo->anterior = novo->proximo = nullptr;
   TElemento * nav = l.inicio;
   for(int i = 0; i != pos-1; i++){
     nav=nav->proximo;
   }
   nav->proximo->anterior = novo;
   novo->proximo = nav->proximo;
   novo->anterior = nav;
   nav->proximo = novo;
 }
}

void Remover_Inicio_LDE(TLista &l){
  TElemento * Apagar = l.inicio;
  l.inicio = Apagar->proximo;
  Apagar->proximo->anterior = nullptr;
  delete Apagar;
}

void Remover_Fim_LDE(TLista &l){
  TElemento * Apagar = l.fim;
  l.fim = Apagar->anterior;
  Apagar->anterior->proximo = nullptr;
  delete Apagar;
}

void Remover_Posicao_LDE(TLista &l,int pos){
  TElemento * nav = l.inicio;
  int cont = 0;
  while (nav->proximo != nullptr){
    nav = nav->proximo;
    cont = cont+1;
  }
  if (pos-1 == cont){
    Remover_Fim_LDE(l);
  }
  else if (pos-1 == 0){
    Remover_Inicio_LDE(l);
  }
  
  else if((pos-1) < 0 || (pos-1) > cont){
    cout << "Index invalido";
  }
  else{
     TElemento * nav = l.inicio;
     for(int i = 0; i != pos-1; i++){
     nav=nav->proximo;
   }
    TElemento * Apagar  = nav->proximo;
    nav->proximo = Apagar->proximo;
    Apagar->proximo->anterior = nav;
    delete Apagar;
  }
  
}
#endif 