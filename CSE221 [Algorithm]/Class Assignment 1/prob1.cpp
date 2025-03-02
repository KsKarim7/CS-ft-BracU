#include <bits/stdc++.h>
using namespace std;

int findIndex(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[mid + 1])
        {
            return mid + 1;
        }
        else if (arr[low] <= arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    return low;
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

    cout << findIndex(arr, n) << endl;
    return 0;
}
// a)The algorithm to find the index i is based on the fact that the array is divided into two parts: the first part is in increasing order, and the second part is also in increasing order. We can use a binary search approach to find the index i.

// c) The time complexity of this algorithm is O(log n), where n is the size of the array. This is because we're using a binary search approach, which reduces the search space by half in each iteration.