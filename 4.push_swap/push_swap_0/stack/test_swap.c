#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"  // Include the necessary header file

void print_stack(t_stack *stack) {
    printf("Stack elements: ");
    for (int i = 0; i < stack->size; i++) {
        printf("%d ", stack->buffer[i]);
    }
    printf("\n");
}

int main(void) {
    // Initialize the data structure for testing
    t_push_swap data;
    data.stack_a.buffer = (int*)malloc(7 * sizeof(int));
    data.stack_a.i_top = 1;
    data.stack_a.size = 7;
    data.stack_a.buffer[0] = 0;
    data.stack_a.buffer[1] = 2;
    data.stack_a.buffer[2] = 3;
    data.stack_a.buffer[3] = 4;
    data.stack_a.buffer[4] = 0;
    data.stack_a.buffer[5] = 0;
    data.stack_a.buffer[6] = 0;

    data.stack_b.buffer = (int*)malloc(7 * sizeof(int));
    data.stack_b.i_top = 1;
    data.stack_b.size = 7;
    data.stack_b.buffer[0] = 0;
    data.stack_b.buffer[1] = 8;
    data.stack_b.buffer[2] = 9;
    data.stack_b.buffer[3] = 10;
    data.stack_b.buffer[4] = 0;
    data.stack_b.buffer[5] = 0;
    data.stack_b.buffer[6] = 0;

    data.write_mode = true;

    printf("Initial state:\n");
    printf("Stack A:\n");
    print_stack(&data.stack_a);
    printf("Stack B:\n");
    print_stack(&data.stack_b);

    // Test swap_a
    printf("\nTesting swap_a:\n");
    swap_a(&data);
    print_stack(&data.stack_a);

    // Test swap_b
    printf("\nTesting swap_b:\n");
    swap_b(&data);
    print_stack(&data.stack_b);

    // Modify i_top to 2 (to test the swap with different i_top)
    data.stack_a.i_top = 2;
    data.stack_b.i_top = 2;

    printf("\nState after changing i_top to 2:\n");
    printf("Stack A:\n");
    print_stack(&data.stack_a);
    printf("Stack B:\n");
    print_stack(&data.stack_b);

    // Test swap_a with i_top = 2
    printf("\nTesting swap_a with i_top set to 2:\n");
    swap_a(&data);
    print_stack(&data.stack_a);

    // Test swap_b with i_top = 2
    printf("\nTesting swap_b with i_top set to 2:\n");
    swap_b(&data);
    print_stack(&data.stack_b);

    // Cleanup
    free(data.stack_a.buffer);
    free(data.stack_b.buffer);

    return 0;
}
