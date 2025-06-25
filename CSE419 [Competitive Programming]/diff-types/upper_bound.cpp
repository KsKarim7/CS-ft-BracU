#include <bits/stdc++.h>
using namespace std;

int upper_bound(int arr[], int target, int n)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    cout << upper_bound(arr, target, n);
    return 0;
}