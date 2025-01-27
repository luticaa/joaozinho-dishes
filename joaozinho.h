/*UEL - UNIVERDIDADE ESTADUAL DE LONDRINA - ESTRUTURA DE DADOS 
Este código tem como objetivo criar uma lista de 300 mil pratos para demonstrar
para o Joaozinho que o quickSort é muito melhor opção ao BubbleSort
LUCAS ANTONIO CUNHA RODRIGUES DA SILVA - 25/01/2025*/ 
#define joaozinho_h //definição arquivo joaozinho
#include<iomanip>//diretriz pré-processamento #include biblioteca manipulação fluxo saida
#include "prato.h"//diretriz pré-processamento #include inclindo arquivo com nosso ADT
#include<vector>//diretriz pré-processamento #include biblioteca vector
#include <cmath>//diretriz pré-processamento #include biblioteca math
#include <ctime>//diretriz pré-processamento #include biblioteca para hora/horario
#include<random>//diretriz pré-processamento #include biblioteca random
#include<unordered_set>/*diretriz pré-processamento #include unordered set para
facilitar manipular as duplicatas na geração de numero aleatorio*/


#define sizeA 300000//size recorrente no codigo os 300k pratos
#define sizeB 1000// size para segundo tamanho que é para os tempos de preparo

class OrdenacaoJoaozinho{//declaração classe  Ordenacao

    public: //membros dados public
    
        void const printData();//função impressão
        vector<int> const randomPie(int n, int q = sizeA, int b = 0);//função gera numeros aleatorios
        void createPriorities();//cria prioridades
        void createCookTime();//cria tempo de preparo
        vector<Prato> getConteiner();//aqui retornamos o conteiner atual da classe
        void createDishesNames();//cria os nomes dos pratos baseado no nosso menu
        void bubbleSort();//função ordenação bubbleSort
        void quickSort(vector<Prato>*lista, int n);//função ordenação QuickSort
        void quickSortOrdena(vector<Prato>*lista, int esq, int dir);//função Ordenação QuickSort
        void quickSortParticao(vector<Prato>*lista, int esq, int dir, int&i,int&j);//Função Ordenação QuickSort
        
        OrdenacaoJoaozinho(){//construtor padrão-classe
        conteiner.resize(sizeA,Prato());//redimensiona nosso vetor
        menu = {//menu para confecção dos pratos contei 69 palavras que formam um 
        //arranjo de 314364 mais que o total que precisamos pra nao repetir.
        "BITTERSWEET_MEAT", "CHICKEN_WITH_CURRY", "FRIED_EGGS", "PASTA", "ONION", 
        "SMASHED_POTATOS", "ROASTED_CHEESE", "TENDERLOIN", "SCRAMBLED_EGGS", "FRENCH_FRIES","FISH",
        "BANANA","SPICY_TOMATOE","SAUSAGE","PIZZA","PARMA_HAM","PORCH","ESPINACH","RIBS","SPAGHETTI",
        "FRIED_CHICKEN","LETTUCE","SOY_SAUCE","PEPPER","CORN","BACON","FRESH_WINE","BREAD",
        "CHICKEN_BREAST","PEACH'S_JAM","SALMON","RUMP_STEAK","TEMPERED_FROG","COOKED_FISH","APPLE",
        "GRAPE", "ORANGE", "PEAR", "PEACH", "PLUM", "CHERRY", "KIWI", "MANGO","PINEAPPLE",
        "STRAWBERRY", "BLUEBERRY", "RASPBERRY", "WATERMELON", "CANTALOUPE", "DRAGONFRUIT", "DURIAN",
        "JACKFRUIT", "LYCHEE", "PERSIMMON", "CARROT", "GARLIC", "BROCCOLI", "CAULIFLOWER", "SPINACH", "QUINOA", 
        "TOFU", "BREAD", "BEEF", "SHRIMP", "OCTOPUS", "VENISON", "TRUFFLE", "SAFFRON","SUGAR_FLOUR"
        };

    }

    private: vector<Prato>conteiner;//membro de dados privado nossa lista 
    private: vector<string> menu;//membro de dados privado menu pratos

};
vector<Prato> OrdenacaoJoaozinho::getConteiner(){//função retorna estrutura (lista)
    return conteiner;
}
void const OrdenacaoJoaozinho::printData(){//função impressao da lista vigente
    int ask;//resultado do cin que será validado
    int total = 0;//variavel acumuladora 
    cout<<"Digite quantas linhas deseja observar, dado o tamanho do dataset:";
    //mensagem para leitura do total de linhas a serem impressas
    
    while (true){//validação entrada
        cin>>ask;//recebe leitura
        if (cin.fail() || ask < 1 || ask > sizeA) {
            //se houver erro ou estiver fora da faixa
            cout << "Erro: entrada invalida detectada!" << endl;
            //mensagem para usuario do erro encontrado
            cin.clear();//limpa buffer entrada
            cin.ignore(100, '\n');  //ignora os proximos 100 caracteres ou ate um /n
        } else {
            cout << "Voce digitou: " << ask << endl;// entrada valida quebra loop
            break;
            }   
        }
    for(Prato x : conteiner){// loop impressao
    //configurações de impressao e cout
        cout<<setw(6)<<setfill('0')<<x.priority<<"***"<<setw(3)<<setfill('0')<<x.tempoPreparo<<"***"<<setw(6)<<setfill('0')<<x.nomePrato<<endl;
        total++;
        if(total >= ask) break;
    }
}
vector<int>const OrdenacaoJoaozinho::randomPie(const int n, int q,int b){
//função gera aleatoriedade
vector<int>aleatoryList;//lista armazena indices/subscritos aleatorios
unordered_set<int> generatedNumbers;//unordered set para ajudar com duplicatas
random_device rd;  //esse codigo peguei da internet para o contador de tempo
mt19937 gen(rd());  // Gerador Mersenne Twister (32 bits)
uniform_int_distribution<int> dist(0, q);  // Intervalo de 0 a 1 milhão
if (!b){
    while(static_cast<int>(aleatoryList.size()) < n){
        //enquanto nao forem iguais...
        int number = dist(gen);//vai gerando novo numero e se for unico adiciona na lista
        if (generatedNumbers.insert(number).second) aleatoryList.push_back(number);
            }
        } 
else 
    {//aqui tem uma opção para gerar nao exclusivos no caso do tempo de preparo...
    //o default value da assinatura definirá qual ação é executada
        while(static_cast<int>(aleatoryList.size()) < n){
        int number = dist(gen);
        aleatoryList.push_back(number);
        }

    }
    return aleatoryList;//retorna lista de aleatorios para uso no codigo
}
void OrdenacaoJoaozinho::createPriorities(){//função cria prioridades
    vector<int> myList = randomPie(sizeA);//aciona função aleatoria salvando seu retorno
    for (size_t i = 0; i< conteiner.size();i++){
        conteiner[i].priority = myList [i];//vai preenchendo na lista da classe
    }
}
void OrdenacaoJoaozinho::quickSort(vector<Prato>*lista, int n){
    //função quicksort estudada em sala de aula
    quickSortOrdena(lista,0,n-1);
    for (int g = 0; g<sizeA; g++){
        conteiner[g] = (*lista)[g];
    }
}
void OrdenacaoJoaozinho::quickSortOrdena(vector<Prato>*lista, int esq, int dir){
    int i,j;
    //função quicksort estudada em sala de aula
    quickSortParticao(lista,esq,dir,i,j);
    if(esq<j)quickSortOrdena(lista,esq,j);
    if(i<dir)quickSortOrdena(lista,i,dir);
}
void OrdenacaoJoaozinho::quickSortParticao(vector<Prato>*lista, int esq, int dir, int&i,int&j){
    //função quicksort estudada em sala de aula
    Prato pivo, aux;
    i = esq;
    j = dir;
    pivo = (*lista)[(i+j)/2];
    do{
        while(pivo.priority < (*lista)[i].priority){
            (i)++;
        } 
        while(pivo.priority > (*lista)[j].priority){
                (j)--;
            }
        if(i <= j){
            aux = (*lista)[i];
            (*lista)[i] = (*lista)[j];
            (*lista)[j] = aux;
            (i)++;
            (j)--;
        }

    }while(i <= j);
    }
    

void OrdenacaoJoaozinho::bubbleSort(){
    //função bubbleSort estudada em sala de aula
    int temp;
    for(int a = 0; a < sizeA-1;a++){
        for(int b = 1; b < sizeA-a;b++){
            if(conteiner[b].priority > conteiner[b-1].priority){
                temp = conteiner[b-1].priority;
                conteiner[b-1].priority = conteiner[b].priority;
                conteiner[b].priority = temp;

            }
        }
    }
}
 void OrdenacaoJoaozinho::createCookTime(){//função cria os tempos de preparo
    vector<int>myList3 = randomPie(sizeB,sizeB);
    //notar aqui o default value sendo usado pois como o tempo vai apenas até 1000
    int acumuladora =0;//variavel acumuladora
    int k =0;//
    for (size_t j = 0; j<myList3.size();j++){
        acumuladora = (j+1)*300;//crio em lotes de 300 pois 1000*300 = 300kilo
        for (;k<acumuladora;k++){
            conteiner[k].tempoPreparo = myList3[j];
        }
    }
    //embaralhando apos criação pois ficou ali tudo ordenado antes
    vector<int>myList5 = randomPie(sizeA);
    //cria lista aleatoria dessa vez tamanho total
    for (size_t a = 0; a < conteiner.size();a++){
        //variavel temporaria para troca
        int temp = conteiner[a].tempoPreparo; 
        conteiner[a].tempoPreparo = conteiner[myList5[a]].tempoPreparo;
        //efetua embaralhamento
        conteiner[myList5[a]].tempoPreparo = temp;
    }
 }

 void OrdenacaoJoaozinho::createDishesNames(){//função cria nome dos pratos
    string nomeFicticio;//string nome 
    int control = 0;//variavel de controle
    int size = static_cast<int>(menu.size());//conversao do tipo tamanho do vetor
    vector<string>nomesPratos;//vetor com os nomes gerados
    for(int a = 0; a < size;a++){
        if (control >= sizeA) break;//deu 300k nomes para
        for(int b = 0; b<size;b++){
    //os fors aninhados garantem a geração das combinações puras (sem repetição)
            if (b == a) continue;
            if (control >= sizeA) break;//deu 300k nomes para
            for(int c = 0; c <size;c++){
                if (c == a || c == b) continue;
                if (control >= sizeA) break;//deu 300k nomes para
                nomeFicticio = menu[a]+"-"+menu[b]+"-"+menu[c];
                //captura um a um cada nome possivel para formar uma combinação
                nomesPratos.push_back(nomeFicticio);
            }
            nomeFicticio = "";//reseta para uma novo grupo
            control++;//incrementa variavel acumuladora
        }
    }
    for (int i=0;i<sizeA;i++){//loop para escrever o que foi obtido na ADT
        conteiner[i].nomePrato = nomesPratos[i];
        }
    //embaralha para nao ficar ordenado, poderia criar um função embaralhar mas 
    //teria que criar um dado para os pratos como foram apenas duas vezes usada
    //entao deixei aqui mas poderia ser feito.
    //o processo aqui é o mesmo das linhas 180-183
    vector<int>myList8 = randomPie(sizeA);
    for (size_t a = 0; a < conteiner.size();a++){
        
        string temp = conteiner[a].nomePrato; 
        conteiner[a].nomePrato = conteiner[myList8[a]].nomePrato;
        conteiner[myList8[a]].nomePrato = temp;
    }
    }
    
