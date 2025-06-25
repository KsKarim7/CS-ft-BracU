#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ii;
    string s;
    bool flag = false;
    cin >> n;
    cin >> s;
    for (int i = 1; i < n; i++)
    {
        /* code */
        if (s[i - 1] > s[i])
        {
            flag = true;
            ii = i;
            break;
        }
    }
    if (flag == false)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << ii << " " << ii + 1 << endl;
    }

    return 0;
}