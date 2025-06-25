#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        if (v[0] != 1)
            printf("%s\n", "NO");
        else
            printf("%s\n", "YES");
    }

    return 0;
}