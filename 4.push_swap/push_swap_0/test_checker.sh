#!/bin/bash

echo "CONDITION ac > 1 && ac <=3"
echo "Coloured OK"
./push_swap "1 2 3" | ./checker -c "1 2 3"
./push_swap "3 2 1" | ./checker -c "3 2 1"
./push_swap "1 2 3" | ./checker "1 2 3" -c
./push_swap "3 2 1" | ./checker "3 2 1" -c
./push_swap "7 6 5 4 3 2 1" | ./checker "7 6 5 4 3 2 1" -c
./push_swap "7 6 5 4 3 2 1" | ./checker -c "7 6 5 4 3 2 1"
echo ""

echo "Normal OK"
./push_swap "1 2 3" | ./checker "1 2 3"
./push_swap "3 2 1" | ./checker "3 2 1"
echo ""

echo "Should be Error"
./push_swap "1 2 3" | ./checker "-c 1 2 3"
./push_swap "1 2 3" | ./checker "1 2 3 -c"
./push_swap "1 2 3" | ./checker "1 2 -c 3"
./push_swap "1 2 3" | ./checker "-c1 2 3"
./push_swap "1 2 3" | ./checker "1-c 2 3"
./push_swap "1 2 3" | ./checker "1 2 3-c"
./push_swap "1 2 3" | ./checker "1 2 -c3"
./push_swap "1 2 3" | ./checker "1 2-c 3"
./push_swap "1 2 3" | ./checker "1 -c2 3"
echo ""

echo "CONDITION ac > 3"
echo "Coloured OK"
./push_swap 3 2 1 | ./checker -c 3 2 1
./push_swap 3 2 1 | ./checker 3 2 1 -c
./push_swap 1 2 3 | ./checker 1 2 3 -c
./push_swap 1 2 3 | ./checker -c 1 2 3
echo ""

echo "Should be Error"
./push_swap 3 2 1 | ./checker 3-c 2 1
./push_swap 3 2 1 | ./checker -c3 2 1
./push_swap 3 2 1 | ./checker 3 -c2 1
./push_swap 3 2 1 | ./checker 3 2 -1c
./push_swap 3 2 1 | ./checker 3 2 -c1
./push_swap 3 2 1 | ./checker 3 2 1-c
echo ""
