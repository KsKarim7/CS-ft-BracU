#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> bfs(vector<vector<int>> &graph, vector<int> &inDegree)
{
    queue<int> q;
    vector<int> order;

    for (int i = 1; i <= graph.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : graph[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return order;
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