#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &nums)
{
    int n = nums.size();
    int res = nums[0];
    vector<int> pref(n, 0);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        /* code */
        pref[i] = pref[i - 1] + nums[i];
    }
    int minimum = min(pref[0], 0);
    for (int i = 0; i < n; i++)
    {
        /* code */
        int sum = pref[i] - minimum;
        minimum = min(minimum, pref[i]);
        res = max(sum, res);
    }
    return res;
}
int main()
{
    vector<int> arr = {2, 3, -4, -1, 3, 10, -8};
    int max_sum = maxSubArraySum(arr);
    cout << "Maximum sum of a subarray: " << max_sum << endl;
    return 0;
}