#!/bin/sh

g++  solver_main.cpp jacobi.cpp gauss.cpp sor.cpp -o main.out
time ./main.out 40 j
time ./main.out 40 g
time ./main.out 40 s
