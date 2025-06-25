#include <bits/stdc++.h>
using namespace std;

int main()
{
    int inp;
    cin >> inp;
    int i = 5;
    int count = 0;
    while (inp / i >= 1)
    {
        count += inp / i;
        i *= 5;
    }
    cout << count << endl;

    // cout << inp / i << endl;

    return 0;
}
