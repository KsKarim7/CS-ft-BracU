#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int arr_1[n], arr_2[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr_1[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr_2[i]);
        }
        sort(arr_1, arr_1 + n);
        sort(arr_2, arr_2 + n);
        int i = 0, j = n - 1, sum = 0;
        for (int z = 0; z < n; z++)
        {

            if (arr_1[i] < arr_2[j] && k > 0)
            {
                sum += arr_2[j];
                swap(arr_1[i], arr_2[j]);
                k--;
            }
            else
            {
                sum += arr_1[i];
            }
            i++;
            j--;
        }
        printf("%d\n", sum);
    }
    return 0;
}