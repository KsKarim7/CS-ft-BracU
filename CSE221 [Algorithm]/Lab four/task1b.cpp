#include <fstream>
#include <vector>
#include <map>
#include <iostream>

void adj_list()
{
    for (int n = 1; n < 4; n++)
    {
        std::ifstream f1("input1b_" + std::to_string(n) + ".txt");
        int vertices, edges;
        f1 >> vertices >> edges;
        std::map<int, std::vector<std::pair<int, int>>> diction;
        for (int i = 0; i < edges; i++)
        {
            int u, v, w;
            f1 >> u >> v >> w;
            diction[u].push_back(std::make_pair(v, w));
        }
        f1.close();
        std::ofstream f2("output1b_" + std::to_string(n) + ".txt");
        for (auto &pair : diction)
        {
            f2 << pair.first << " : ";
            for (auto &edge : pair.second)
            {
                f2 << "(" << edge.first << ", " << edge.second << ") ";
            }
            f2 << "\n";
        }
        f2.close();
    }
}

int main()
{
    adj_list();
    return 0;
}