#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include "solvers.hpp"

int main(int argc, char *argv[])
{
    // Read arguments and set execution parameters
    int size = 40;
    std::function<void(std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&, double)> solver = jacobi;
    if (argc > 1)
        size = atoi(argv[1]);
    if (argc > 2) {
        if (argv[2][0] == 'j')
            solver = jacobi;
        if (argv[2][0] == 'g')
            solver = gauss_seidel;
        if (argv[2][0] == 's')
            solver = sor;
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
    double relaxation_param = 0.9;

    // Perform solver on the grid
    int i = 0;
    double r = 0;
    double t = 1e-9;
    while (i == 0 || std::isgreater(r, t)) {
        solver(grid, rhs, relaxation_param);
        r = residual(grid, rhs);
        //std::cout << " " << r << std::endl;
        i++;
    }

    // Print the final grid of values
    /*for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }*/


    std::cout << i << std::endl;

    return 0;
}
