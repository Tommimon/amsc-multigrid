#ifndef AMSC_MULTIGRID_MULTIGRID_HPP
#define AMSC_MULTIGRID_MULTIGRID_HPP

void multigrid(std::vector<std::vector<double>>& grid,
               const std::vector<std::vector<double>>& rhs,
               const std::function<void(std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&, double)>& solver,
               int num_levels,
               double relaxation_param);

#endif //AMSC_MULTIGRID_MULTIGRID_HPP
