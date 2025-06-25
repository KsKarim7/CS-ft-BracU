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
        int arr[n];
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {

            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr, arr + n);
        if (k == 1)
        {
            cout << max(sum - (arr[0] + arr[1]), sum - arr[n - 1]) << endl;
        }
        else
        {
            sum = 0;

            long long psa[n + 1], ssa[n + 1];
            psa[0] = 0;
            ssa[0] = 0;

            for (int i = 0; i < n; i++)
            {
                sum += arr[i];
                psa[i + 1] = sum;
            }

            reverse(arr, arr + n);
            sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += arr[i];
                ssa[i + 1] = sum;
            }

            long long res = 0;

            for (int i = 0; i <= k; i++)
            {
                res = max(res, sum - (psa[(i * 2)] + ssa[(k - i)]));
            }
            cout << res << endl;
        }
    }
    return 0;
}