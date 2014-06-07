
/** 
	This solver uses recursion to brute-force all possible combinations.
**/

#ifndef recursive_solver_hpp
#define recursive_solver_hpp

#include <vector>

#include "knapsack.hpp"

std::vector<knapsack_object> recursive_solver(
		std::vector<knapsack_object> objects,
		size_t capacity);

#endif
