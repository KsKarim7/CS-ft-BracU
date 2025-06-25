#include <bits/stdc++.h>
using namespace std;

// shortcuts

#define ll long long
#define vll vector<ll>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ll a, b, xk, yk, xq, yq;

        scanf("%d %d %d %d %d %d", &a, &b, &xk, &yk, &xq, &yq);
        // vll dx = {a, b, a, b, -a, -b, -a, -b};
        // vll dy = {b, a, -b, -a, -b, a, -b, -a};

        vll dx = {-a, -a, a, a, b, b, -b, -b};
        vll dy = {-b, b, b, -b, a, -a, a, -a};

        set<pair<ll, ll>> dirK;
        set<pair<ll, ll>> dirQ;

        for (int i = 0; i < 8; i++)
        {
            /* code */
            dirK.insert({xk + dx[i], yk + dy[i]});
            dirQ.insert({xq + dx[i], yq + dy[i]});
        }

        int res = 0;

        for (auto i : dirK)
        {
            if (dirQ.find(i) != dirQ.end())
            {
                res++;
            }
        }

        printf("%d\n", res);
    }
    return 0;
}
