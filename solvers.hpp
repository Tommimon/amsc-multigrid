#ifndef AMSC_MULTIGRID_SOLVERS_HPP
#define AMSC_MULTIGRID_SOLVERS_HPP

void jacobi(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double _relaxation_param);
void gauss_seidel(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double _relaxation_param);
void sor(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double relaxation_param);

#endif //AMSC_MULTIGRID_SOLVERS_HPP
