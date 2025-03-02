#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int arr[N];

int partition(int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void quick_sort(int l, int h)
{
    if (l < h)
    {
        int j = partition(l, h);
        quick_sort(l, j - 1);
        quick_sort(j + 1, h);
    }
}

int main()
{
    int n;
    cin >> n;
    // int arr[n];
    // arr[n] = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}