#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool flag = true;
        for (int i = 0; i < s2.size(); i++)
        {
            if (s1[i] != s2[i] or s1.size() != s2.size())
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            cout << "False" << endl;
        }
        else
        {
            cout << "True" << endl;
        }
    }
    return 0;
}