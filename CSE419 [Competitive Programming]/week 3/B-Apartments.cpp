#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int app[n] = {90, 41, 20, 39, 49, 21, 35, 31, 74, 86};
    int ap[m] = {14, 24, 24, 7, 82, 85, 82, 4, 60, 95};
    // map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        app[i] = x;
        // mp[x]++;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &ap[i]);
    }
    sort(app, app + n);
    sort(ap, ap + m);
    int i = 0, j = 0, count = 0;
    while (i < n && j < m)
    {
        if (ap[j] <= app[i] + k && ap[j] >= app[i] - k)
        {
            i++;
            j++;
            count++;
        }
        else if ((app[i] + k) < ap[j])
        {
            i++;
        }
        else if ((app[i] - k) > ap[j])
        {
            j++;
        }
    }
    printf("%d\n", count);

    // int count = 0;
    // map<int, int>::iterator it = mp.begin();

    // int i = 0;
    // while (it != mp.end())
    // {
    //     if (i == m)
    //         break;
    //     if (it->first <= ap[i] + k && it->first >= ap[i] - k)
    //     {
    //         count++;
    //     }

    //     i++;
    //     it++;
    //     // printf("%d\n", count);
    // }
    // while (it != mp.end())
    // {
    //     cout << "Key: " << it->first
    //          << ", Value: " << it->second << endl;
    //     it++;
    // }
    // for (int i = 0; i < m; i++)

    return 0;
}