#ifndef AMSC_MULTIGRID_SOLVERS_HPP
#define AMSC_MULTIGRID_SOLVERS_HPP

void jacobi(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double _relaxation_param);
void gauss_seidel(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double _relaxation_param);
void sor(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double relaxation_param);

double residual(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs) {
    int nx = grid.size();
    int ny = grid[0].size();

    double sum = 0;

    // Compute the residual on this grid
    for (int i = 1; i < nx-1; i++)
    {
        for (int j = 1; j < ny-1; j++)
        {
            sum += rhs[i][j] - (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1] - 4 * grid[i][j]);
        }
    }

    return sum;
}

#endif //AMSC_MULTIGRID_SOLVERS_HPP
