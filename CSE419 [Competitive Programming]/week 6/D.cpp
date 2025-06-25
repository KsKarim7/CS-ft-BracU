#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> lis(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> lis[i];
    }

    int max_lis = *max_element(lis.begin(), lis.end());
    int num = static_cast<int>(sqrt(max_lis)) + 1;

    vector<int> arr(num, 1); // All initialized to 1
    set<int> pre;

    // sieve of Eratosthenes
    for (int i = 2; i < num; i++)
    {
        if (arr[i])
        {
            pre.insert(i * i);
            for (int j = i * i; j < num; j += i)
            {
                arr[j] = 0;
            }
        }
    }

    for (int x : lis)
    {
        if (pre.count(x))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
