#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test[2][3][4] = {
        // { {3, 4, }, {0, -3, }, {23, 12, } },
        // { {13, 4, }, {5, 9, }, {5, 1, } }
        {{3,
          4},
         {0,
          -3},
         {23,
          12}},
        {{13,
          4},
         {5,
          9},
         {5,
          1}}};

    // Calculate prefix sum for each 2D slice
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 1; k < 4; k++)
            {
                test[i][j][k] += test[i][j][k - 1];
            }
        }
    }
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {

    //         for (int k = 1; k < 2; k++)
    //         {
    //             cout << test[i][j][k] << " ";
    //             ;
    //         }
    //     }
    //     cout << endl;
    // }

    // Calculate prefix sum for each 1D row
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                test[i][j][k] += test[i][j - 1][k];
            }
        }
    }

    // Calculate prefix sum for each element in the 3D array
    for (int i = 1; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                test[i][j][k] += test[i - 1][j][k];
            }
        }
    }

    // Print the prefix sum array
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                std::cout << test[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}