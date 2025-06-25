#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    scanf("%lld", &t);
read:
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        long long arr[n];
        for (long long i = 0; i < n; i++)
            scanf("%lld", &arr[i]);

        sort(arr, arr + n);
        for (long long i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] > 1)
            {
                printf("NO\n");
                goto read;
            }
        }
        printf("YES\n");
    }

    return 0;
}