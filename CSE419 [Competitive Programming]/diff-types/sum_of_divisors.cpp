#include <bits/stdc++.h>
using namespace std;

const int N = 10e5 + 5;
int sigma[N];

void sieve(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j += i)
        {
            sigma[j] += i;
        }
    }
}
// O(nlogn)

int main()
{
    int n;
    cin >> n;
    sieve(n);
    for (int i = 1; i < n; i++)
    {
        cout << sigma[i] << endl;
    }

    return 0;
}