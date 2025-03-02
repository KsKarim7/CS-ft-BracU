#include <fstream>
#include <vector>
#include <iostream>

void adj_matrix()
{
    for (int n = 1; n < 3; n++)
    {
        std::ifstream f1("input1a_" + std::to_string(n) + ".txt");
        int vertices, edges;
        f1 >> vertices >> edges;
        std::vector<std::vector<int>> matrix(vertices + 1, std::vector<int>(vertices + 1, 0));
        for (int i = 0; i < edges; i++)
        {
            int u, v, w;
            f1 >> u >> v >> w;
            matrix[u][v] = w;
        }
        f1.close();
        std::ofstream f2("output1a_" + std::to_string(n) + ".txt");
        for (int i = 0; i <= vertices; i++)
        {
            for (int j = 0; j <= vertices; j++)
            {
                f2 << matrix[i][j] << " ";
            }
            f2 << "\n";
        }
        f2.close();
    }
}

int main()
{
    adj_matrix();
    return 0;
}