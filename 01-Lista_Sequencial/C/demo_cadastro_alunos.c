/**
 * @file demo_cadastro_alunos.c
 * @brief Aplicação Prática: CRUD de Alunos usando Lista Sequencial.
 */

#include <stdio.h>
#include <string.h>

// 1. Definimos nosso domínio de negócio ANTES de importar a lista
typedef struct {
    int matricula;
    char nome[50];
} Aluno;

// 2. Ensina a lista genérica a lidar com a Struct Aluno
// Compara alunos pela matrícula
#define ITEM_EQUALS(a, b) ((a).matricula == (b).matricula) 
// Formata a impressão do aluno
#define IMPRIMIR_ITEM(a) printf("\t{Mat: %d, Nome: %s}\n", (a).matricula, (a).nome)

// 3. Sobrescrevemos o TipoItem genérico para usar a nossa struct
#define TIPO_ITEM_DEFINIDO
typedef Aluno TipoItem;

// 4. Importamos a estrutura pura (Unity Build para injetar o tipo)
#include "lista_sequencial.c"

// Função auxiliar para imprimir um aluno
void imprimir_aluno(Aluno a) {
    printf("Matricula: %d | Nome: %s\n", a.matricula, a.nome);
}

// Sobrecarga visual do imprimir_lista genérico para formato de relatório
void relatorio_turma(ListaSequencial *l) {
    printf("\n--- DIARIO DE CLASSE (%d/%d alunos) ---\n", l->tamanho_atual, MAX);
    for (int i = 0; i < l->tamanho_atual; i++) {
        printf("\t[%d] ", i);
        imprimir_aluno(l->itens[i]);
    }
    printf("--------------------------------------\n");
}

int main() {
    ListaSequencial turma;
    inicializar_lista(&turma);

    // CREATE
    Aluno a1 = {202601, "Guilherme Parnaiba"};
    Aluno a2 = {202602, "Ada Lovelace"};
    Aluno a3 = {202603, "Alan Turing"};

    inserir(&turma, a1, 0);
    inserir(&turma, a2, 1);
    inserir(&turma, a3, 1); // Alan Turing entra no meio, Ada sofre shift

    // READ
    relatorio_turma(&turma);

    // DELETE
    Aluno removido;
    if (remover(&turma, 1, &removido)) {
        printf("\n\tAluno transferido: %s (Mat: %d)\n", removido.nome, removido.matricula);
    }

    relatorio_turma(&turma);

    return 0;
}