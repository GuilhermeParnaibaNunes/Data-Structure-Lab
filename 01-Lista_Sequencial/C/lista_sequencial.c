/**
 * @file lista_sequencial.c
 * @brief Implementação das funções da Lista Sequencial.
 * @author Guilherme Parnaíba Nunes
 */

#include <stdio.h>
#include "lista_sequencial.h"

void inicializar_lista(ListaSequencial *l) {
    l->tamanho_atual = 0;
}

bool lista_cheia(ListaSequencial *l) {
    return l->tamanho_atual == MAX;
}

bool lista_vazia(ListaSequencial *l) {
    return l->tamanho_atual == 0;
}

bool inserir(ListaSequencial *l, TipoItem item, int posicao) {
    if (lista_cheia(l) || posicao < 0 || posicao > l->tamanho_atual) {
        return false; // Erro: Lista cheia ou posição inválida
    }

    // Shift para a direita: abre espaço para o novo elemento
    for (int i = l->tamanho_atual; i > posicao; i--) {
        l->itens[i] = l->itens[i - 1];
    }

    l->itens[posicao] = item;
    l->tamanho_atual++;
    return true;
}

bool remover(ListaSequencial *l, int posicao, TipoItem *item_removido) {
    if (lista_vazia(l) || posicao < 0 || posicao >= l->tamanho_atual) {
        return false; // Erro: Lista vazia ou posição inválida
    }

    *item_removido = l->itens[posicao];

    // Shift para a esquerda: tampa o "buraco" deixado pelo elemento removido
    for (int i = posicao; i < l->tamanho_atual - 1; i++) {
        l->itens[i] = l->itens[i + 1];
    }

    l->tamanho_atual--;
    return true;
}

int buscar(ListaSequencial *l, TipoItem item) {
    for (int i = 0; i < l->tamanho_atual; i++) {
        if (ITEM_EQUALS(l->itens[i], item)) { // Usa a macro no lugar do ==
            return i;
        }
    }
    return -1;
}

void imprimir_lista(ListaSequencial *l) {
    printf("\tLista [ ");
    for (int i = 0; i < l->tamanho_atual; i++) {
        IMPRIMIR_ITEM(l->itens[i]); // Usa a macro no lugar do printf("%d")
        if (i < l->tamanho_atual - 1) printf(", ");
    }
    printf(" ] Tamanho: %d/%d\n", l->tamanho_atual, MAX);
}