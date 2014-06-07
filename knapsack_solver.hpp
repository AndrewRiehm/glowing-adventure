#ifndef knapsack_solver_hpp
#define knapsack_solver_hpp

#include <vector>

#include "knapsack.hpp"

std::vector<knapsack_object> knapsack_solver(
		std::vector<knapsack_object> objects,
		size_t capacity);

#endif
