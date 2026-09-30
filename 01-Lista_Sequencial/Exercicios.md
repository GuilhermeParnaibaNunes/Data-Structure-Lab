# Exercícios de Fixação: Lista Sequencial

Estes exercícios testam a compreensão sobre a mecânica de memória, complexidade assintótica e limitações práticas da Lista Sequencial. Tente resolvê-los antes de consultar o gabarito.

## Questões

**Questão 1: Análise de Custo e Movimentação**
Imagine uma Lista Sequencial com capacidade máxima (`MAX`) para 10.000 itens, contendo atualmente 5.000 elementos cadastrados. 
1. Qual será a complexidade de tempo (Notação Big-O) para acessar o elemento na posição 4.999?
2. Qual será a complexidade para inserir um novo elemento na posição `0`? Quantas cópias de elementos na memória o processador precisará realizar?

**Questão 2: Bug Hunting (O Problema do Shift)**
Um aluno tentou implementar a operação de inserção no meio da lista, mas cometeu um erro lógico no laço de repetição (*shift* para a direita). Veja o trecho abaixo:

```c
// Shift para a direita (abre espaço)
for (int i = posicao; i < lista->tamanho_atual; i++) {
    lista->itens[i + 1] = lista->itens[i];
}
lista->itens[posicao] = novo_valor;

```

Explique qual é o defeito letal desse trecho de código e como ele corrompe os dados da lista.

**Questão 3: Decisão de Arquitetura (Trade-offs)**
No nosso `demo_cadastro_alunos.c`, assuma que a secretaria da universidade decidiu manter a lista de alunos **sempre ordenada por ordem alfabética**. Todos os dias, dezenas de alunos novos são matriculados e dezenas de transferências (remoções) ocorrem, cujos nomes caem no meio da ordem alfabética.
Por que a Lista Sequencial seria uma má escolha de arquitetura de software para este cenário específico?

**Questão 4: Desafio de Lógica (Inversão *in-place*)**
Como você implementaria uma função `inverter_lista(ListaSequencial *l)` que inverte a ordem de todos os elementos dentro da própria lista, sem utilizar um segundo vetor auxiliar? Qual seria a complexidade de tempo desta operação?

---











## Gabarito

**Resolução da Questão 1**

1. O acesso custa $O(1)$ (Melhor/Pior caso). Como a lista usa um array contíguo sob o capô, o endereço de memória é calculado matematicamente de forma instantânea (Endereço Base + (Índice * Tamanho do Tipo)), não importando se é o índice 0 ou 4.999.
2. A inserção na posição `0` (início da lista) custa $O(n)$ no pior caso. O processador precisará realizar exatas **5.000 cópias**, "empurrando" todos os elementos uma posição para a direita para conseguir abrir o buraco no índice 0 sem sobrescrever ninguém.

**Resolução da Questão 2**
O defeito é que o laço de repetição percorre a lista da esquerda para a direita. Ao fazer `itens[posicao + 1] = itens[posicao]`, o aluno sobrescreve e destrói o dado que estava na posição seguinte antes de tê-lo copiado para a frente. O resultado é que o primeiro valor deslocado vai se propagar por toda a lista, apagando todos os outros dados (uma reação em cadeia de sobrescrita).
*A correção:* O *shift* para a direita deve sempre ocorrer de trás para frente (do `tamanho_atual` descendo até a `posicao`).

**Resolução da Questão 3**
Uma lista mantida sempre ordenada exige que as inserções e remoções ocorram, em média, no meio do vetor. Como a Lista Sequencial tem complexidade $O(n)$ para essas operações devido à necessidade constante de deslocamento (*shift*) de memória, o sistema perderia muita performance com o alto volume diário de entradas e saídas. (Estruturas baseadas em nós encadeados ou árvores seriam soluções mais escaláveis aqui).

**Resolução da Questão 4**
A inversão pode ser feita utilizando a técnica de *Dois Ponteiros* (um no início e um no fim), trocando os elementos e convergindo para o centro:

```c
void inverter_lista(ListaSequencial *l) {
    int inicio = 0;
    int fim = l->tamanho_atual - 1;
    TipoItem temp;
    
    while (inicio < fim) {
        // Realiza o swap (troca)
        temp = l->itens[inicio];
        l->itens[inicio] = l->itens[fim];
        l->itens[fim] = temp;
        
        inicio++;
        fim--;
    }
}

```

*Complexidade:* O tempo é $O(n)$, pois o laço executa exatamente `n/2` vezes, tocando todos os elementos da lista. O espaço adicional é $O(1)$, pois usa apenas a variável `temp`.
