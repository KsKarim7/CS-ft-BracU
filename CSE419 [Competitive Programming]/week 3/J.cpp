#include <bits/stdc++.h>
using namespace std;

template <typename T>
T input()
{
    T x;
    cin >> x;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    auto t = input<int>();
    while (t--)
    {
        long long a = input<int>();
        long long b = input<int>();
        long long n = input<int>();

        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long tictic = b;
        for (auto time : arr)
        {
            tictic += min(time + 1, a) - 1;
        }
        cout << tictic << "\n";
    }
    return 0;
}