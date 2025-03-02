#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task
{
    int start;
    int end;
};

bool compareTasks(const Task &a, const Task &b)
{
    return a.end < b.end;
}

int maxTasks(vector<Task> &tasks, int M)
{
    sort(tasks.begin(), tasks.end(), compareTasks);

    int maxTasks = 0;
    int endTime = 0;

    for (int i = 0; i < tasks.size() && M > 0; ++i)
    {
        if (tasks[i].start >= endTime)
        {
            ++maxTasks;
            --M;
            endTime = tasks[i].end;
        }
    }

    return maxTasks;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Task> tasks(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> tasks[i].start >> tasks[i].end;
    }

    cout << maxTasks(tasks, M) << endl;

    return 0;
}