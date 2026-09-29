/**
 * @file lista_sequencial.h
 * @brief Definição da estrutura e protótipos da Lista Sequencial.
 * @author Guilherme Parnaíba Nunes
 */
 
#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include <stdbool.h>

#define MAX 100 // Capacidade máxima da lista

// Guard que permite ao consumidor injetar seu próprio TipoItem
// antes de incluir este header (ver demo_cadastro_alunos.c)
#ifndef TIPO_ITEM_DEFINIDO
#define TIPO_ITEM_DEFINIDO
typedef int TipoItem; 
#endif

// Macros genéricas para comparação e impressão
#ifndef ITEM_EQUALS
#define ITEM_EQUALS(a, b) ((a) == (b))
#endif

#ifndef IMPRIMIR_ITEM
#define IMPRIMIR_ITEM(a) printf("%d", (a))
#endif

// ... (resto do arquivo continua igual)

/**
 * @brief Estrutura representativa de uma Lista Sequencial.
 */
typedef struct {
    TipoItem itens[MAX];
    int tamanho_atual;
} ListaSequencial;

/**
 * @brief Inicializa a lista definindo o tamanho atual como zero.
 * @param l Ponteiro para a lista a ser inicializada.
 */
void inicializar_lista(ListaSequencial *l);

/**
 * @brief Verifica se a lista está cheia.
 * @param l Ponteiro para a lista.
 * @return true se estiver cheia, false caso contrário.
 */
bool lista_cheia(ListaSequencial *l);

/**
 * @brief Verifica se a lista está vazia.
 * @param l Ponteiro para a lista.
 * @return true se estiver vazia, false caso contrário.
 */
bool lista_vazia(ListaSequencial *l);

/**
 * @brief Insere um elemento em uma posição específica da lista.
 * @param l Ponteiro para a lista.
 * @param item Valor a ser inserido.
 * @param posicao Índice onde o elemento será inserido (0 a tamanho_atual).
 * @return true se a inserção for bem-sucedida, false se a posição for inválida ou a lista estiver cheia.
 */
bool inserir(ListaSequencial *l, TipoItem item, int posicao);

/**
 * @brief Remove um elemento de uma posição específica da lista.
 * @param l Ponteiro para a lista.
 * @param posicao Índice do elemento a ser removido.
 * @param item_removido Ponteiro para armazenar o valor que foi removido.
 * @return true se a remoção for bem-sucedida, false se a posição for inválida ou a lista estiver vazia.
 */
bool remover(ListaSequencial *l, int posicao, TipoItem *item_removido);

/**
 * @brief Busca a primeira ocorrência de um item na lista.
 * @param l Ponteiro para a lista.
 * @param item Valor a ser buscado.
 * @return O índice do elemento se encontrado, ou -1 se não existir na lista.
 */
int buscar(ListaSequencial *l, TipoItem item);

/**
 * @brief Imprime os elementos da lista no terminal.
 * @param l Ponteiro para a lista.
 */
void imprimir_lista(ListaSequencial *l);

#endif // LISTA_SEQUENCIAL_H