#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);

        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &vec[i]);
        if (k >= 2)
        {
            printf("%s\n", "YES");
        }
        else if (k == 1 && is_sorted(vec.begin(), vec.end()))
        {
            printf("%s\n", "YES");
        }
        else
        {
            printf("%s\n", "NO");
        }
    }
    return 0;
}