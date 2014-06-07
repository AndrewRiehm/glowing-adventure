#include <iostream>
#include <string>
#include "knapsack_solver.hpp"
#include "gloop_solver.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::string;

void test_solution(
		vector<size_t> weights, 
		vector<size_t> values, 
		size_t capacity, 
		string name
		);

int main(int /*argc*/, char** /*argv*/)
{
	// first simple test case
	vector<size_t> weights { 1,2,3,4,5,6 };
	vector<size_t> values {0,1,2,3,4,5};
	size_t capacity = 15;

	vector<string> names = {"knapsack", "gloop"};

	for(string name : names)
	{
		test_solution(weights, values, capacity, name);
	}

	return 0;
}

void test_solution(
		vector<size_t> weights, 
		vector<size_t> values, 
		size_t capacity, 
		string name)
{
	vector<bool> solution;

	if(name == "knapsack")
	{
		solution = knapsack_solver(weights, values, capacity);
	}
	else if(name == "gloop")
	{
		solution = gloop_solver(weights, values, capacity);
	}
	else
	{
		throw "Unknown solver name";
	}

	cout << "-=-=-=-= Executing " << name << " -=-=-=-=-" << endl;

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
}
