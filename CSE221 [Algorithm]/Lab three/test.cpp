#include <bits/stdc++.h>
using namespace std;

using namespace std;

int maxCrossSum(vector<int> &A, int low, int mid, int high)
{
    int leftMax = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += A[i];
        cout << A[i] << endl;
        cout << endl;
        leftMax = max(leftMax, sum);
    }

    int rightMax = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += A[i] * A[i];
        rightMax = max(rightMax, sum);
    }

    return leftMax + rightMax;
}
int maxSumHelper(vector<int> &A, int low, int high)
{
    if (low == high)
    {
        return A[low] * A[low];
    }

    int mid = (low + high) / 2;
    int leftMax = maxSumHelper(A, low, mid);
    int rightMax = maxSumHelper(A, mid + 1, high);
    int crossMax = maxCrossSum(A, low, mid, high);

    return max(max(leftMax, rightMax), crossMax);
}

int maxSum(vector<int> &A)
{
    int N = A.size();
    return maxSumHelper(A, 0, N - 1);
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cout << maxSum(A) << endl;
    return 0;
}