#include <iostream>
#include <vector>
#include <algorithm>

int minPrefixSum(std::vector<int> &arr)
{
    int min_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        current_sum += arr[i];
        min_sum = std::min(min_sum, current_sum);
    }

    return min_sum;
}

int main()
{
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int min_sum = minPrefixSum(arr);
    std::cout << "Minimum prefix sum: " << min_sum << std::endl;
    return 0;
}