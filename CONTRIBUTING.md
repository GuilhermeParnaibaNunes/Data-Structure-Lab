# Contribuindo para o Data Structure Lab

Ficamos felizes que você queira contribuir! Este repositório é mantido para auxiliar alunos, e contribuições de outros monitores ou estudantes são muito bem-vindas.

## Padrão de Commits

Utilizamos um padrão baseado no Conventional Commits para manter o histórico organizado. O formato é:
`<tipo>(<escopo>): <descrição>`

**Exemplos:**
* `feat(01-lineares): add doubly linked list impl` (Novas implementações)
* `fix(04-grafos): corrige erro de segmentação na busca em largura` (Correção de bugs)
* `docs(03-arvores): atualiza apostila de árvore balanceada` (Alterações nos arquivos .md)

## Checklist de Pull Request (PR)

Antes de enviar seu PR, garanta que sua contribuição atende aos requisitos abaixo:

- [ ] **Compilação:** O código compila via `make` sem *warnings* ou erros (flags padrão: `-Wall -Wextra -fsanitize=address`).
- [ ] **Documentação:** A respectiva "apostila" teórica (`.md`) foi criada ou atualizada.
- [ ] **Prática:** O código inclui a versão genérica da estrutura e um exemplo funcional (`demo`) simulando uma aplicação real.
- [ ] **Consistência:** Os arquivos foram alocados na pasta correta do módulo e seguem o padrão de nomenclatura do projeto.