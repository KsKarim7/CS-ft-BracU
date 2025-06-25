// // C++ program to illustrate the begin and end iterator
// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;

// int main()
// {
//     // Create a map of strings to integers
//     map<string, int> mp;

//     // Insert some values into the map
//     mp["one"] = 1;
//     mp["two"] = 2;
//     mp["three"] = 3;

//     // Get an iterator pointing to the first element in the
//     // map
//     map<string, int>::iterator it = mp.begin();

//     // Iterate through the map and print the elements
//     while (it != mp.end())
//     {
//         cout << "Key: " << it->first
//              << ", Value: " << it->second << endl;
//         ++it;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
// #define pb push_back
// #define mp make_pair
// #define all(x) x.begin(), x.end()

int main()
{

    ll t;
    cin >> t;

read:
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        for (ll i = 1; i < n; i++)
        {
            if (a[i] - a[i - 1] > 1)
            {
                cout << "NO" << endl;
                goto read;
            }
        }

        cout << "YES" << endl;
    }

    return 0;
}