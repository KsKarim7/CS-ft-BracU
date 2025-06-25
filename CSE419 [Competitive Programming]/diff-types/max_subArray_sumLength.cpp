#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumLength(int arr[], int n)
{
    int max_current = arr[0];
    int max_global = arr[0];
    int start = 0;
    int end = 0;
    int temp_start = 0;

    for (int i = 1; i < n; i++)
    {
        if (max_current < 0)
        {
            max_current = 0;
            temp_start = i;
        }
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global)
        {
            max_global = max_current;
            start = temp_start;
            end = i;
        }
    }

    return end - start + 1;
}
int main()
{

    return 0;
}
