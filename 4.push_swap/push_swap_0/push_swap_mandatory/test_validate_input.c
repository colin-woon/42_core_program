#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

// ANSI color codes
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

// Function declarations
void convert_and_validate(int argc, char **argv);
void run_test_case(int argc, char **argv, const char *expected_result);

// Main function to run all test cases
int main(void)
{
    // 1. Test: Valid input with multiple numerical arguments
    char *test_case1[] = {"./push_swap", "1", "3", "5", "+9", "20", "-4", "50", "60", "04", "08"};
    run_test_case(11, test_case1, "Valid");

    // 2. Test: Valid input with a single character list as a parameter
    char *test_case2[] = {"./push_swap", "3 4 6 8 9 74 -56 +495"};
    run_test_case(2, test_case2, "Valid");

    // 3. Test: Invalid input with a non-numerical character ("dog")
    char *test_case3[] = {"./push_swap", "1", "3", "dog", "35", "80", "-3"};
    run_test_case(7, test_case3, "Error");

    // 4. Test: Invalid input with a single non-numerical character ("a")
    char *test_case4[] = {"./push_swap", "a"};
    run_test_case(2, test_case4, "Error");

    // 5. Test: Invalid input with non-numerical characters in a number ("67b778")
    char *test_case5[] = {"./push_swap", "1", "2", "3", "5", "67b778", "947"};
    run_test_case(7, test_case5, "Error");

    // 6. Test: Invalid input with non-numerical characters in a string ("54fhd")
    char *test_case6[] = {"./push_swap", "12 4 6 8 54fhd 4354"};
    run_test_case(2, test_case6, "Error");

    // 7. Test: Invalid input with multiple hyphens ("--")
    char *test_case7[] = {"./push_swap", "1", "--", "45", "32"};
    run_test_case(5, test_case7, "Error");

    // 8. Test: Invalid input with a duplicated number ("3" twice)
    char *test_case8[] = {"./push_swap", "1", "3", "58", "9", "3"};
    run_test_case(6, test_case8, "Error");

    // 9. Test: Invalid input with a duplicated number in different formats ("3" and "03")
    char *test_case9[] = {"./push_swap", "3", "03"};
    run_test_case(3, test_case9, "Error");

    // 10. Test: Invalid input with a duplicated number in a single argument ("49" twice)
    char *test_case10[] = {"./push_swap", "49 128 50 38 49"};
    run_test_case(2, test_case10, "Error");

    // 11. Test: Valid input with similar but non-duplicate numbers ("-9" and "9")
    char *test_case11[] = {"./push_swap", "95 99 -9 10 9"};
    run_test_case(2, test_case11, "Valid");

    // 12. Test: Valid input with INT_MAX and normal integers
    char *test_case12[] = {"./push_swap", "2147483647", "2", "4", "7"};
    run_test_case(5, test_case12, "Valid");

    // 13. Test: Valid input with INT_MIN and normal integers
    char *test_case13[] = {"./push_swap", "99", "-2147483648", "23", "545"};
    run_test_case(5, test_case13, "Valid");

    // 14. Test: Valid input with INT_MAX in a string
    char *test_case14[] = {"./push_swap", "2147483647 843 56544 24394"};
    run_test_case(2, test_case14, "Valid");

    // 15. Test: Invalid input with an out-of-range integer
    char *test_case15[] = {"./push_swap", "54867543867438", "3"};
    run_test_case(3, test_case15, "Error");

    // 16. Test: Invalid input with an out-of-range negative integer
    char *test_case16[] = {"./push_swap", "-2147483647765", "4", "5"};
    run_test_case(4, test_case16, "Error");

    // 17. Test: Invalid input with an out-of-range integer in a string
    char *test_case17[] = {"./push_swap", "214748364748385 28 47 29"};
    run_test_case(2, test_case17, "Error");

    // 18. Test: Mixed strings and integers
    char *test_case18[] = {"./push_swap", "1 2 4 3", "76", "90", "348 05"};
    run_test_case(5, test_case18, "Valid");

    return 0;
}

// Assuming convert_and_validate() exits on error, we capture that in our test function
void run_test_case(int argc, char **argv, const char *expected_result)
{
    printf("Running test case: %s\n", expected_result);
    int result = 0;  // 0 for success, 1 for error

    // Since convert_and_validate might exit, you can catch the output using system or conditional checks
    if (fork() == 0) {
        convert_and_validate(argc, argv);  // This will exit if there's an error
        exit(0);  // Exit with success if no error
    } else {
        int status;
        wait(&status);  // Wait for the child process to finish
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            result = 1;
    }

    if ((result == 0 && strcmp(expected_result, "Valid") == 0) ||
        (result == 1 && strcmp(expected_result, "Error") == 0))
    {
        printf(COLOR_GREEN "Output: %s\nExpected: %s\n" COLOR_RESET, expected_result, expected_result);
    }
    else
    {
        printf(COLOR_RED "Output: %s\nExpected: %s\n" COLOR_RESET, result == 0 ? "Valid" : "Error", expected_result);
    }
    printf("\n");
}
