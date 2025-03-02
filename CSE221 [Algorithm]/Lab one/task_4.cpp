#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Bubble sort function
void bubbleSort(vector<vector<string>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            string train1 = arr[j][0];
            string train2 = arr[j + 1][0];
            int length1 = train1.length();
            int length2 = train2.length();
            int range_length = max(length1, length2);
            int idx1 = 0;
            int idx2 = 0;
            if (train1 == train2)
            {
                string time1 = arr[j].back();
                string time2 = arr[j + 1].back();
                for (int k = 0; k < time1.length(); ++k)
                {
                    if (time1[k] > time2[k])
                    {
                        break;
                    }
                    if (time1[k] < time2[k])
                    {
                        swap(arr[j], arr[j + 1]);
                        break;
                    }
                }
            }
            else
            {
                for (int k = 0; k < range_length; ++k)
                {
                    if (idx1 == length1 || idx2 == length2)
                    {
                        if (length1 > length2)
                        {
                            swap(arr[j], arr[j + 1]);
                        }
                        break;
                    }
                    if (train1[idx1] < train2[idx2])
                    {
                        break;
                    }
                    if (train1[idx1] > train2[idx2])
                    {
                        swap(arr[j], arr[j + 1]);
                        break;
                    }
                    idx1 += 1;
                    idx2 += 1;
                }
            }
        }
    }
}

// Train schedule function
// void trainSchedule() {
//     ifstream f1("input4.txt");
//     int input_no;
//     f1 >> input_no;
//     vector<vector<string>> arr(input_no);
//     for (int i = 0; i < input_no; ++i) {
//         string line;
//         getline(f1, line);
//         arr[i] = vector<string>(istream_iterator<string>(istringstream(line)), istream_iterator<string>());
//     }

//     bubbleSort(arr);

//     ofstream f2("output4.txt");
//     for (const auto& item : arr) {
//         for (const auto& str : item) {
//             f2 << str << " ";
//         }
//         f2 << "\n";
//     }
// }

int main()
{
    // trainSchedule();
    return 0;
}