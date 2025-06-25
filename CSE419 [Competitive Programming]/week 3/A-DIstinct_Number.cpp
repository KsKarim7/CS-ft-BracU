#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> mp;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        mp[x]++;
    }
    printf("%d\n", mp.size());
    return 0;
}