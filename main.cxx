/*UEL - UNIVERDIDADE ESTADUAL DE LONDRINA - ESTRUTURA DE DADOS 
Este código tem como objetivo criar uma lista de 300 mil pratos para demonstrar
para o Joaozinho que o quickSort é muito melhor opção ao BubbleSort
LUCAS ANTONIO CUNHA RODRIGUES DA SILVA - 25/01/2025*/ 
#include "joaozinho.h"//diretriz pré-processamento inclusao do arquivo joaozinho.h com a classe principal
#include<chrono>//diretriz - pré-processamento biblioteca contagem tempo 
int escolha(){//função para capturar a quantidade de linhas a serem visualizadas
    int escolhe;//variavel para armazenar escolha
    do{//validação de entrada
        cout << "De qual algoritmo deseja testar o desempenho? 1 = BUBBLE, 2 = QUICKSORT" << endl;
        cin>>escolhe;
    }while(escolhe != 1 && escolhe != 2);
    return escolhe;//retorna escolha 
}

int main(){//funçaõ main
    OrdenacaoJoaozinho dados; //instanciação da classe
    dados.createPriorities();//criaçaõ das prioridades
    dados.createCookTime();//criação dos tempos de preparo
    dados.createDishesNames();//criação dos nomes dos pratos
    dados.printData();//imprime lista desordenada
    if (escolha() == 1){//verifica escolha se BUBBLE
        clock_t pressStart = clock();//inicia contagem
        dados.bubbleSort();//ordena formularios
        clock_t pressEnd = clock();//interrompe contagem pos ordenação atencção esta demandando 18 minutos o processo
        double tempo = double(((pressEnd-pressStart)/CLOCKS_PER_SEC)/60);//variavel para armazenar e converter 
        cout<<"O tempo demandado pelo BUBBLESORT foi "<<tempo<<" minutos"<<endl;
        dados.printData();//apos informar o tempo total realiza a impressao dos dados
        // ⚠️⚠️⚠️ o algoritmo demora 18 minutos para ordenar dado as 90bilhoes de movimentações (300k)²
    } else {
        auto pressStart = chrono::high_resolution_clock::now();  // Início da medição;
        vector<Prato>copia = dados.getConteiner();//copia para criação ponteiro
        vector<Prato> *ptr = new vector<Prato>(copia);//cria ponteiro para quick memoria alocada no heap
        dados.quickSort(ptr,sizeA);//chama algoritmo ordenação
        auto pressEnd = chrono::high_resolution_clock::now();  // Fim da medição
        chrono::duration<double,::milli> tempo = pressEnd - pressStart;//contabiliza o tempo
        cout<<fixed<<setprecision(4);//configurações aderentes de saida
        cout<<"O tempo demandado pelo QUICKSORT  foi "<<tempo.count()<<" milisegundos"<<endl;
        //mensagem para usuario
        dados.printData();//mostra dados
        auto pressStart2 = chrono::high_resolution_clock::now();  // Início da medição;
        dados.quickSort(ptr,sizeA);
        auto pressEnd2 = chrono::high_resolution_clock::now(); 
        chrono::duration<double,::milli> tempo2 = pressEnd2 - pressStart2;//contabiliza o tempo // Fim da medição
        cout<<"O tempo demandado pelo QUICKSORT JA ORDENADO foi "<<tempo2.count()<<" milisegundos"<<endl;
        delete ptr;
        ptr = nullptr;
    } 

}
