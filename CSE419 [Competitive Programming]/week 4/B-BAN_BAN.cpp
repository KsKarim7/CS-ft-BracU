#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    Faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string ban = "";
        for (int i = 0; i < n; i++)
        {
            ban += "BAN";
        }
        vector<pair<int, int>> pr;
        int i = 1, j = ban.size() - 1;
        while (i < j)
        {
            pr.push_back({i + 1, j + 1});
            i += 3;
            j -= 3;
        }
        cout << pr.size() << endl;
        for (auto p : pr)
        {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}