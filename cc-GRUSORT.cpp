#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
map<int, int> mp;
ll dp[1005][1005];
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2);
    p = (p * p) % mod;
    if (y % 2 != 0)
        (p *= x) %= mod;
    return p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        s.insert(a[i]);
    }
    int m = s.size();
    int in = 1;
    dp[0][0] = 1;
    for (auto i : s)
    {
        int cnt = mp[i];
        for (int l = 0; l <= k; l++)
        {
            ll f = 1;
            for (int j = 0; j <= min(l, cnt); j++)
            {
                dp[in][l] += (f * dp[in - 1][l - j]) % mod;
                (f *= (cnt - j)) %= mod;
            }
        }
        in++;
    }
    ll d = 1;
    for (ll i = 1; i <= k; i++)
        d = (d * (n - i + 1)) % mod;
    cout << (dp[m][k] * power(d, mod - 2)) % mod;
}