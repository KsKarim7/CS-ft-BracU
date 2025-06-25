#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int count = 0, gold = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= k)
            {
                gold += a[i];
            }
            else if (a[i] == 0 && gold > 0)
            {
                count++;
                gold--;
            }
        }
        cout << count << endl;
    }
    return 0;
}