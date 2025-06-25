#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    while (true)
    {
        ll n;
        cin >> n;
        if (n < 0ll)
        {
            break;
        }

        for (ll i = 2; i * i <= n; i++)
        {
            cout << "    " << i << endl;
            n /= i;
        }

        if (n > 1)
        {
            cout << "    " << n << endl;
        }

        cout << endl;
    }
    return 0;
}