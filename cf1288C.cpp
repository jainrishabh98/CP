#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2);
    p = (p * p) % mod;
    if (y % 2 != 0)
        p = (x * p) % mod;
    return p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll dp[n + 1], ans = 0;
    dp[1] = 1, dp[0] = 0;
    for (ll i = 2; i <= n; i++)
        dp[i] = (((dp[i - 1] * (m + i - 1)) % mod) * (power(i - 1, mod - 2))) % mod;
    for (ll i = 1; i <= n; i++)
        (ans += ((dp[n - i + 1]) * ((dp[i] - dp[i-1] + mod) % mod)) % mod) %= mod;
    cout << ans;
}