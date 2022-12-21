#!/bin/sh

echo jacobi
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
time ./main.out 1024 10 200 1 j
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid_omp.cpp -o main.out
time ./main.out 1024 10 200 1 j


echo jacobi
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
time ./main.out 4096 4 20 1 j
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid_omp.cpp -o main.out
time ./main.out 4096 4 20 1 j
