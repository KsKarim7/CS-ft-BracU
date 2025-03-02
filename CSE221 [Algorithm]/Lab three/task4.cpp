#include <bits/stdc++.h>
using namespace std;

void D_C(int n, int arr[], int low, int high, int &res)
{
    if (low == high)
    {
        return;
    }
    int mid = (low + high) / 2;
    D_C(n, arr, low, mid, res);
    D_C(n, arr, mid + 1, high, res);
    cout << arr[low] << " " << arr[mid] << " " << arr[high] << endl;
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
    int res = 0;
    D_C(n, arr, 0, n - 1, res);
    return 0;
}