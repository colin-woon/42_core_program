#!/bin/bash

echo "CONDITION ac > 1 && ac <=3"
echo "Coloured OK"
./push_swap "1 2 3" | ./checker -v "1 2 3"
./push_swap "3 2 1" | ./checker -v "3 2 1"
./push_swap "1 2 3" | ./checker "1 2 3" -v
./push_swap "3 2 1" | ./checker "3 2 1" -v
./push_swap "7 6 5 4 3 2 1" | ./checker "7 6 5 4 3 2 1" -v
./push_swap "7 6 5 4 3 2 1" | ./checker -v "7 6 5 4 3 2 1"
echo ""

echo "Normal OK"
./push_swap "1 2 3" | ./checker "1 2 3"
./push_swap "3 2 1" | ./checker "3 2 1"
echo ""

echo "Should be Error"
./push_swap "1 2 3" | ./checker "-v 1 2 3"
./push_swap "1 2 3" | ./checker "1 2 3 -v"
./push_swap "1 2 3" | ./checker "1 2 -v 3"
./push_swap "1 2 3" | ./checker "-v1 2 3"
./push_swap "1 2 3" | ./checker "1-v 2 3"
./push_swap "1 2 3" | ./checker "1 2 3-v"
./push_swap "1 2 3" | ./checker "1 2 -v3"
./push_swap "1 2 3" | ./checker "1 2-v 3"
./push_swap "1 2 3" | ./checker "1 -v2 3"
echo ""

echo "CONDITION ac > 3"
echo "Coloured OK"
./push_swap 3 2 1 | ./checker -v 3 2 1
./push_swap 3 2 1 | ./checker 3 2 1 -v
./push_swap 1 2 3 | ./checker 1 2 3 -v
./push_swap 1 2 3 | ./checker -v 1 2 3
echo ""

echo "Should be Error"
./push_swap 3 2 1 | ./checker 3-v 2 1
./push_swap 3 2 1 | ./checker -v3 2 1
./push_swap 3 2 1 | ./checker 3 -v2 1
./push_swap 3 2 1 | ./checker 3 2 -1c
./push_swap 3 2 1 | ./checker 3 2 -v1
./push_swap 3 2 1 | ./checker 3 2 1-v
echo ""
