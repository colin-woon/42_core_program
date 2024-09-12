# Learning Path
### Time Complexity
### Stack implemented as Circular Buffer
- basically moving the array index to do operations
### Merge Sort
### Quick Sort
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

# How it works:
## Circular Buffer Array
Special functions to handle index increment and decrement
- `get_current_size`
	- Index of top and bottom is the same and at top is 0 = size 0
	- If top > bottom = Size - Top + Bottom + 1
	- Normal case = Bottom - Top + 1
- `get_index_up`
	- Normal case = index - 1 (decrement)
	- If already at start of array, 0 = stack_bottom index
	- If current size of stack is 0 = index
- `get_index_down`
	- Normal case = index + 1 (increment)
	- If already at end of array, 0 = stack top index
	- If current size of stack is 0 = index
### Swap
- If stack is 1 number or empty, do nothing
- Swap using get_index_down with top as index
### Push
- If other stack is full, do nothing
- Push by get_index_up with top index from dest stack, then reassigning the top index of both the src and dest stack
### Rotate
- If stack is full, reassign bottom to top index, increment top index
- If not full, increment bottom index, save value at top index with it, then reassign top index by incrementing it
### Reverse Rotate
- If stack is full, reassign top to bottom index, decrement bottom index
- If not full, decrement top index, save value at bottom index with it, then reassign bottom index by decrementing it

## Three-Way-Quick-Sort

### Check utils_chunk for the split area setting
### Dynamic Pivots
- If TOP_A OR BOTTOM_A
	- pivot lower = size / 3
	- pivot upper = size < 15 ? size : 2 * size / 3
- If TOP_B OR BOTTOM_B
	- pivot upper = size / 2
	- pivot_lower = BOTTOM_B && size < 8 ? size / 2 : size / 3
- Then, and upper and lower threshold is determined by subtracting the pivots  with the current max value of the chunk.
