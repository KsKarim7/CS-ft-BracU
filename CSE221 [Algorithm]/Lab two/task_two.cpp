#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int nums[N];
// 1) a

void merge(int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int L[left_size + 1];

    int right_size = r - (mid + 1) + 1;
    int R[right_size + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = nums[i];
    }
    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = nums[i];
    }

    L[left_size] = INT_MAX;
    R[left_size] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            nums[i] = L[lp];
            lp++;
        }
        else
        {
            nums[i] = R[rp];
            rp++;
        }
    }
}

void mergeSort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, r, mid);
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> m;

    for (int i = n; i < n + m; i++)
    {
        cin >> nums[i];
    }
    mergeSort(0, n - 1);

    for (int i = 0; i < n + m; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}

// 1)b
// int main()
// {
//     int i, j;
//     cin >> i;
//     int arr1[i];
//     for (int m = 0; m < i; m++)
//     {
//         // cin >> arr1[m];
//         scanf("%d", &arr1[m]);
//     }
//     arr1[i] = INT_MAX;
//     cin >> j;
//     int arr2[j];
//     for (int m = 0; m < j; m++)
//     {
//         // cin >> arr2[m];
//         scanf("%d", &arr2[m]);
//     }
//     arr2[j] = INT_MAX;
//     int res[i + j];
//     int pointer1 = 0, pointer2 = 0;
//     while (pointer1 != i || pointer2 != j)
//     {
//         if (arr1[pointer1] < arr2[pointer2])
//         {
//             res[pointer1 + pointer2] = arr1[pointer1];
//             pointer1++;
//         }
//         else
//         {
//             res[pointer1 + pointer2] = arr2[pointer2];
//             pointer2++;
//         }
//     }
//     for (int k = 0; k < i + j; k++)
//     {
//         printf("%d ", res[k]);
//     }
//     return 0;
// }