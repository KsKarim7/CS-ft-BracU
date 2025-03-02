#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 7;
// int nums[N];
vector<pair<int, int>> vec;

void merge(int l, int r, int mid)
{
    int left_size = mid - l + 1;
    // int L[left_size + 1];
    int right_size = r - mid + 1;
    // int R[right_size + 1];
    vector<pair<int, int>> L;
    vector<pair<int, int>> R;

    for (int i = l; i <= mid; i++)
    {
        // L[j] = vec[i];
        L.push_back(vec[i]);
    }

    for (int i = mid + 1; i <= r; i++)
    {
        R.push_back(vec[i]);
        // R[j] = vec[i];
    }

    L.push_back(make_pair(0, INT_MAX));
    R.push_back(make_pair(0, INT_MAX));

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
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        vec.push_back(make_pair(a, b));
    }
    mergeSort(0, n - 1);

    vector<pair<int, int>> res;
    res.push_back(vec[0]);

    int count = 1;

    int cur = vec[0].second;
    for (int i = 1; i < n; i++)
    {
        if (vec[i].first >= cur)
        {
            res.push_back(vec[i]);
            cur = vec[i].second;
            count++;
        }
    }
    printf("%d\n", count);
    for (auto &pair : res)
    {
        printf("%d %d\n", pair.first, pair.second);
    }
    return 0;
}