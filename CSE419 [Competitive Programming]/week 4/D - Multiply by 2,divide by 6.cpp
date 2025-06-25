#include <bits/stdc++.h>
using namespace std;

void see_if(long long x, long long &count_2, long long &count_3)
{
    while (!(x % 2))
    {
        x /= 2;
        count_2++;
    }
    while (!(x % 3))
    {
        x /= 3;
        count_3++;
    }
    if (x != 1 || count_2 > count_3)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (count_3 - count_2) + count_3 << endl;
    }
}

int main()
{
    int n;

    cin >> n;
    while (n--)
    {
        long long x;
        cin >> x;
        long long count_2 = 0, count_3 = 0;
        see_if(x, count_2, count_3);
    }
    return 0;
}