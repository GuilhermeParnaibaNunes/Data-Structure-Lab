🇧🇷 Português | [🇺🇸 English](./Apostila.en.md)

# Lista Sequencial (Array-based List)

## 1. Motivação
A Lista Sequencial é o ponto de partida no estudo de estruturas de dados. Ela existe para resolver o problema mais fundamental do armazenamento: guardar uma coleção de itens de forma que possamos acessá-los instantaneamente se soubermos a sua posição. Por ser mapeada diretamente nos blocos físicos da memória, é a estrutura que o processador lida com maior eficiência natural.

## 2. Definição
Uma Lista Sequencial é uma estrutura de dados linear onde os elementos são armazenados em **posições contíguas de memória**. Isso significa que os dados ficam "um ao lado do outro" fisicamente na memória RAM do computador. 

Por usar vetores (arrays) como base, ela possui um tamanho máximo pré-definido (capacidade) e um contador interno que rastreia quantos elementos estão de fato armazenados no momento (tamanho atual).

## 3. Representação Visual
```text
Índices:       0       1       2       3       4
           +-------+-------+-------+-------+-------+
Memória:   |  10   |  30   |  20   | LIXO  | LIXO  |
           +-------+-------+-------+-------+-------+
           
Tamanho Atual: 3
Capacidade Máxima: 5

```

## 4. Complexidade de Tempo

| Operação | Melhor Caso | Pior Caso (Notação Big-O) | Justificativa |
| --- | --- | --- | --- |
| **Acesso (por índice)** | O(1) | O(1) | Cálculo matemático direto usando o endereço base + índice. |
| **Busca (por valor)** | O(1) | O(n) | Requer varredura linear. O(1) se for o primeiro, O(n) se for o último ou não existir. |
| **Inserção (no fim)** | O(1) | O(1) | Basta adicionar na próxima posição livre. |
| **Inserção (no início/meio)** | O(n) | O(n) | Exige realizar o *shift* (deslocamento) de todos os elementos posteriores para a direita. |
| **Remoção (no fim)** | O(1) | O(1) | Basta decrementar o contador de tamanho. |
| **Remoção (no início/meio)** | O(n) | O(n) | Exige realizar o *shift* (deslocamento) de todos os elementos posteriores para a esquerda. |

## 5. Trade-offs (Vantagens vs. Desvantagens)

### Vantagens

* **Acesso Aleatório:** Ler o elemento na posição `1` ou `1000` leva exatamente o mesmo tempo.
* **Localidade de Referência:** Como os dados estão juntos na memória, a CPU consegue carregar a lista inteira na memória Cache, tornando as iterações extremamente rápidas.
* **Simplicidade:** Fácil implementação e baixo consumo extra de memória (não exige ponteiros adicionais para cada nó).

### Desvantagens

* **Tamanho Fixo:** Exige prever a capacidade máxima. Se a lista encher, é necessário criar um novo vetor maior e copiar tudo (operação custosa). Se alocar espaço demais, ocorre desperdício de memória.
* **Custo de Movimentação:** Inserir ou remover elementos no início ou no meio da lista é ineficiente, pois obriga o processador a empurrar (fazer *shift*) dezenas ou milhares de dados para reorganizar os espaços.

## 6. Pseudocódigo das Principais Operações

**Inserção em uma posição específica:**

```text
funcao inserir(lista, valor, posicao):
    se lista.tamanho_atual == lista.capacidade_maxima:
        retornar ERRO_LISTA_CHEIA
    
    se posicao < 0 ou posicao > lista.tamanho_atual:
        retornar ERRO_POSICAO_INVALIDA
    
    // Shift para a direita (abre espaço)
    para i de lista.tamanho_atual ate posicao (passo -1):
        lista.elementos[i] = lista.elementos[i - 1]
    
    lista.elementos[posicao] = valor
    lista.tamanho_atual = lista.tamanho_atual + 1

```

**Remoção de uma posição específica:**

```text
funcao remover(lista, posicao):
    se lista.tamanho_atual == 0:
        retornar ERRO_LISTA_VAZIA
        
    se posicao < 0 ou posicao >= lista.tamanho_atual:
        retornar ERRO_POSICAO_INVALIDA
        
    valor_removido = lista.elementos[posicao]
    
    // Shift para a esquerda (tampa o buraco)
    para i de posicao ate lista.tamanho_atual - 2 (passo 1):
        lista.elementos[i] = lista.elementos[i + 1]
        
    lista.tamanho_atual = lista.tamanho_atual - 1
    retornar valor_removido

```

## 7. Implementações

* [Implementação em C](./C/)
* [Implementação em Java](./Java/)

## 8. Aplicação Prática

A pasta `C/` contém dois programas de demonstração com propósitos distintos:

- **`demo_lista_sequencial.c`** — valida a estrutura genérica isoladamente,
  testando inserção, remoção e busca com valores inteiros simples.
- **`demo_cadastro_alunos.c`** — a aplicação prática de fato. Simula um
  sistema de diário de classe (CRUD), onde a Lista Sequencial armazena e
  gerencia um vetor de `struct Aluno` (matrícula e nome). Ilustra como a
  abstração genérica da lista serve de motor para regras de negócio reais.

## 9. Exercícios Propostos

Os exercícios de fixação para este tópico estão em [Exercicios.md](./Exercicios.md).

## 10. Referências

* ZIVIANI, N. Projeto de Algoritmos com implementações em Java e C++. São Paulo: CENGAGE Learning, 2012.


* ASCENSIO, A. F.; ARAUJO, G. S. Estrutura de Dados: Algoritmos, Análise da Complexidade e Implementações em Java e C/C++. São Paulo: Pearson, 2010.