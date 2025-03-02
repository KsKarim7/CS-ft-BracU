#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0, j = n - 1;
    bool flag = false;
    while (i != j)
    {
        if (arr[i] + arr[j] == s)
        {
            flag = true;
            break;
        }
        else if (arr[i] + arr[j] < s)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if (flag == false)
    {
        printf("%s\n", "IMPOSSIBLE");
    }
    else
    {

        printf("%d %d\n", i + 1, j + 1);
    }
    return 0;
}