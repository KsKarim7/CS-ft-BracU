#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k = 3;
    int n = 7;
    int sum = 0;
    vector<int> arr = {2, 3, -4, -1, 3, 10, -8};
    vector<int> pref(n, 0);
    pref[0] = arr[0];
    // sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
    }
    for (int i = k + 1; i <= n; i++)
    {
        sum += arr[i];
        sum -= arr[i - k];
    }
    cout << "Sum of the subarray with length " << k << ": " << sum << endl;
    return 0;
}