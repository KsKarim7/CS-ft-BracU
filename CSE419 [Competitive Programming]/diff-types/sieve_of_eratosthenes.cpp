#include <bits/stdc++.h>
using namespace std;

void sieve(int n)
{
    bool prime[n + 1];
    memset(prime, false, sizeof(prime)); // this line effectively initializes the array with all false values. 0(N)

    for (int i = 2; i * i < n; i++)
    {
        if (prime[i] == false)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = true; // mark all multiples of i as not prime
            }
        }
    } //Nlog(logN) prime harmonic series
    for (int i = 2; i < n; i++)
    {
        if (prime[i] == false)
        {
            cout << i << " "; // print all prime numbers up to n
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    return 0;
}