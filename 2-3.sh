#!/bin/sh

echo jacobi
g++  main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
time ./main.out 260 3 100 10 j
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
time ./main.out 260 3 100 10 j

echo gauss
g++  main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
time ./main.out 260 3 100 10 g
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
time ./main.out 260 3 100 10 g

echo sor
g++  main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp -o main.out
time ./main.out 260 3 100 10 s
g++ -fopenmp main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid.cpp -o main.out
time ./main.out 260 3 100 10 s
