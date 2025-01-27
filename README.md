# joaozinho-dishes
A static test struct for use with sorting algorithms (bubbleSort and QuickSort), measures  time difference between these 2 options.
#README BUBBLE AND QUICK - JOAOZINHO#
**O projeto foi reaalizado através de uma classe e seu membro de dados privado,
nao era necessário mas por aplicação é bom pra acostumar. 
Nos criamos funções membro separadas para cada ação(criar prioridade, criar nome,
criar tempo de preparo) e também foi necessário ao final de (QuickSort) inserir 
mais uma varredura para escrever no membro da classe pois o algoritmo precisava de
um ponteiro para funcionar e não é possível retornar uma referencia para um membro
de dados privado sem comprometer a segurança da classe (o array poderia ser apagado)
por terceiros fora da classe. Isso fez com que o tempo saisse de 0.43 milisegundos
para 0.64 aproximadamente.
O bubble levou 18 minutos para concluir a ordenação.
No pdf dizia de fazer o desempate caso a prioridade fosse igual mas a prioridade é
unica e nunca será igual entao deixei desta forma.
As escolhas sobre os pivos em QuickSort São de extrema importancia no desempenho 
do algoritmo pois muda a complexidade das iterações com a mediana central se comporta
nlogn e com a seleção aleatoria também. Enquanto nas extremidades configura n² pois
seria o pior caso nas extremidades e com ele já ordenado(ascendente ou decrescente);
Após correções no programa (ponteiro mal alocado causando memory leak na main e subs
crito incorreto no bubble) obtivemos:
bubble (media 11 a 14 minutos);
quick embaralhado (368 milisegundos);
quick ordenado (108 milisegundos);

Att,
Lucas Silva.
