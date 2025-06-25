#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> dict;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (dict.find(s) != dict.end())
        {
            cout << s << dict[s] << '\n';
            dict[s]++;
        }
        else
        {
            dict[s]++;
            cout << "OK" << '\n';
        }
    }
    // for (auto pair : dict)
    // {
    //     cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    // }
    // if (dict.find("grape") != dict.end())
    // {
    //     cout << "Grape is in the dictionary!" << endl;
    // }
    // else
    // {
    //     cout << "Grape is not in the dictionary." << endl;
    // }

    return 0;
}