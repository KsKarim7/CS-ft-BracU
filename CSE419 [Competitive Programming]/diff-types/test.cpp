#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2, 3, -4, -1, 3, 10, -8};
    int curr_max = 0, gbl_max = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        curr_max = max(arr[i], curr_max + arr[i]);
        gbl_max = max(gbl_max, curr_max);
    }
    cout << "Global Maximum Subarray Sum: " << gbl_max << endl;
    return 0;
}