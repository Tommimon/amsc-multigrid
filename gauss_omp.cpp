#include <vector>

void gauss_seidel(std::vector<std::vector<double>>& grid,
                      const std::vector<std::vector<double>>& rhs,
                      double relaxation_param,
                      int my_rank,
                      int num_procs)
{
    // Get the dimensions of the grid
    int nx = grid.size();
    int ny = grid[0].size();

    // Perform Gauss-Seidel iteration on each point in the grid
#pragma omp parallel for
    for (int i = 1; i < nx-1; i++)
    {
        for (int j = 1; j < ny-1; j++)
        {
            // Update the value at this point using the Gauss-Seidel formula
            grid[i][j] = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] - rhs[i][j]) / 4.0;
        }
    }
}
