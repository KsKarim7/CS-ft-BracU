#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int &i : arr)
    {
        cin >> i;
    }
    // for(int i:arr){
    //     cout<<i<<" ";
    // }
    int l = 0, r = 0, max_len = 0, sum = 0;
    while (r < n)
    {
        sum += arr[r];
        if (sum > k)
        {
            sum -= arr[l];
            l++;
        }
        if (sum <= k)
        {
            max_len = max(max_len, r - l + 1);
        }
        r++;
    }
    cout << max_len;

    return 0;
}