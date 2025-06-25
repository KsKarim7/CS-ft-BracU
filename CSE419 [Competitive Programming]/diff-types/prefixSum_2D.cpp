
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r, c;
    cin >> r >> c;
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }
    int psa[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            psa[i][j] = 0;
        }
    }
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c; j++)
    //     {
    //         cout << psa[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                psa[i][j] = arr[i][j];
            }
            else if (i == 0 && j > 0)
            {
                psa[i][j] = psa[i][j - 1] + arr[i][j];
            }
            else if (j == 0 && i > 0)
            {
                psa[i][j] = psa[i - 1][j] + arr[i][j];
            }
            else
            {

                psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + arr[i][j];
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << psa[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}