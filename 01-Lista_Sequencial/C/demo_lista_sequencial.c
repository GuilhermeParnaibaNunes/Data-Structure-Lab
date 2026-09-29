/**
 * @file demo_lista_sequencial.c
 * @brief Demonstração prática do uso da Lista Sequencial.
 */

#include <stdio.h>
#include "lista_sequencial.h"

int main() {
    ListaSequencial minha_lista;
    inicializar_lista(&minha_lista);
    TipoItem removido;

    printf("\n--- Iniciando testes da Lista Sequencial ---\n");

    inserir(&minha_lista, 10, 0); // [10]
    inserir(&minha_lista, 30, 1); // [10, 30]
    inserir(&minha_lista, 20, 1); // [10, 20, 30] (Inserção no meio, forçando shift)
    
    imprimir_lista(&minha_lista);

    int pos = buscar(&minha_lista, 20);
    if (pos != -1) {
        printf("\tItem 20 encontrado no indice: %d\n", pos);
    }

    printf("\n\tRemovendo o item do indice 0...\n");
    if (remover(&minha_lista, 0, &removido)) {
        printf("\tItem removido com sucesso: %d\n\n", removido);
    }

    imprimir_lista(&minha_lista);

    return 0;
}