cmake_minimum_required(VERSION 3.23)
project(amsc_multigrid)

set(CMAKE_CXX_STANDARD 14)

add_executable(amsc_multigrid main.cpp jacobi.cpp gauss.cpp sor.cpp)

include_directories(/var/run/host/usr/lib/x86_64-linux-gnu/openmpi/include)
