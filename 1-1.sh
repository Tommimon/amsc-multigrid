#!/bin/sh

g++  solver_main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
time ./main.out 40 2 j
time ./main.out 40 2 g
time ./main.out 40 2 s
