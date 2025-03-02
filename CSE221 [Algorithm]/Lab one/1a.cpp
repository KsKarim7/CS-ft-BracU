#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m % 2 == 0)
        {
            cout << m << " is an Even number" << '\n';
        }
        else
        {
            cout << m << " is an Odd number" << '\n';
        }
    }
    return 0;
}