#include <iostream>
#include "knapsack_solver.hpp"

using std::vector;
using std::cout;
using std::endl;

int main(int /*argc*/, char** /*argv*/)
{
    // first simple test case
    std::vector<size_t> weights { 1,2,3,4,5,6 };
    std::vector<size_t> values {0,1,2,3,4,5};
    
    std::vector<bool> solution = knapsack_solver(weights, values, 15);

    size_t total_possible = 0;
    size_t score = 0;

    for(size_t i = 0; i < solution.size(); ++i)
    {
        total_possible += values[i];
        if(!solution[i])
        {
            continue;
        }
            
        score += values[i];
        cout << i 
             << " - weight: " 
             << weights[i]
             << " - value: "
             << values[i]
             << endl;
    }

    cout << "Total possible: " << total_possible << endl;
    cout << "Score: " << score << endl;

    return 0;
}