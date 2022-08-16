# Double_open_Hash
O objetivo do problema é implementar uma Hash dupla aberta que contenha as funções de insert, search e remove, assim como contando as colisões que ocorrerem.       
# Estrutura
Temos uma estrutura baseada de [HashTable](https://github.com/mpiress/HashTable), porém diferentemente do exemplo dado, ao ocorrer uma colisão existe um segundo algoritmo para gerar uma nova chave, caso ambas estejam sendo utilizadas, ele percorre a Hash até achar uma chave vazia, caso a Hash esteja completa deve-se duplicar o tamanho atual e setar o próximo primo como tamanho da Hash.
# Logica

O programa possui alguns métodos importantes: *criaHash()*, *insertHash()*, *printHash()*, *searchHash()* e *removeHash()*.
1) criaHash(int tam):      
Este método é responsável por inicializar uma tabela de objetos Entry, setando atributos como *t->quantidade* e *t->collisions* como 0, dizendo que a tabela está vazia, e setando tamanho da tabela como o próximo primo do dobro de um número informado, assim como alocando essa quantidade de memória para a tabela.

2) insertHash(Table* t, int valor):      
O método percorre a lista de inteiros passada calculando uma chave (*valor % t->tamanho*) para o valor informado, caso a tabela na posição desta chave esteja preenchida, será realizado uma segunda operação de cálculo ((valor\*index+t->tamanho)%t->tamanho), caso este valor também esteja preenchido, a tabela será percorrida até achar um valor nulo, e a cada ciclo realizado há uma colisão, portanto adiciona-se 1 ao atributo *t->collisions* para que seja possível exibir a quantidade de colisões que houveram. Caso a tabela esteja cheia, será feito um re-hash para atualizar o valor do tamanho e inserir mais valores.

3) printHash(Table* t):       
Printa o tamanho da Hash, percorre a Hash recebida printando os objetos(chave e valor) aonde existe valor, e no final printar o número de colisões ocorridas.

4) searchHash(Table* t, int valor):       
Calcula uma chave (*valor % t->tamanho*) para o valor recebido e verifica se a tabela nessa posição possui valor igual ao recebido, se não realiza o mesmo calculo de *insertHash()* e verifica novamente, se não encontrar percorre a Hash até encontrá-lo ou caso faça dois ciclos retorna um valor nulo.

6) removeHash(Table* t, int valor):       
Realiza uma busca semelhante à *buscaHash()* e caso encontre remove o número da lista de inteiros do objeto aonde a chave bateu, assim como diminui o número de colisões que foram necessárias para encontrar esse valor.

Obs.:      
- O programa não aceita entrada de usuários, ele utiliza um array estático de inteiros implementado, caso seja necessário deve-se criar um input para o array.

# Exemplo de execução
O main do programa está implementado para inserir o vetor na Hash, printar a Hash após iserção, buscar um número que existe, remover um número, printar após remoção, remover um número não existente, inserir uma quantidade de números que ultrapassa o limite da Hash, printar a rash adaptada a uma nova quantidade.      
Vetor:

> {1378, 3012, 600, 4700, 918, 175, 2051, 3653, 4558, 1210, 1468, 2724, 1055, 2143, 1136, 546, 3350, 1610, 3412, 1096}

Novos valores:

> {4558, 4559, 4560, 4561, 4562, 4551}

Execução:
</p>
<p align="center">
	<img src="imgs/exec.jpg"/> 
</p>    
<p align="center">
	<img src="imgs/exec2.jpg"/> 
</p>   

# Conclusão

Ao compararmos a estrutura a uma semelhante porém fechada, notamos que existem mais colisões na hora de inserção, porém, a busca é mais rápida já que sabemos exatamente o caminho que devemos percorrer para encontrar o valor, portanto o custo é linear. Ou seja, perde-se na inserção porém ganha-se na busca.

# Compilação e Execução

O programa possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
