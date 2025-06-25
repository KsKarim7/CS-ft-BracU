#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, XOR = 0;
        vector<int> white, gray;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            gray.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            white.push_back(y);
        }

        for (int i = 0; i < n; i++)
        {
            int temp;
            temp = white[i] - gray[i] - 1;
            XOR ^= temp;
        }

        cout << "Case " << i;
        if (XOR != 0)
            cout << ": white ";
        else
            cout << ": black ";
        cout << "wins" << endl;
    }
    return 0;
}