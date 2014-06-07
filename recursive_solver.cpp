
#include <algorithm>

#include "recursive_solver.hpp"

using std::vector;
using std::sort;

bool compare_by_value(
		knapsack_object a,
		knapsack_object b)
{
	return a.value > b.value;
}

vector<knapsack_object> recursive_solver(
		vector<knapsack_object> objects,
		size_t capacity)
{
	vector<knapsack_object> solution;

	// First make all the high-value stuff show up first
	sort(objects.begin(), objects.end(), compare_by_value);

	// Then grab as much as you can in order
	// (GLOOP!)
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


