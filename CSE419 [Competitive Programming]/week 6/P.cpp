#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_expo(ll b, ll p, ll m)
{
    ll result = 1;
    b = b % m;
    while (p > 0)
    {

        if (p % 2 == 1)
        {
            result = (result * b) % m;
        }
        p = p / 2;
        b = (b * b) % m;
    }
    return result;
}

int main()
{
    ll b, p, m;
    while (cin >> b >> p >> m)
    {
        cout << mod_expo(b, p, m) << endl;
    }

    return 0;
}
