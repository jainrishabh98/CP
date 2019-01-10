#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n, k;
    cin >> n >> k;
    ll m = 1e9 + 7;
    ll dp[n + 1][k + 1];
    vector<ll> store[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (i % j == 0)
            {
                store[i].push_back(j);
            }
        }
        //   cout<<store[i]<<" ";
    }
    for (int l = 1; l <= k; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (l == 1)
            {
                dp[i][l] = 1;
            }
            else if (i == 1)
            {
                dp[i][l] = 1;
            }
            else
            {
                ll cnt = 0;
                ll x = i;
                // the following loop takes logn time
                for (auto b : store[x])     // traversing precomputed divisors... can also be done using loop(i to n & i+=n) which happens in logn time 
                {
                    cnt = (cnt + dp[b][l - 1]) % m;
                }
                dp[i][l] = cnt;
            }
        }
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum = (sum + dp[i][k]) % m;

    cout << sum << "\n";
    return 0;
}