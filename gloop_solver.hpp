
/** Solver named after Augustus Gloop.
    (the fat kid from Willy Wonka).

		Because it's greedy... too greedy...
**/

#ifndef gloop_solver_hpp
#define gloop_solver_hpp

#include <vector>

#include "knapsack.hpp"

std::vector<knapsack_object> gloop_solver(
		std::vector<knapsack_object> objects,
		size_t capacity);

#endif
