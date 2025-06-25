#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string b;
        cin >> b;
        int n = b.size();
        if (b[0] != b.back())
        {
            b[0] = b.back();
        }
        cout << b << endl;
    }
    return 0;
}
