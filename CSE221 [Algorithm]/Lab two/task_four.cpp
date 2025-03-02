#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vec;

void merge(int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int right_size = r - mid + 1;

    vector<pair<int, int>> L;
    vector<pair<int, int>> R;

    for (int i = l; i <= mid; i++)
    {
        L.push_back(vec[i]);
    }
    for (int i = mid + 1; i <= r; i++)
    {
        R.push_back(vec[i]);
    }
    L.push_back({0, INT_MAX});
    R.push_back({0, INT_MAX});

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp].second <= R[rp].second)
        {
            vec[i] = L[lp];
            lp++;
        }
        else
        {
            vec[i] = R[rp];
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
    cin >> n >> m;
    // int arr[m] = {[0 ... (m - 1)] = 0};
    int arr[m];
    fill_n(arr, m, 0);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    mergeSort(0, n - 1);

    int work = 0;
    bool flag = true;
    for (auto pair : vec)
    {
        for (int i = 0; i < m; i++)
        {
            if (pair.first >= arr[i] && flag == true)
            {
                arr[i] = pair.second;
                flag = false;
                work++;
            }
        }
        flag = true;
    }
    cout << work << endl;

    return 0;
}