#include <vector>
#include <functional>

// Function for performing multigrid on a grid of values
void multigrid(std::vector<std::vector<double>>& grid,
               const std::vector<std::vector<double>>& rhs,
               const std::function<void(std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&, double, int, int)>& solver,
               int num_levels,
               double relaxation_param,
               int my_rank,
               int num_procs)
{

}
