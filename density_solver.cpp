#include <algorithm>

#include "density_solver.hpp"

using std::vector;
using std::sort;

bool compare_by_value_density(
        knapsack_object a,
        knapsack_object b)
{
    if(b.weight == 0 || a.weight == 0)
    {
        throw "Zero weights are not allowed.";
    }
    auto b_density = (float)b.value / b.weight;
    auto a_density = (float)a.value / a.weight;
    return a_density > b_density;
}

vector<knapsack_object> density_solver(
        vector<knapsack_object> objects,
        size_t capacity)
{
    vector<knapsack_object> solution;

    // First make all the high value density stuff show up first
    sort(objects.begin(), objects.end(), compare_by_value_density);

    // Then grab as much as you can in order
    size_t weight_so_far = 0;
    for(auto ob : objects)
    {
        if(weight_so_far + ob.weight <= capacity)
        {   
            solution.push_back(ob);
            weight_so_far += ob.weight;
        }
    }

    return solution;
}
