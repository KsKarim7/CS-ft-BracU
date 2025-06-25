#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second; // Sorting in descending order based on the second element of the pair (duration)
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> movies[i].first >> movies[i].second;
    }
    sort(movies.begin(), movies.end(), cmp);
    int i = 0;
    int count = 0;
    int end = INT_MIN;
    while (i < n)
    {
        if (movies[i].first >= end)
        {
            count++;
            end = movies[i].second;
        }
        i++;
    }
    cout << count << endl;
    return 0;
}