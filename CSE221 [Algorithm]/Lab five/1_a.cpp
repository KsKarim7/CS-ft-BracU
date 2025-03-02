#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];

bool isCycle(int u, int p, bool visit[])
{
    visit[u] = true;
    bool cycle = false;
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (visit[v])
        {
            return true;
        }
        cycle |= isCycle(v, u, visit);
    }
    return cycle;
}

void dfs(bool visited[], int res[], int node)
{
    visited[node] = true;
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(visited, res, neighbour);
        }
    }
    res[++res[0]] = node;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool visit[n];
    if (isCycle(1, -1, visit))
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        // dfs()
        cout << "Hala" << endl;
        bool visited[n];
        int res[n];
        for (int i = 0; i < n + 1; i++)
        {
            if (!visited[i])
            {
                dfs(visited, res, i);
            }
        }
        for (int i : res)
        {
            cout << i << " ";
        }
    }

    return 0;
}