[🇧🇷 Português](./README.md) | 🇺🇸 English

# 🔬 Data Structure Lab

Welcome to **Data Structure Lab**!

This repository was created to demystify the study of Data Structures and Algorithms, bringing theory and practice together. It was developed specifically as support material for the Data Structures II teaching assistantship, serving both as a study guide and a practical code lab.

### 💡 What will you find here?
* **📘 Theoretical Handouts:** Step-by-step summaries and explanations structured as `.md` files.
* **💻 Dual Implementations:** For each topic, there's the generic code (the pure structure) and an application demonstrating its real-world use.
* **☕ Multi-Language:** Code implemented in **C/C++** and **Java**.

### 📂 Repository Structure
* `/01-Lineares_Basicas` - Lists, Stacks, Queues, and Deque
* `/02-Gerenciamento_e_Recursao` - Dynamic allocation and recursive problems
* `/03-Arvores` - BST, AVL, B-Tree
* `/04-Grafos` - Implementations and representation formats
* `/05-Ordenacao` - Bubble, Insertion, Selection, Merge and Quick Sort
* `/06-Hashing` - Hashing functions and collision resolution
* `/07-Paradigmas` - Greedy Algorithms and Dynamic Programming

### 🚀 Development Roadmap (Module 01)
Below is the plan and current implementation status of the basic linear structures:

- [x] 01. Sequential List (Array)
- [ ] 02. Singly Linked List
- [ ] 03. Doubly Linked List
- [ ] 04. Circular Linked List
- [ ] 05. Sequential Stack
- [ ] 06. Linked Stack
- [ ] 07. Sequential Queue
- [ ] 08. Linked Queue
- [ ] 09. Circular Queue
- [ ] 10. Deque

*(Task lists for upcoming modules will be added as the project progresses).*

## 🛠️ Build Environment (C/C++)

The C examples use `-fsanitize=address` (AddressSanitizer) to detect
memory bugs (buffer overflow, use-after-free, memory leaks) — one of
the most common errors when implementing data structures.

- **Linux / macOS / WSL2:** works natively, no extra setup required.
- **Native Windows (MSYS2/MinGW):** AddressSanitizer support is
  inconsistent across MSYS2 environments. If you compile in the
  **UCRT64** environment, the flag is automatically disabled by the
  Makefile (OS detection). To get full ASan protection on Windows,
  two options:
  1. Use the **MSYS2 MinGW64** environment instead of UCRT64
     (`pacman -S mingw-w64-x86_64-gcc`), or
  2. Compile via **WSL2** (recommended) — closer to the environment
     used for grading in the course.

### 🤝 How to Contribute
Students and future teaching assistants are invited to contribute! Read the `CONTRIBUTING.md` file to understand our commit standards and Pull Request checklist.