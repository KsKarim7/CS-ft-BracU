#include <bits/stdc++.h>
using namespace std;

// int const N = 100000;
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == 0)
        {
            printf("%d\n", a[r + 1]);
            continue;
        }
        printf("%d\n", a[r + 1] - a[l]);
    }
    return 0;
}