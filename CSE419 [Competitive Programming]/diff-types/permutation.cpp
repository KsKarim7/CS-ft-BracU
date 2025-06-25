#include <iostream>
#include <string>
using namespace std;

void permute(string s, int left, int right)
{
    if (left == right)
    {
        cout << s << endl;
    }
    else
    {

        for (int i = left; i <= right; i++)
        {

            swap(s[left], s[i]);

            permute(s, left + 1, right);

            swap(s[left], s[i]);
        }
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "All permutations of the string are: " << endl;
    permute(str, 0, str.length() - 1);

    return 0;
}