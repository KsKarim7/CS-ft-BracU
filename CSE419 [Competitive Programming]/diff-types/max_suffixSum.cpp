#include <iostream>
#include <vector>
#include <algorithm>

int maxSuffixSum(std::vector<int> &arr)
{
    int max_suffix_sum = arr[arr.size() - 1];
    int current_sum = arr[arr.size() - 1];

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        current_sum += arr[i];
        max_suffix_sum = std::max(max_suffix_sum, current_sum);
    }

    return max_suffix_sum;
}

int main()
{
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_suffix_sum = maxSuffixSum(arr);
    std::cout << "Maximum suffix sum: " << max_suffix_sum << std::endl;
    return 0;
}