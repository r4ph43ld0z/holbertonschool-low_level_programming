# Memory Maps

## 1. Stack Example

This program shows how memory works when a function calls itself.

The `main()` function calls `walk_stack(0, 3)`. This function calls itself several times until it reaches the maximum depth.

Each function call has its own local variables, such as `depth`, `max_depth` and `marker`. These variables are stored on the stack.

The program also uses a function called `dump_frame()`, which creates a local integer, a character array and a pointer to the local integer.

When a function finishes, its local variables are no longer available. The recursive calls return one by one, starting with the deepest call.

This program does not allocate memory on the heap.

## 2. Heap Example

This program demonstrates how dynamic memory allocation works with `malloc()` and `free()`.

It uses a structure called `Person`, which contains a name and an age.

The program creates two people, Alice and Bob. For each person, it allocates memory for the structure and separately for the name.

Bob's memory is released correctly because the program frees both his name and his structure.

However, there is a problem with Alice. The function `person_free_partial()` only frees her structure and does not free the memory allocated for her name.

As a result, Alice's name remains allocated even though the structure is gone. This is called a memory leak.

This example shows why every allocation must be released correctly.

## 3. Aliasing Example

This program demonstrates pointer aliasing.

It first allocates an array of five integers on the heap. The values are 0, 11, 22, 33 and 44.

Then, the program assigns `a` to `b`. This means both pointers refer to the same memory allocation.

The problem happens when the program calls `free(a)`. The allocated memory is released, but the other pointer is not automatically set to NULL.

The program then tries to access the array using `b`.

This is called a use-after-free because the program tries to access memory after its lifetime has ended. This causes undefined behavior.

Both pointers are local variables stored on the stack, while the array itself is allocated on the heap.

## 4. Crash Example

This program demonstrates the problem of using a NULL pointer.

At the beginning, the pointer `nums` is initialized to NULL and the variable `n` is set to zero.

The function `allocate_numbers()` checks the requested size. Since the size is zero, it returns NULL without allocating any memory.

After that, the program tries to write the value 42 into `nums[0]`.

This causes undefined behavior because `nums` does not point to a valid memory location. The program will usually terminate with a segmentation fault.

No heap memory is allocated in this example.

## 5. AI Explanation Review

I asked an AI tool to explain what happens when two pointers refer to the same memory allocation and one of them is freed.

The explanation was misleading because it suggested that the second pointer could still be used to access the old memory.

After checking the C memory rules, I understood that this was incorrect.

When `free(a)` releases the allocation, the lifetime of the allocated object ends. The other pointer does not automatically become NULL, but it cannot be safely used to access that memory.

This is why the program contains a use-after-free error.

## 6. Conclusion

This exercise helped me understand the difference between stack and heap memory.

The stack stores local variables and function calls. These variables stop existing when their function finishes.

The heap is used for dynamic memory allocation with `malloc()`. This memory must be released with `free()` when it is no longer needed.

I also learned that several pointers can refer to the same allocation. This is called aliasing.

Finally, I understood how memory leaks, NULL pointer dereferences and use-after-free errors can cause problems in C programs.
