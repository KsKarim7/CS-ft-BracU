// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         int x;
//         cin >> x;
//         if (x + 1 % 3 == 0 || x + 2 % 3 == 0 || x % 3 == 0)
//         {
//             cout << "First" << endl;
//         }
//         else
//         {
//             cout << "Second" << endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

void winner(int n)
{
    if ((n + 1) % 3 == 0 || (n - 1) % 3 == 0)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        winner(n);
    }
    return 0;
}