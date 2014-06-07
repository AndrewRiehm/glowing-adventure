#include <vector>
// assign each worker to a task that it can handle,
// starting with the worker that can handle the least
// number of tasks.
void simple_solver(std::vector<int> workers, std::vector<int> tasks)
{
    std::vector<int> can_solve;
    // initialize the can_solve array to zeros
    for(int i=0; i<workers.size(); i++)
    {
        can_solve[i]=0;
    }
    for(int i = 0; i < tasks.size(); i++)
    {
        for (int j = 0; j < workers.size(); j++)
        {
            if(workers[j] >= tasks[i])
            {
                can_solve[j] += 1;
            }
        }
    }
}

int main(int /*argc*/, char** /*argv*/)
{
    std::vector<int> workers { 1,2,3,4,5,6 };
    std::vector<int> tasks {0,1,2,3,4,5};
    simple_solver(workers, tasks);
    return 0;
}