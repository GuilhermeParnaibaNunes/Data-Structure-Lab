# 🔬 Data Structure Lab

Bem-vindo ao **Data Structure Lab**! 

Este repositório foi criado para descomplicar o aprendizado de Estruturas de Dados e Algoritmos, unindo teoria e prática. Ele foi desenvolvido especialmente como material de apoio para a monitoria de Estrutura de Dados II, servindo tanto como um guia de estudos quanto como um laboratório prático de código.

### 💡 O que você vai encontrar aqui?
* **📘 Apostilas Teóricas:** Resumos e explicações passo a passo estruturados em arquivos `.md`.
* **💻 Implementações Duplas:** Para cada tópico, há o código genérico (a estrutura pura) e uma aplicação demonstrando o seu uso no mundo real.
* **☕ Multi-Linguagem:** Códigos implementados em **C/C++** e **Java**.

### 📂 Estrutura do Repositório
* `/01-Lineares_Basicas` - Listas, Pilhas, Filas e Deque
* `/02-Gerenciamento_e_Recursao` - Alocação dinâmica e problemas recursivos
* `/03-Arvores` - ABB, AVP, Árvore-B
* `/04-Grafos` - Implementações e formas de representação
* `/05-Ordenacao` - Bubble, Insertion, Selection, Merge e Quick Sort
* `/06-Hashing` - Funções de hashing e resolução de colisões
* `/07-Paradigmas` - Algoritmos Gulosos e Programação Dinâmica

### 🚀 Roadmap de Desenvolvimento (Módulo 01)
Abaixo está o planejamento e o status atual da implementação das estruturas lineares básicas:

- [x] 01. Lista Sequencial (Array)
- [ ] 02. Lista Simplesmente Encadeada
- [ ] 03. Lista Duplamente Encadeada
- [ ] 04. Lista Encadeada Circular
- [ ] 05. Pilha Sequencial
- [ ] 06. Pilha Encadeada
- [ ] 07. Fila Sequencial
- [ ] 08. Fila Encadeada
- [ ] 09. Fila Circular
- [ ] 10. Deque

*(As listas de tarefas dos próximos módulos serão adicionadas conforme o avanço do projeto).*

## 🛠️ Ambiente de Build (C/C++)

Os exemplos em C usam `-fsanitize=address` (AddressSanitizer) para
detectar bugs de memória (buffer overflow, use-after-free, memory
leak) — um dos erros mais comuns ao implementar estruturas de dados.

- **Linux / macOS / WSL2:** funciona nativamente, nenhuma configuração extra.
- **Windows nativo (MSYS2/MinGW):** o AddressSanitizer é suportado de
  forma inconsistente entre os ambientes do MSYS2. Se você compilar
  no ambiente **UCRT64**, a flag é automaticamente desabilitada pelo
  Makefile (detecção de SO). Para obter a proteção completa do
  ASan no Windows, duas opções:
  1. Use o ambiente **MSYS2 MinGW64** em vez do UCRT64
     (`pacman -S mingw-w64-x86_64-gcc`), ou
  2. Compile via **WSL2** (recomendado) — ambiente mais próximo do
     usado na correção da disciplina.

### 🤝 Como Contribuir
Alunos e futuros monitores são convidados a contribuir! Leia o arquivo `CONTRIBUTING.md` para entender nosso padrão de commits e o checklist de Pull Requests.

## 🛠️ Ambiente de Build (C/C++)

Os exemplos em C usam `-fsanitize=address` (AddressSanitizer) para
detectar bugs de memória (buffer overflow, use-after-free, memory
leak) — um dos erros mais comuns ao implementar estruturas de dados.

- **Linux / macOS / WSL2:** funciona nativamente, nenhuma configuração extra.
- **Windows nativo (MSYS2/MinGW):** o AddressSanitizer é suportado de
  forma inconsistente entre os ambientes do MSYS2. Se você compilar
  no ambiente **UCRT64**, a flag é automaticamente desabilitada pelo
  Makefile (detecção de SO). Para obter a proteção completa do
  ASan no Windows, duas opções:
  1. Use o ambiente **MSYS2 MinGW64** em vez do UCRT64
     (`pacman -S mingw-w64-x86_64-gcc`), ou
  2. Compile via **WSL2** (recomendado) — ambiente mais próximo do
     usado na correção da disciplina.