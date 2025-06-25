#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (auto &i : arr)
    {
        cin >> i;
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);
    int count = 0, i = 0, wins = 0;
    while (i < n && count <= n)
    {
        int mx = arr[i];
        i++;
        int x = ceil((d + 1) / (mx * 1.0));
        count += x;
        if (count <= n)
        {
            wins++;
        }
    }
    cout << wins;
    return 0;
}