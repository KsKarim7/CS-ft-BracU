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
        string brkts;
        cin >> n >> brkts;
        int op = 0, cl = 0;
        for (char c : brkts)
        {
            if (c == '(')
            {
                op++;
            }
            else
            {
                if (op > 0)
                {
                    op--;
                }
                else
                {
                    cl++;
                }
            }
        }
        cout << cl << endl;
    }

    return 0;
}