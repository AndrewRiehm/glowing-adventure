#include <iostream>
#include <string>

#include "knapsack.hpp"
#include "knapsack_solver.hpp"
#include "gloop_solver.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::string;

void test_solution(
		vector<knapsack_object> objects, 
		size_t capacity, 
		string name
		);

int main(int /*argc*/, char** /*argv*/)
{
	vector<string> names = {"knapsack", "gloop"};

	for(string name : names)
	{
		// first simple test case
		vector<knapsack_object> objects(10);
		for(size_t i = 0; i < objects.size(); ++i)
		{
			objects[i].weight = i + 1;
			objects[i].value = i;
			objects[i].id = i;
		}
		size_t capacity = 15;

		test_solution(objects, capacity, name);
	}

	return 0;
}

void test_solution(
		vector<knapsack_object> objects, 
		size_t capacity, 
		string name)
{
	vector<knapsack_object> solution;

	if(name == "knapsack")
	{
		solution = knapsack_solver(objects, capacity);
	}
	else if(name == "gloop")
	{
		solution = gloop_solver(objects, capacity);
	}
	else
	{
		throw "Unknown solver name";
	}

	cout << "-=-=-=-= Executing " << name << " -=-=-=-=-" << endl;

	size_t total_possible = 0;
	size_t score = 0;

	for(size_t i = 0; i < objects.size(); ++i)
	{
		total_possible += objects[i].value;
	}

	for(size_t i = 0; i < solution.size(); ++i)
	{
		score += solution[i].value;
		cout << "id: " 
			<< solution[i].id
			<< " - weight: " 
			<< solution[i].weight
			<< " - value: "
			<< solution[i].value
			<< endl;
	}

	cout << "Total possible: " << total_possible << endl;
	cout << "Score: " << score << endl;
}
