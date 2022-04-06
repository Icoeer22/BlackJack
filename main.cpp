// Alunos: Bernardo Henrique Gaya, Guilherme Victor Butzke e Pablo Augusto de Quadros
#include <iostream>
#include "carta.h"
using namespace std;

int main(){
    TListaCarta Baralho_Mesa;
    Baralho_Mesa = Criar_Baralho();
    Embaralhar(Baralho_Mesa);
    Imprimir_Lista_LCartas(Baralho_Mesa);
}