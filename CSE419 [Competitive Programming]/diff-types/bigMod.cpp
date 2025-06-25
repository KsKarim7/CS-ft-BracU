#include <bits/stdc++.h>
using namespace std;

// return x^n (mod m)
long long bigMod(long long x, long long n, long long m)
{
    if (n == 0)
        return 1;
    if (n % 2)
    {
        long long y = x * x % m;
        return bigMod(x, n / 2, m);
    }
    else
    {
        long long y = x * x % m;
        long long temp = bigMod(y, (n - 1) / 2, m);
        return temp * x % m;
    }
}

int main()
{
    long long mod = 61, a = 7, b = 1;

    b = bigMod(a, mod - 2, mod);

    return 0;
}