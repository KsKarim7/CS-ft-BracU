// Question: https://bit.ly/3Mdw2FX

// int lower_bound(vector<int> &arr, int n, int x)
// {
//     int low = 0, high = n - 1, ans = n;
//     while (low <= high)
//     {
//         int mid = (low + high)  / 2;
//         if (arr[mid] >= x)
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// int upper_bound(vector<int> &arr, int n, int x)
// {
//     int low = 0, high = n - 1, ans = n;
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (arr[mid] > x)
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }
// pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
// {
//     // Write your code here
//     int lb = lower_bound(arr, n, k);
//     if (lb == n || arr[lb] != k)
//         return {-1, -1};
//     return {lb, upper_bound(arr, n, k) - 1};
// }
