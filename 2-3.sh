#!/bin/sh

echo jacobi
g++  main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
time ./main.out 260 3 1000 10 j
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
time ./main.out 260 3 1000 10 j
