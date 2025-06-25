#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, a, b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> a >> b;
        if (n == a && n == b)
        {
            cout << "YES" << "\n";
        }
        else
        {
            n -= a + b;
            if (n > 1)
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
    }
    return 0;
}