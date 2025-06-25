#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long n, k;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        bool ok = false;
        cin >> n >> k;
        if (n % 2 == 0 || n % k == 0)
        {
            ok = true;
            cout << "YES" << "\n";
        }
        else
        {
            long long m = n - 2;
            long long l = n - k;
            if (m % k == 0 || l % 2 == 0)
            {
                ok = true;
                cout << "YES" << "\n";
            }
        }
        if (ok == false)
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}