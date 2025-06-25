#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        string strr;
        cin >> m;
        cin >> strr;
        bool conse = false;
        int count = 0, continuous = 0;
        for (int j = 0; j < m; j++)
        {
            if (strr[j] == '.')
            {
                count++;
                continuous++;
                if (continuous == 3)
                {
                    conse = true;
                    continuous == 0;
                    count == 0;
                    cout << 2 << endl;
                    break;
                }
            }
            else
            {
                continuous = 0;
            }
        }
        if (conse != true)
        {
            cout << count << endl;
            count == 0;
            conse = false;
        }
    }

    return 0;
}