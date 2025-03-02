#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            if (mid == 0 || arr[mid - 1] != x)
            {
                return mid;
            }
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // not found
}
int main()
{
    int n, x;
    cin >> n >> x;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << firstOccurrence(arr, n, x) << endl;
    return 0;
}
