#include <vector>
#include <functional>

// Function for performing multigrid on a grid of values
void multigrid(std::vector<std::vector<double>>& grid,
               const std::vector<std::vector<double>>& rhs,
               const std::function<void(std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&, double, int, int)>& solver,
               int num_levels,
               double relaxation_param,
               int _my_rank,
               int _num_procs)
{
    // If we are at the coarsest level, just perform Solver iteration
    if (num_levels == 1)
    {
        solver(grid, rhs, relaxation_param, 0, 0);
        return;
    }

    // Get the dimensions of the grid
    int nx = grid.size();
    int ny = grid[0].size();

    // Temporary grids for storing residuals and error
    std::vector<std::vector<double>> residual(nx, std::vector<double>(ny));
    std::vector<std::vector<double>> error(nx, std::vector<double>(ny));

    // Compute the residual on this grid
    for (int i = 1; i < nx-1; i++)
    {
        for (int j = 1; j < ny-1; j++)
        {
            residual[i][j] = rhs[i][j] - (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] - 4 * grid[i][j]);
        }
    }

    // Restrict the residual to the coarser grid
    std::vector<std::vector<double>> coarse_grid(nx/2, std::vector<double>(ny/2));
    for (int i = 0; i < nx/2; i++)
    {
        for (int j = 0; j < ny/2; j++)
        {
            coarse_grid[i][j] = residual[2*i][2*j];
        }
    }

    // Perform multigrid on the coarser grid
    multigrid(coarse_grid, rhs, solver, num_levels-1, relaxation_param, 0, 0);

    // Interpolate the error to the finer grid
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            error[i][j] = coarse_grid[i/2][j/2];
        }
    }

    // Add the error to the original grid
    for (int i = 1; i < nx-1; i++)
    {
        for (int j = 1; j < ny-1; j++)
        {
            grid[i][j] += error[i][j];
        }
    }

    // Perform Solver iteration on the original grid
    solver(grid, rhs, relaxation_param, 0, 0);
}
