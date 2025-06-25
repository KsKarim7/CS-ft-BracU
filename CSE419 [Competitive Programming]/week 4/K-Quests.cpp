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
        vector<int> arr(n), sum(n), mx(n), exp(n);
        cin >> arr[0];
        sum[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        cin >> exp[0];
        mx[0] = exp[0];
        for (int i = 1; i < n; i++)
        {
            cin >> exp[i];
            mx[i] = max(mx[i - 1], exp[i]);
        }
        k--;
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            /* code */
            res = max(res, sum[i] + (k - i) * mx[i]);
            if (i == k)
            {
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}