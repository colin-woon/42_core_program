#!/bin/bash

echo "CONDITION ac > 1 && ac <=3"
echo "Normal OK"
./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker -c "1 2 3"
./push_swap "3 2 1" | valgrind -s --leak-check=full ./checker -c "3 2 1"
./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1 2 3" -c
./push_swap "3 2 1" | valgrind -s --leak-check=full ./checker "3 2 1" -c
./push_swap "7 6 5 4 3 2 1" | valgrind -s --leak-check=full ./checker "7 6 5 4 3 2 1" -c
./push_swap "7 6 5 4 3 2 1" | valgrind -s --leak-check=full ./checker -c "7 6 5 4 3 2 1"
echo ""

# echo "Coloured OK"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1 2 3"
# ./push_swap "3 2 1" | valgrind -s --leak-check=full ./checker "3 2 1"
# echo ""

# echo "Should be Error"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "-c 1 2 3"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1 2 3 -c"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1 2 -c 3"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "-c1 2 3"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1-c 2 3"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1 2 3-c"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1 2 -c3"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1 2-c 3"
# ./push_swap "1 2 3" | valgrind -s --leak-check=full ./checker "1 -c2 3"
# echo ""

# echo "CONDITION ac > 3"
# echo "Normal OK"
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker -c 3 2 1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 2 1 -c
# ./push_swap 1 2 3 | valgrind -s --leak-check=full ./checker 1 2 3 -c
# ./push_swap 1 2 3 | valgrind -s --leak-check=full ./checker -c 1 2 3
# echo ""

# echo "Should be Error"
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3-c 2 1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker -c3 2 1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 -c2 1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 2 -1c
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 2 -c1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 2 1-c
# echo ""

# echo "Should be Error when 2 flags"
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 2 1-cv
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 2 1-cc
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 2 1 -c -c
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 2 1 -c -c
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker -c -c 3 2 1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker -c -c 3 2 1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker -cc 3 2 1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker -cv 3 2 1
# ./push_swap 3 2 1 | valgrind -s --leak-check=full ./checker 3 -c -c 2 1
# echo ""
