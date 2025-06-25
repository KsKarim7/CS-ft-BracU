#include <iostream>
#include <string>
using namespace std;

void combinations(string s, string result, int index)
{
    cout << result << endl;

    for (int i = index; i < s.length(); i++)
    {

        combinations(s, result + s[i], i + 1);
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "All combinations of the string are: " << endl;
    combinations(str, "", 0);

    return 0;
}