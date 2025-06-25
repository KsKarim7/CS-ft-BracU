// #include <bits/stdc++.h>
// using namespace std;
//
//
// int main(){
//
//     int t;
//     cin>>t;
//     while(t--){
//         string b;
//         cin>>b;
//         int n = b.size();
//         if(b[0] != b.back()){
//             b[0] = b.back();
//         }
//         cout<<b<<endl;
//
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        swap(arr[0], arr[1]);
        swap(arr[n - 1], arr[0]);

        if (arr[0] == arr[1])
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {

                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
}
