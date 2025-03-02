#include <fstream>
#include <vector>
#include <map>
#include <iostream>

bool cycle(std::map<int, std::vector<int>> &graph, int node, std::vector<int> &color_lst, std::vector<bool> &dfs_lst)
{
    if (graph[node].empty())
    {
        dfs_lst[node] = false;
        return false;
    }
    if (dfs_lst[node] && color_lst[node] == 1)
    {
        return true;
    }

    color_lst[node] = 1;
    dfs_lst[node] = true;

    for (int val : graph[node])
    {
        bool cycle_bool = cycle(graph, val, color_lst, dfs_lst);
        if (cycle_bool)
        {
            return cycle_bool;
        }
    }

    dfs_lst[node] = false;
    return false;
}

void traversal()
{
    for (int n = 1; n < 6; n++)
    {
        std::ifstream f1("input4_" + std::to_string(n) + ".txt");
        int vertices, edges;
        f1 >> vertices >> edges;
        std::map<int, std::vector<int>> graph;
        for (int i = 1; i <= vertices; i++)
        {
            graph[i] = {};
        }
        std::vector<int> color_lst(vertices + 1, 0);
        std::vector<bool> dfs_lst(vertices + 1, false);
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            f1 >> u >> v;
            graph[u].push_back(v);
        }
        f1.close();

        bool cycle_bool = cycle(graph, 1, color_lst, dfs_lst);

        std::ofstream f2("output4_" + std::to_string(n) + ".txt");
        if (cycle_bool)
        {
            f2 << "YES";
        }
        else
        {
            f2 << "NO";
        }
        f2.close();
    }
}

int main()
{
    traversal();
    return 0;
}