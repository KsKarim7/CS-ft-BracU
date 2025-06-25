#include <bits/stdc++.h>
using namespace std;
// #include <algorithm>

bool isSorted(int arr[], int n)
{
    return is_sorted(arr, arr + n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];

            if (j > 0 && flag == true)
            {
                if (a[j - 1] > a[j])
                {
                    flag = false;
                }
            }
        }
        if (flag == false && k != 0)
        {

            for (int i = 1; i < n; i++)
            {
                if (a[i] < a[i - 1])
                {
                    int j = i;
                    while (j > 0 && a[j] < a[j - 1] && j - i + 1 <= k)
                    {
                        j--;
                    }
                    reverse(a + j, a + i + 1);
                    i = j;
                }
            }
        }
        if (isSorted(a, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}