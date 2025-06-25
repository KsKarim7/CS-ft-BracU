#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int count_0 = count(s.begin(), s.end(), '0');
        int count_1 = count(s.begin(), s.end(), '1');

        if (min(count_0, count_1) % 2 == 1)
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NET" << endl;
        }
    }

    return 0;
}
