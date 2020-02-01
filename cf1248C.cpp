#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, mod = 1e9 + 7;
    cin >> n >> m;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= max(n, m); i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    cout << (2 * (dp[n] + dp[m] - 1 + mod) % mod) % mod;
}