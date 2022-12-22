# Multigrid Hands-on Project

## Questions

### 1.1
With a size of 40 jacobi solver takes 0.695s to converge. gauss seidel and
sor take less than a half (0.266s). The number of iteration is 8633 for
jacobi and 4319 for gauss.

### 1.2
With the same size using the multi-grid decreases drammatically the number
of iteration required and the execution time (0.015s for all of them).
77 iterations for jacobi and 92 for gauss.

### 2.1
By comparing the output we are testing the correctness of the jacobi OpenMP
implementation.

### 2.2
By comparing the output we are testing the correctness of the gauss seidel
and sor OpenMP implementations.

### 2.3
The jacobi OpenMP implementation has a high grade of parallelization, so we can
see a clear difference in the execution time also with a size of 260.

On the other hand the gauss seidel and sor solvers have less parallel
operation and so the OpenMP implementation performs the same with this size.
In order to see a difference I had to increase the size by a factor of 10
to 2600.

### 3.1
By comparing the output we are testing the correctness of the multi-grid 
OpenMP implementations.

### 3.2
With a size of 1024 the difference is almost zero but by increasing the size
to 4096 it's clear that the parallel implementation offers a speedup on
big grids.


## Conclusions

The OpenMP implementation of the solvers and the multi-grid algorithm are
granted to provide the same result as the serial version.

The OpenMP implementation offers a speedup on big matrices but if the size
is too small the cost of creating and starting the threads is more than the
parallel speedup.
