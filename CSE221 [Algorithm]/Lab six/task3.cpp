#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9 + 10;

struct Edge
{
    int to, weight;
};

vector<Edge> adj[1001];
vector<int> dist(1001, INF);

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (Edge e : adj[u])
        {
            int v = e.to;
            int w = e.weight;
            if (max(dist[u], w) < dist[v])
            {
                dist[v] = max(dist[u], w);
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(1);

    if (dist[N] == INF)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << dist[N] << endl;
    }

    return 0;
}