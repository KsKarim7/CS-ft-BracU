#include <bits/stdc++.h>
using namespace std;

// Kadane's algorithm implementation

// A problem related to the following problem : https://bit.ly/3QhMl6j

int maxSubArraySum(vector<int> &arr)
{
    int max_current = 0;
    int max_global = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        max_current = max(arr[i], max_current + arr[i]);

        if (max_current < 0)
        {
            max_current = 0;
            continue; // Skip negative numbers in the current subarray, since they won't contribute to the maximum sum.
            // Note: This implementation assumes that the array can contain negative numbers. If you want to handle negative numbers differently,
            // you can remove this continue statement and add a condition to check if max_current is still positive before updating max_global.
        }

        max_global = max(max_current, max_global);
        // if (max_current > max_global)
        // {
        //     max_global = max_current;
        // }
    }

    return max_global;
}

int main()
{
    vector<int> arr = {2, 3, -4, -1, 3, 10, -8};
    int max_sum = maxSubArraySum(arr);
    cout << "Maximum sum of a subarray: " << max_sum << endl;
    return 0;
}