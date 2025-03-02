#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
const int N = 1e3 + 5;
const int INF = 1e9 + 10;

vector<pr> adj[N];
vector<int> dis(N, INF);
vector<bool> visited(N);

void dijkstra(int src)
{
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    dis[src] = 0;
    pq.push({dis[src], src});

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (pr vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v])
                continue;

            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1);

    return 0;
}