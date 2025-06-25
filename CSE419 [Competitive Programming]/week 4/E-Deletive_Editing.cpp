#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        map<char, int> mp;
        string s, t, temp = "";
        cin >> s >> t;
        for (int i = 0; i < t.size(); i++)
        {
            mp[t[i]]++;
        }
        for (int i = s.size() - 1; i > -1; i--)
        {
            if (mp[s[i]] > 0)
            {
                temp += s[i];
                mp[s[i]]--;
                // cout << i << endl;
            }
        }
        reverse(temp.begin(), temp.end());
        if (temp == t)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    // for (auto &pair : mp)
    // {
    //     cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    // }
    return 0;
}