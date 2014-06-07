#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


#include "knapsack.hpp"
#include "density_solver.hpp"
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
void run_simple_testcases(vector<string> names);
void run_random_testcases(vector<string> names);


int main(int /*argc*/, char** /*argv*/)
{
    srand(time(NULL));
	vector<string> names = {"density", "gloop"};
    // run_simple_testcases(names);
    run_random_testcases(names);
	return 0;
}

void run_simple_testcases(vector<string> names)
{
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
}

void run_random_testcases(vector<string> names)
{
    vector<knapsack_object> objects(10);
    for(size_t i = 0; i < objects.size(); ++i)
    {
        objects[i].weight = rand() % 10 + 1;
        objects[i].value = rand() % 10 + 1;
        objects[i].id = i;
    }
    size_t capacity = 15;
    for(string name : names)
    {   
        auto o(objects);
        test_solution(o, capacity, name);
    }
}

void test_solution(
		vector<knapsack_object> objects, 
		size_t capacity, 
		string name)
{
	vector<knapsack_object> solution;

	if(name == "density")
	{
		solution = density_solver(objects, capacity);
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
