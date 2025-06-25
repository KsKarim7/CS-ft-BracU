#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    string inp;
    cin >> inp;
    string to_find = "hello";
    int count = 0, pas = 0;
    bool flag = false;
    for (int i = 0; i < inp.size(); i++)
    {
        if (inp[i] == to_find[count])
        {
            count++;
            // pas++;
        }
        // else
        // {
        //     pas++;
        // }
    }
    if (count == 5)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}