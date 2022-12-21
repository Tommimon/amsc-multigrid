cmake_minimum_required(VERSION 3.23)
project(amsc_multigrid)

set(CMAKE_CXX_STANDARD 14)

add_executable(amsc_multigrid main.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp)
add_executable(amsc_converge_solver converge_solver.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp)
add_executable(amsc_converge_multigrid converge_multigrid.cpp jacobi.cpp gauss.cpp sor.cpp multigrid.cpp)
add_executable(amsc_multigrid_mpi main.cpp jacobi_omp.cpp gauss_omp.cpp sor_omp.cpp multigrid_omp.cpp)

include_directories(/var/run/host/usr/lib/x86_64-linux-gnu/openmpi/include)
