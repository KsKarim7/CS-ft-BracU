#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int sum = a + b + c;

        if (c % 2 == 0)
        {
            if (a > b)
            {

                cout << "First" << endl;
            }

            else
            {

                cout << "Second" << endl;
            }
        }
        else
        {
            if (b > a)
            {

                cout << "Second" << endl;
            }
            else
            {
                cout << "First" << endl;
            }
        }
        // else
        // {
        //     cout << "First" << endl;
        // }

        // if (sum - a > sum - b)
        // {
        //     cout << "Second" << endl;
        // }
        // else
        // {
        //     cout << "First" << endl;
        // }
    }
    return 0;
}