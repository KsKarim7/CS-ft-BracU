#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge
{
    int to, weight;
};

vector<Edge> adj[10001];
vector<int> distA(10001, INF), distB(10001, INF);

void dijkstra(int start, vector<int> &dist)
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
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
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

    int S, T;
    cin >> S >> T;

    dijkstra(S, distA);
    dijkstra(T, distB);

    int minTime = INF;
    int meetNode = -1;

    for (int i = 1; i <= N; i++)
    {
        if (distA[i] != INF && distB[i] != INF)
        {
            int time = distA[i] + distB[i];
            if (time < minTime)
            {
                minTime = time;
                meetNode = i;
            }
        }
    }

    if (meetNode == -1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << minTime << " " << meetNode << endl;
    }

    return 0;
}