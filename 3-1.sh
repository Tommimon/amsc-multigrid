#!/bin/sh

g++ -D VERBOSE -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
./main.out 40 2 100 10 j > serial.log
g++ -D VERBOSE -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid_omp.cpp -o main.out
./main.out 40 2 100 10 j > parallel.log
diff parallel.log serial.log
