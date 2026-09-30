[🇧🇷 Português](./Apostila.md) | 🇺🇸 English

# Sequential List (Array-based List)

## 1. Motivation
The Sequential List is the starting point in the study of data structures. It exists to solve the most fundamental storage problem: storing a collection of items in a way that we can access them instantly if we know their position. Because it is mapped directly onto physical memory blocks, it is the structure that the processor handles with the greatest natural efficiency.

## 2. Definition
A Sequential List is a linear data structure where elements are stored in **contiguous memory locations**. This means that the data sits "side-by-side" physically in the computer's RAM. 

By using arrays as a base, it has a pre-defined maximum size (capacity) and an internal counter that tracks how many elements are currently stored (current size).

## 3. Visual Representation
```text
Indices:       0       1       2       3       4
           +-------+-------+-------+-------+-------+
Memory:    |  10   |  30   |  20   | EMPTY | EMPTY |
           +-------+-------+-------+-------+-------+
           
Current Size: 3
Maximum Capacity: 5

```

## 4. Time Complexity

| Operation | Best Case | Worst Case (Big-O) | Justification |
| --- | --- | --- | --- |
| **Access (by index)** | O(1) | O(1) | Direct mathematical calculation using the base address + index. |
| **Search (by value)** | O(1) | O(n) | Requires linear scan. O(1) if it's the first element, O(n) if it's the last or doesn't exist. |
| **Insertion (at the end)** | O(1) | O(1) | Just add it to the next available position. |
| **Insertion (start/middle)** | O(n) | O(n) | Requires shifting all subsequent elements to the right. |
| **Removal (at the end)** | O(1) | O(1) | Just decrement the size counter. |
| **Removal (start/middle)** | O(n) | O(n) | Requires shifting all subsequent elements to the left. |

## 5. Trade-offs (Advantages vs. Disadvantages)

### Advantages

* **Random Access:** Reading the element at position `1` or `1000` takes exactly the same amount of time.
* **Locality of Reference:** Since data is packed together in memory, the CPU can load the entire list into the Cache memory, making iterations extremely fast.
* **Simplicity:** Easy to implement and low memory overhead (does not require additional pointers for each node).

### Disadvantages

* **Fixed Size:** Requires predicting the maximum capacity in advance. If the list fills up, you must allocate a new, larger array and copy everything over (an expensive operation). Over-allocating leads to wasted memory.
* **Movement Cost:** Inserting or removing elements at the beginning or middle of the list is inefficient because it forces the processor to shift dozens or thousands of items to reorganize the space.

## 6. Pseudocode of Main Operations

**Insertion at a specific position:**

```text
function insert(list, value, position):
    if list.current_size == list.max_capacity:
        return ERROR_LIST_FULL
    
    if position < 0 or position > list.current_size:
        return ERROR_INVALID_POSITION
    
    // Shift right (makes room for the new element)
    for i from list.current_size down to position (step -1):
        list.elements[i] = list.elements[i - 1]
    
    list.elements[position] = value
    list.current_size = list.current_size + 1

```

**Removal from a specific position:**

```text
function remove(list, position):
    if list.current_size == 0:
        return ERROR_LIST_EMPTY
        
    if position < 0 or position >= list.current_size:
        return ERROR_INVALID_POSITION
        
    removed_value = list.elements[position]
    
    // Shift left (fills the gap left by the removed element)
    for i from position up to list.current_size - 2 (step 1):
        list.elements[i] = list.elements[i + 1]
        
    list.current_size = list.current_size - 1
    return removed_value

```

## 7. Implementations

* [C Implementation](./C/)
* [Java Implementation](./Java/)

## 8. Practical Application

The `C/` folder contains two demonstration programs with distinct purposes:

* **`demo_lista_sequencial.c`** — validates the generic structure in isolation, testing insertion, removal, and search operations with simple integer values.
* **`demo_cadastro_alunos.c`** — the actual practical application. It simulates a class diary system (CRUD), where the Sequential List stores and manages an array of `struct Aluno` (student ID and name). It illustrates how the generic list abstraction serves as an engine for real-world business rules.

## 9. Proposed Exercises

The practice exercises for this topic can be found in [Exercicios.md](./Exercicios.en.md).

## 10. References

* ZIVIANI, N. Projeto de Algoritmos com implementações em Java e C++. São Paulo: CENGAGE Learning, 2012.
* ASCENSIO, A. F.; ARAUJO, G. S. Estrutura de Dados: Algoritmos, Análise da Complexidade e Implementações em Java e C/C++. São Paulo: Pearson, 2010.