# Valgrind Analysis

## 1. Stack Example

I ran Valgrind on `stack_example` using the full leak check and origin tracking options.

Valgrind reported zero errors and no memory leaks.

The program uses recursive function calls and local variables stored on the stack. Each function call has its own local variables, which stop existing when the function returns.

Valgrind reported one allocation and one free, with 1,024 bytes allocated in total. No memory remained allocated when the program finished.

There were no invalid reads, invalid writes or uses of uninitialized memory.

## 2. Heap Example

Valgrind reported one memory leak in `heap_example`.

The report showed that 6 bytes in one block were definitely lost.

The allocation was made by `person_new()` at line 21 of `heap_example.c`, called from `main()` at line 51.

The memory block contains Alice's name. The program allocates memory for the Person structure and separately for the name.

The problem is that the program frees Alice's structure without freeing the memory allocated for her name.

As a result, the pointer to the name is lost and the allocated memory cannot be released anymore.

This is a memory leak caused by lost ownership.

The 6 bytes correspond to the five characters in "Alice" and the terminating null character.

Bob's memory is released correctly. Valgrind reported no invalid reads or writes in this program.

## 3. Aliasing Example

Valgrind reported three memory errors in `aliasing_example`.

The first error is an invalid read at line 42. The program tries to read `b[2]` after the memory has been freed.

The second error is an invalid write at line 44. The program tries to write to `b[3]` after the allocation has been released.

The third error is another invalid read at line 45. The program tries to read `b[3]` after the invalid write.

All three errors concern the same memory block of 20 bytes.

The problem comes from pointer aliasing. Both pointers `a` and `b` refer to the same heap allocation.

When the program calls `free(a)`, the allocated memory is released. Using `b` afterwards to access that memory causes a use-after-free error.

Valgrind also shows that the program has no memory leaks because all allocated blocks were freed before it finished.

Even though Valgrind displayed the value 22 after the invalid read, this does not mean the access was valid. The memory had already been freed, so the behavior was undefined.

## 4. Crash Example

Valgrind reported one invalid write in `crash_example`.

The error happens at line 32 of `crash_example.c`.

The program requests an allocation with a size of zero. The allocation function returns NULL because no valid array is created.

The program then tries to write the value 42 using `nums[0]`.

This is a NULL pointer dereference because the pointer does not refer to a valid memory location.

Valgrind reports an invalid write at address 0 and the program terminates with signal 11, also known as SIGSEGV.

Valgrind also reports 1,024 bytes as still reachable. These bytes come from an internal buffer used by the C standard library when printing with `puts()`. They are not a memory leak caused by the program itself.

There are no definitely lost bytes in this execution.

## 5. AI Explanation Review

I used AI to help understand the Valgrind output.

One explanation that needed verification concerned the 1,024 bytes reported as still reachable in `crash_example`.

An initial interpretation could classify these bytes as a memory leak. However, this would be incorrect.

After checking the stack trace, I found that the allocation comes from the standard library's internal output buffer, used by `puts()`.

The memory is still reachable, which means that a pointer to it still exists when the program terminates. It is not classified as definitely lost.

This shows why Valgrind's output must be checked against the source code and the actual memory behavior instead of accepting an AI explanation without verification.

## 6. Conclusion

This exercise helped me understand how Valgrind reports memory problems.

I learned that a memory leak happens when allocated memory loses its ownership and cannot be freed.

I also learned that a use-after-free happens when a program accesses memory after its lifetime has ended.

Finally, I understood that accessing a NULL pointer can cause an invalid memory operation and a segmentation fault.

Valgrind helped me connect each error to a specific line of code and understand the reason behind it.
