#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> bfs(vector<vector<int>> &graph, vector<int> &inDegree)
{
    queue<vector<int>> q;
    vector<int> order;

    for (int i = 1; i <= graph.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            vector<int> temp = {i};
            q.push(temp);
        }
    }

    while (!q.empty())
    {
        vector<int> path = q.front();
        q.pop();
        int node = path.back();

        for (int neighbor : graph[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                vector<int> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }

    while (!q.empty())
    {
        vector<int> path = q.front();
        q.pop();
        if (path.size() == graph.size())
        {
            return path;
        }
    }

    return {}; // IMPOSSIBLE
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> inDegree(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        inDegree[B]++;
    }

    vector<int> order = bfs(graph, inDegree);

    if (order.empty())
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int node : order)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}