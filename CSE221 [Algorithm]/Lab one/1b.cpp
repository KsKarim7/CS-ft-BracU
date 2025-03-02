#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, op;

        int num, mum;
        cin >> s >> num >> op >> mum;
        // cout << s << num << op << mum;
        cout << "The result of " << num;
        if (op == "+")
        {
            cout << " + " << mum << " is " << num + mum << '\n';
        }
        else if (op == "-")
        {
            cout << " - " << mum << " is " << num - mum << '\n';
        }
        else if (op == "*")
        {
            cout << " * " << mum << " is " << num * mum << '\n';
        }
        else if (op == "/")
        {
            double res = num / mum;
            cout << " / " << mum << " is " << fixed << setprecision(1) << res << '\n';
        }
    }
    return 0;
}
// switch (op)
// {
// case '+':
//     res = num + mum;
//     break;
// case '-':
//     res = num - mum;
//     break;
// case '*':
//     res = num * mum;
//     break;
// case '/':
//     res = num / mum;
//     break;
// default: