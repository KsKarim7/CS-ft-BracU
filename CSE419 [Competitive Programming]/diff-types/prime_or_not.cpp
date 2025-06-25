#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, count = 0;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    // for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++;
            if (n / i != i)
            {
                count++;
            }
        }
        if (count > 2)
        {
            break;
        }
    }
    if (count == 0)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not prime";
    }
    // TC -> O(sqrt(n))

    return 0;
}