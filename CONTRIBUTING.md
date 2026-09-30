# Contribuindo para o Data Structure Lab

Ficamos felizes que você queira contribuir! Este repositório é mantido para auxiliar alunos, e contribuições de outros monitores ou estudantes são muito bem-vindas.

## Padrão de Commits

Utilizamos um padrão baseado no Conventional Commits para manter o histórico organizado. O formato é:
`<tipo>(<escopo>): <descrição>`

**Exemplos:**
* `feat(01-lineares): add doubly linked list impl` (Novas implementações)
* `fix(04-grafos): corrige erro de segmentação na busca em largura` (Correção de bugs)
* `docs(03-arvores): atualiza apostila de árvore balanceada` (Alterações nos arquivos .md)

## Convenção de Nomenclatura
- Documentação e pastas: `Title_Case` (ex: `Apostila.md`, `Lista_Sequencial/`)
- Código C: `snake_case` (ex: `lista_sequencial.c`)
- Código Java: `PascalCase` para classes (ex: `ListaSequencial.java`)

## Checklist de Pull Request (PR)

Antes de enviar seu PR, garanta que sua contribuição atende aos requisitos abaixo:

- [ ] **Compilação:** O código compila via `make` sem *warnings* ou erros (flags padrão: `-Wall -Wextra -fsanitize=address`).
- [ ] **Documentação:** A respectiva "apostila" teórica (`.md`) foi criada ou atualizada.
- [ ] **Prática:** O código inclui a versão genérica da estrutura e um exemplo funcional (`demo`) simulando uma aplicação real.
- [ ] **Consistência:** Os arquivos foram alocados na pasta correta do módulo e seguem o padrão de nomenclatura do projeto.

## Fluxo de Branch por Estrutura

Cada estrutura do checklist é desenvolvida em uma branch própria, seguindo o
padrão `feat/<numero>-<nome-da-estrutura>` (ex: `feat/01-lista-sequencial`).

1. Criar a branch a partir de `main`:
```bash
   git checkout -b feat/NN-nome-da-estrutura
```
2. Desenvolver o ciclo completo de commits da estrutura (apostila, C, Java,
   exercícios, traduções EN — ver padrão de commits acima).
3. Mergear em `main` e limpar a branch:
```bash
   git checkout main
   git merge feat/NN-nome-da-estrutura
   git branch -d feat/NN-nome-da-estrutura
   git push origin --delete feat/NN-nome-da-estrutura  # se houver push remoto
```

`git branch -d` (minúsculo) é intencional — ele só permite apagar branches já
totalmente mergeadas em `main`, funcionando como proteção contra perda
acidental de trabalho. Nunca usar `-D` maiúsculo sem investigar antes.