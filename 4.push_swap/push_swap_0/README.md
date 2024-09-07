#Learning Path
## Time Complexity
## Stack implemented as Circular Buffer
- basically moving the array index to do operations
## Merge Sort
## Quick Sort
- Divide & Conquer
- Dutch National Flag Algorithm (Three-way Quick Sort)

# Project Breakdown
1. Check Valid Input
3. Stack ADT
4. Sort 3
5. Sort 5
6. Sort (2 & 4) (Optional)
7. Make strings usable
8. Three-way Quick Sort (Combining Merge Sort and Quick Sort)

# Flow
Sort is done first > Store operations in Linked List > Optimize Operations

# Issues Faced
1. Compiling other codebase as example, but when running make in windows, will have reference error. Turns out linker sequence when compiling will make a difference, particularly when linking with library (libft.a) (-lft)
```
// Incorrect
gcc -Wall -Wextra -Werror -Iinclude -Isrc -O3 -I lib/libft/include -I lib/ft_printf/include lib/libft/libft.a lib/ft_printf/ft_printf.a obj/push_swap/opti_post_sort_utils.o -o push_swap

// Correct
gcc -Wall -Wextra -Werror -Iincludes/ -ILibft/srcs/ -LLibft/ objs/push_swap.o objs/operations1.o objs/operations2.o objs/ps_utils.o objs/check_input.o objs/sort_small.o objs/sort_big.o -lft -o push_swap
```

2. Memory leak if a new linked list is not created during optimization.

# Misc
- -O3 & -O2 optimization flag
- patsubst makefile
- Doubly Linked list used for operations list

# Reference
https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0

# Tester
https://github.com/PepeSegura/push_swap_Tester (Validation)
https://github.com/SimonCROS/push_swap_tester (Benchmark)
