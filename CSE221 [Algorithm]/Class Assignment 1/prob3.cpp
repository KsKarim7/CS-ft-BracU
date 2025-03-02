#include <bits/stdc++.h>
using namespace std;

int findMaxWave(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1]))
        {
            return arr[mid];
        }
        else if (mid > 0 && arr[mid] < arr[mid - 1])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1; // not found
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

    cout << findMaxWave(arr, n) << endl;
    return 0;
}

// b)The time complexity of this algorithm is O(log N), where N is the size of the array. This is because we're using a binary search approach, which reduces the search space by half in each iteration.

// The key insight here is that we can use a single binary search to find the peak element, which is the maximum number in the sequence. By checking the middle element and its neighbors, we can determine whether we're in the ascending or descending part of the sequence and adjust our search accordingly.
