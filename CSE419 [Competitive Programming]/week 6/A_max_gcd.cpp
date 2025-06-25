#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int maxGCD(vector<int> &nums)
{
    int max_gcd = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int gcd_val = gcd(nums[i], nums[j]);
            max_gcd = max(max_gcd, gcd_val);
        }
    }
    return max_gcd;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        vector<int> nums(M);
        for (int j = 0; j < M; j++)
        {
            cin >> nums[j];
        }
        cout << maxGCD(nums) << endl;
    }
    return 0;
}