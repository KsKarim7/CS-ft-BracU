#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt_0 = 0;
        int cnt_1 = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                cnt_0++;
            }
            else
            {
                cnt_1++;
            }
        }
        for (char c : s)
        {
            if (c == '0')
            {
                if (cnt_1 - 1 == -1)
                {
                    break;
                }
                cnt_1--;
            }
            else
            {
                if (cnt_0 - 1 == -1)
                {
                    break;
                }
                cnt_0--;
            }
        }
        cout << cnt_1 + cnt_0 << endl;
    }
    return 0;
}