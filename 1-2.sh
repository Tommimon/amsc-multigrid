#!/bin/sh

g++  converge_multigrid.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
time ./main.out 40 2 1 j
time ./main.out 40 2 1 g
time ./main.out 40 2 1 s
