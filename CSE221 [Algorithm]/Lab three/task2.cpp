#include <bits/stdc++.h>
using namespace std;

void maxValue(int arr[], int l, int r, int &mx)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    if (arr[mid] > mx)
    {
        mx = arr[mid];
    }
    maxValue(arr, l, mid - 1, mx);
    maxValue(arr, mid + 1, r, mx);
    // cout << mx << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mx = INT_MIN;
    maxValue(arr, 0, n - 1, mx);
    cout << mx << endl;

    return 0;
}