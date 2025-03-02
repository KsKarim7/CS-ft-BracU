#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Bubble sort function
void bubbleSort(vector<pair<int, int>>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].second < arr[j + 1].second) {
                swap(arr[j], arr[j + 1]);
            }
            if (arr[j].second == arr[j + 1].second) {
                if (arr[j].first > arr[j + 1].first) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

// Ranking function
void ranking() {
    ifstream f1("input3.txt");
    ofstream f2("output3.txt");
    f2 << "";

    int num_inputs;
    f1 >> num_inputs;
    vector<int> id_arr(num_inputs);
    vector<int> mark_arr(num_inputs);

    for (int i = 0; i < num_inputs; ++i) {
        f1 >> id_arr[i];
    }
    for (int i = 0; i < num_inputs; ++i) {
        f1 >> mark_arr[i];
    }

    vector<pair<int, int>> id_mark_arr;
    for (int i = 0; i < num_inputs; ++i) {
        id_mark_arr.push_back({id_arr[i], mark_arr[i]});
    }

    bubbleSort(id_mark_arr);

    for (const auto& pair : id_mark_arr) {
        f2 << "ID: " << pair.first << " Mark: " << pair.second << "\n";
    }
    f2 << "\n";
}

int main() {
    ranking();
    return 0;
}