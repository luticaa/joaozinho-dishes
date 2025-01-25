/*UEL - UNIVERDIDADE ESTADUAL DE LONDRINA - ESTRUTURA DE DADOS 
Este código tem como objetivo criar uma lista de 300 mil pratos para demonstrar
para o Joaozinho que o quickSort é muito melhor opção ao BubbleSort
LUCAS ANTONIO CUNHA RODRIGUES DA SILVA - 25/01/2025*/ 
#define prato_h // definição arquivo prato.h
#include <iostream>//diretriz pré-processamento fluxo entrada e saída
#include <string> //diretriz pré-processamento biblioteca string
using namespace std;//namespace std referenciado para escrita do código

struct Prato{//estrutura prato
    int priority;//dado prioridade
    int tempoPreparo;//dadp tempo preparo
    string nomePrato;//string nome do prato
};