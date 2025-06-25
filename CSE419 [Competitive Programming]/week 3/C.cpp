#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    int arr[n];
    int l = 0, r = n - 1;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    int gondola = 0;
    while (l <= r)
    {
        if (arr[l] + arr[r] <= x)
        {
            l++;
            r--;
        }
        else
        {
            r--;
        }
        gondola++;
    }
    printf("%d\n", gondola);
    return 0;
}