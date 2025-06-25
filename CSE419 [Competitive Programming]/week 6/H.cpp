#include <bits/stdc++.h>
using namespace std;

int CountDivisors(int n)
{
    int divs = 0, m = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (m % i == 0)
        {
            divs++;
            while (m % i == 0)
                m /= i;
        }
    }
    if (m > 1)
        divs++;
    return divs;
}
int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n)
        {
            cout << n << " : " << CountDivisors(n) << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}