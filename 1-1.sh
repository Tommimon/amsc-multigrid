#!/bin/sh

g++  converge_solver.cpp jacobi.cpp gauss.cpp sor.cpp -o main.out
time ./main.out 40 j
time ./main.out 40 g
time ./main.out 40 s
