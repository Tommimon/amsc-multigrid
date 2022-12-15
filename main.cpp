#include <iostream>
#include <vector>

// Function for performing Jacobi iteration on a grid of values
void jacobi(std::vector<std::vector<double>>& grid,
            const std::vector<std::vector<double>>& rhs,
            double relaxation_param)
{
    // Get the dimensions of the grid
    int nx = grid.size();
    int ny = grid[0].size();

    // Temporary grid for storing updated values
    std::vector<std::vector<double>> temp(nx, std::vector<double>(ny));

    // Perform Jacobi iteration on each point in the grid
    for (int i = 1; i < nx-1; i++)
    {
        for (int j = 1; j < ny-1; j++)
        {
            // Update the value at this point using the Jacobi formula
            temp[i][j] = (1 - relaxation_param) * grid[i][j] +
                         relaxation_param * (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] - rhs[i][j]) / 4.0;
        }
    }

    // Update the grid with the new values
    grid = temp;
}

// Function for performing multigrid on a grid of values
void multigrid(std::vector<std::vector<double>>& grid,
               const std::vector<std::vector<double>>& rhs,
               int num_levels,
               double relaxation_param)
{
    // If we are at the coarsest level, just perform Jacobi iteration
    if (num_levels == 1)
    {
        jacobi(grid, rhs, relaxation_param);
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
    multigrid(coarse_grid, rhs, num_levels-1, relaxation_param);

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

    // Perform Jacobi iteration on the original grid
    jacobi(grid, rhs, relaxation_param);
}

int main()
{
    // Set up the grid of values and the right-hand side of the equation
    std::vector<std::vector<double>> grid = {{0, 0, 0, 0, 0},
                                             {0, 1, 2, 3, 0},
                                             {0, 4, 5, 6, 0},
                                             {0, 7, 8, 9, 0},
                                             {0, 0, 0, 0, 0}};
    std::vector<std::vector<double>> rhs = {{0, 0, 0, 0, 0},
                                            {0, 1, 1, 1, 0},
                                            {0, 1, 1, 1, 0},
                                            {0, 1, 1, 1, 0},
                                            {0, 0, 0, 0, 0}};

    // Set the number of multigrid levels and the relaxation parameter
    int num_levels = 2;
    double relaxation_param = 0.5;

    // Perform multigrid on the grid
    multigrid(grid, rhs, num_levels, relaxation_param);

    // Print the final grid of values
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
