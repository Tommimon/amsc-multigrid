#!/bin/sh

g++  main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
./main.out 40 2 100 10 g > serial.log
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
./main.out 40 2 100 10 g > parallel.log
diff parallel.log serial.log

g++  main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
./main.out 40 2 100 10 s > serial.log
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
./main.out 40 2 100 10 s > parallel.log
diff parallel.log serial.log
