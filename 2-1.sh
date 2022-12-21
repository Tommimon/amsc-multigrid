#!/bin/sh

g++  main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
./main.out 40 2 j > serial.log
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
./main.out 40 2 j > parallel.log
diff parallel.log serial.log
