#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int left, int mid, int right)
{
    int inversions = 0;
    int i = left, j = mid + 1, k = left;
    vector<int> temp(right + 1);

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

int countInversions(vector<int> &arr, int left, int right)
{
    int inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        inversions += countInversions(arr, left, mid);
        inversions += countInversions(arr, mid + 1, right);
        inversions += merge(arr, left, mid, right);
    }
    return inversions;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << countInversions(arr, 0, n - 1) << endl;
    return 0;
}