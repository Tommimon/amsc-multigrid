#include <vector>

void gauss_seidel(std::vector<std::vector<double>>& grid,
                      const std::vector<std::vector<double>>& rhs,
                      double relaxation_param)
{
    // Get the dimensions of the grid
    int nx = grid.size();
    int ny = grid[0].size();

    // Perform Gauss-Seidel iteration on each point in the grid
    for (int sum = 2; sum < ny + nx - 3; sum++)
    {
        int startI = 1 > sum-ny+2 ? 1 : sum-ny+2;
        int endI = nx-1 < sum ? nx-1 : sum;
#pragma omp parallel for
        for (int i = startI; i < endI; i++)
        {
            int j = sum - i;
            // Update the value at this point using the Gauss-Seidel formula
            grid[i][j] = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] - rhs[i][j]) / 4.0;
        }
    }
}
