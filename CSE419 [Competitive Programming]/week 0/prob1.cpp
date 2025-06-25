#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    long long inp;
    for (int j = 1; j < n; j++)
    {
        cin >> inp;
        arr[inp] = inp;

        // cout << inp;
        // cin >> arr[j];
    }
    // cout << (n * (n + 1)) / 2 - sum << endl;
    for (int k = 1; k <= n; k++)
    {
        if (arr[k] != k)
        {
            cout << k;
        }

        ;
    }
    return 0;
}