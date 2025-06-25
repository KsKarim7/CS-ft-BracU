#include <bits/stdc++.h>
using namespace std;


int gcd(int n,int m){
    if(m == 0){
        return n;
    }
    gcd(m,n%m);  //O(logN)
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<"GCD: "<<gcd(n,m)<<endl;
    cout<<"LCM: "<<n*m/gcd(n,m); 
    return 0;
}