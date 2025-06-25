#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n], sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        arr[i] = m;
        sum += m;
    }
    sort(arr, arr + n);
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // if (res + arr[i] <= sum)
        // {
        //     count++;
        //     res += arr[i];
        //     sum -= arr[i];
        if (res > sum)
        {
            break;
        }
        else
        {
            count++;
            res += arr[i];
            sum -= arr[i];
        }
    };
    std::cout << count << endl;
    return 0;
}