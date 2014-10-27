#ifndef density_solver_hpp
#define density_solver_hpp

#include <vector>

#include "knapsack.hpp"

std::vector<knapsack_object> density_solver(
		std::vector<knapsack_object> objects,
		size_t capacity);

#endif
