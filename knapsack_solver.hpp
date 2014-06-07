#ifndef knapsack_solver_hpp
#define knapsack_solver_hpp

#include <vector>

std::vector<bool> knapsack_solver(std::vector<size_t> values,
                                        std::vector<size_t> weights,
                                        size_t capacity);

#endif