#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        // Find the maximum sum of any contiguous sequence (X)
        int max_sum = -99999;
        int current_sum = 0;
        for (int i = 0; i < n; i++)
        {
            current_sum = max(A[i], current_sum + A[i]);
            max_sum = max(max_sum, current_sum);
        }

        // Count the number of contiguous sequences that sum up to X using a map
        map<int, int> sum_count;
        current_sum = 0;
        for (int i = 0; i < n; i++)
        {
            current_sum += A[i];
            sum_count[current_sum]++;
            if (current_sum > max_sum)
            {
                current_sum = 0;
            }
        }

        int count = sum_count[max_sum];

        cout << max_sum << " " << count << endl;
    }

    return 0;
}