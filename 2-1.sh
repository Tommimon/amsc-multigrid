#!/bin/sh

g++ -D VERBOSE main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
./main.out 40 2 100 10 j > serial.log
g++ -D VERBOSE -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
./main.out 40 2 100 10 j > parallel.log
diff parallel.log serial.log
