[🇧🇷 Português](./CONTRIBUTING.md) | 🇺🇸 English

# Contributing to Data Structure Lab

We're glad you want to contribute! This repository is maintained to help students, and contributions from other teaching assistants or students are very welcome.

## Commit Convention

We use a standard based on Conventional Commits to keep the history organized. The format is:
`<type>(<scope>): <description>`

**Examples:**
* `feat(01-lineares): add doubly linked list impl` (New implementations)
* `fix(04-grafos): fix segfault in breadth-first search` (Bug fixes)
* `docs(03-arvores): update balanced tree handout` (Changes to .md files)

## Naming Convention
- Documentation and folders: `Title_Case` (e.g. `Apostila.md`, `Lista_Sequencial/`)
- C code: `snake_case` (e.g. `lista_sequencial.c`)
- Java code: `PascalCase` for classes (e.g. `ListaSequencial.java`)

## Pull Request (PR) Checklist

Before submitting your PR, make sure your contribution meets the requirements below:

- [ ] **Compilation:** The code compiles via `make` with no *warnings* or errors (default flags: `-Wall -Wextra -fsanitize=address`).
- [ ] **Documentation:** The corresponding theoretical "handout" (`.md`) was created or updated.
- [ ] **Practice:** The code includes the generic version of the structure and a working example (`demo`) simulating a real application.
- [ ] **Consistency:** Files were placed in the correct module folder and follow the project's naming convention.

## Branch Workflow per Structure

Each structure in the checklist is developed on its own branch, following
the pattern `feat/<number>-<structure-name>` (e.g. `feat/01-lista-sequencial`).

1. Create the branch from `main`:
```bash
   git checkout -b feat/NN-structure-name
```
2. Develop the structure's full commit cycle (handout, C, Java,
   exercises, EN translations — see commit standard above).
3. Merge into `main` and clean up the branch:
```bash
   git checkout main
   git merge feat/NN-structure-name
   git branch -d feat/NN-structure-name
   git push origin --delete feat/NN-structure-name  # if pushed remotely
```

`git branch -d` (lowercase) is intentional — it only allows deleting branches
that are already fully merged into `main`, acting as a safeguard against
accidental loss of work. Never use uppercase `-D` without investigating first.