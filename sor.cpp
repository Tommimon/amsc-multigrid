#include <vector>

void sor(std::vector<std::vector<double>>& grid,
         const std::vector<std::vector<double>>& rhs,
         double relaxation_param)
{
    // Get the dimensions of the grid
    int nx = grid.size();
    int ny = grid[0].size();

    // Perform SOR iteration on each point in the grid
    for (int i = 1; i < nx-1; i++)
    {
        for (int j = 1; j < ny-1; j++)
        {
            // Update the value at this point using the SOR formula
            grid[i][j] = (1 - relaxation_param) * grid[i][j] +
                         relaxation_param * (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] - rhs[i][j]) / 4.0;
        }
    }
}
