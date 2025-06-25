#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, count = 0;
        string s;
        cin >> n;
        cin >> s;

        for (int i = 0; i < n; i++)
        {
            /* code */
            if (s[i] == 'U')
                count++;
        }

        if (count % 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}