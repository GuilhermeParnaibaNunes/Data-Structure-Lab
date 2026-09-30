# Practice Exercises: Sequential List

These exercises test your understanding of memory mechanics, asymptotic complexity, and the practical limitations of the Sequential List. Try to solve them before checking the answer key.

## Questions

**Question 1: Cost and Movement Analysis**
Imagine a Sequential List with a maximum capacity (`MAX`) of 10,000 items, currently holding 5,000 stored elements.
1. What is the time complexity (Big-O Notation) for accessing the element at position 4,999?
2. What is the complexity for inserting a new element at position `0`? How many element copies will the processor need to perform?

**Question 2: Bug Hunting (The Shift Problem)**
A student tried to implement the middle-insertion operation, but made a logical error in the loop (right shift). See the snippet below:

```c
// Shift right (makes room)
for (int i = position; i < list->current_size; i++) {
    list->items[i + 1] = list->items[i];
}
list->items[position] = new_value;

```

Explain the fatal flaw in this code snippet and how it corrupts the list's data.

**Question 3: Architecture Decision (Trade-offs)**
In our `demo_cadastro_alunos.c`, assume the university registrar's office decided to keep the student list **always sorted alphabetically**. Every day, dozens of new students are enrolled and dozens of transfers (removals) occur, with names falling in the middle of the alphabetical order.
Why would the Sequential List be a poor architectural choice for this specific scenario?

**Question 4: Logic Challenge (In-place Reversal)**
How would you implement a function `reverse_list(ListaSequencial *l)` that reverses the order of all elements within the list itself, without using a second auxiliary array? What would be the time complexity of this operation?

---

## Answer Key

**Question 1 Solution**

1. Access costs $O(1)$ (Best/Worst case). Since the list uses a contiguous array under the hood, the memory address is calculated mathematically in an instant (Base Address + (Index * Type Size)), regardless of whether it's index 0 or 4,999.
2. Insertion at position `0` (start of the list) costs $O(n)$ in the worst case. The processor will need to perform exactly **5,000 copies**, "pushing" every element one position to the right to open a gap at index 0 without overwriting anything.

**Question 2 Solution**
The flaw is that the loop iterates from left to right. By doing `items[position + 1] = items[position]`, the student overwrites and destroys the data that was in the next position *before* it has been copied forward. The result is that the first shifted value propagates through the entire list, wiping out all the other data (a chain reaction of overwrites).
*The fix:* the right shift must always happen back-to-front (descending from `current_size` down to `position`).

**Question 3 Solution**
A list kept permanently sorted requires insertions and removals to occur, on average, in the middle of the array. Since the Sequential List has $O(n)$ complexity for these operations — due to the constant need for memory shifting — the system would lose significant performance under the high daily volume of entries and exits. (Node-based linked structures or trees would be more scalable solutions here.)

**Question 4 Solution**
The reversal can be done using the *Two Pointers* technique (one at the start, one at the end), swapping elements and converging toward the center:

```c
void reverse_list(ListaSequencial *l) {
    int start = 0;
    int end = l->current_size - 1;
    TipoItem temp;
    
    while (start < end) {
        // Perform the swap
        temp = l->items[start];
        l->items[start] = l->items[end];
        l->items[end] = temp;
        
        start++;
        end--;
    }
}

```

*Complexity:* Time is $O(n)$, since the loop runs exactly `n/2` times, touching every element in the list. Additional space is $O(1)$, as it only uses the `temp` variable.