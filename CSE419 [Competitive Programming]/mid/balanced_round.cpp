#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, count = 1, res = 1;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] - arr[i - 1] > k)
            {
                count = 1;
            }
            else
            {
                count++;
            }
            res = max(res, count);
        }
        cout << n - res << endl;
    }
}