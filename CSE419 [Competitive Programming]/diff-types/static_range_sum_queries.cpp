// https://cses.fi/problemset/task/1646
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n + 1);
    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    prefix[0] = arr[0];
    for (int i = 1; i <= n; i++)
    {
        prefix[i] += prefix[i - 1] + arr[i];
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        // x--;
        cout << prefix[y] - prefix[x - 1] << endl;
    }
    return 0;
}