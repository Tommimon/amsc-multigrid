#ifndef AMSC_MULTIGRID_SOLVERS_HPP
#define AMSC_MULTIGRID_SOLVERS_HPP

void jacobi(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double _relaxation_param, int my_rank, int num_procs);
void gauss_seidel(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double _relaxation_param, int my_rank, int num_procs);
void sor(std::vector<std::vector<double>>& grid, const std::vector<std::vector<double>>& rhs, double relaxation_param, int my_rank, int num_procs);

#endif //AMSC_MULTIGRID_SOLVERS_HPP
