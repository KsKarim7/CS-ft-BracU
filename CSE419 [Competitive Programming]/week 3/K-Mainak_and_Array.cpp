#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        // int mx = INT_MIN;
        // int mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            // mx = max(mx, a[i]);
            // mn = min(mn, a[i]);
        }

        // cout << (mx - mn) << endl;
        int res = arr[n - 1] - arr[0];
        if (n == 1)
        {
            cout << res << endl;
        }
        else
        {

            for (int i = 1; i < n; i++)
            {
                /* code */
                res = max(res, arr[i] - arr[0]);
            }
            for (int i = 0; i < n - 1; i++)
            {
                /* code */
                res = max(res, arr[n - 1] - arr[i]);
            }
            for (int i = 1; i < n; i++)
            {
                /* code */
                res = max(res, arr[i - 1] - arr[i]);
            }
            cout << res << endl;
        }
    }
    return 0;
}