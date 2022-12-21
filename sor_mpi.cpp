#include <vector>
#include <mpi.h>

void sor(std::vector<std::vector<double>>& grid,
             const std::vector<std::vector<double>>& rhs,
             double relaxation_param,
             int my_rank,
             int num_procs)
{
    // Get the dimensions of the grid
    int nx = grid.size();
    int ny = grid[0].size();

    // Decompose the grid into blocks for each process
    int local_nx = nx / num_procs;
    int local_ny = ny;
    int start = my_rank * local_nx;
    int end = start + local_nx;

    // Perform SOR iteration on each point in the local block
    for (int i = start+1; i < end-1; i++)
    {
        for (int j = 1; j < ny-1; j++)
        {
            // Update the value at this point using the SOR formula
            // (including the values from the neighboring blocks)
            double left = (i == start) ? 0 : grid[i-1][j];
            double right = (i == end-1) ? 0 : grid[i+1][j];
            grid[i][j] = (1 - relaxation_param) * grid[i][j] +
                         relaxation_param * (left + right + grid[i][j-1] + grid[i][j+1] - rhs[i][j]) / 4.0;
        }
    }

    // Communicate the updated values with the neighboring processes
    if (my_rank > 0)
    {
        MPI_Send(&grid[start], ny, MPI_DOUBLE, my_rank-1, 0, MPI_COMM_WORLD);
        MPI_Recv(&grid[start-1], ny, MPI_DOUBLE, my_rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    if (my_rank < num_procs-1)
    {
        MPI_Send(&grid[end-1], ny, MPI_DOUBLE, my_rank+1, 0, MPI_COMM_WORLD);
        MPI_Recv(&grid[end], ny, MPI_DOUBLE, my_rank+1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
}
