#include <iostream>
#include <vector>
#include <functional>
#include "multigrid.hpp"
#include "solvers.hpp"

int main(int argc, char *argv[])
{
    // Read arguments and set execution parameters
    int size = 40;
    int num_levels = 2;
    std::function<void(std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&, double)> solver = jacobi;
    if (argc > 1)
        size = atoi(argv[1]);
    if (argc > 2)
        num_levels = atoi(argv[2]);
    if (argc > 3) {
        if (argv[3][0] == 'j')
            solver = jacobi;
        if (argv[3][0] == 'g')
            solver = gauss_seidel;
        if (argv[3][0] == 's')
            solver = sor;
    }

    if (size % (1 << (num_levels-1)) != 0) {
        std::cout << "too many grid levels specified for this size, can't reduce grid" << std::endl;
        return 0;
    }

    // Set up the grid of values and the right-hand side of the equation
    std::vector<std::vector<double>> grid(size, std::vector<double>(size));
    std::vector<std::vector<double>> rhs(size, std::vector<double>(size));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (i > 0 && i < size-1 && j > 0 && j < size-1) {
                grid[i][j] = i + j;
                rhs[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
                rhs[i][j] = 0;
            }
        }
    }

    // Set the relaxation parameter
    double relaxation_param = 0.5;
    int nu = 10;

    // Perform multigrid on the grid
    for (int i = 0; i < 10000; ++i) {
        multigrid(grid, rhs, solver, num_levels, relaxation_param, nu);
    }

    // Print the final grid of values
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
