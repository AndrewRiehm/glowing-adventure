
/** Solver named after Augustus Gloop.
    (the fat kid from Willy Wonka).

		Because it's greedy... too greedy...
**/

#ifndef gloop_solver_hpp
#define gloop_solver_hpp

#include <vector>

std::vector<bool> gloop_solver(
		std::vector<size_t> values,
		std::vector<size_t> weights,
		size_t capacity);

#endif
