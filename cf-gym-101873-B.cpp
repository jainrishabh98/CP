#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
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
    ll n, m, c;
    cin >> n >> m >> c;
    ll ans = 0;
    for (ll i = 0; i < m; i++)
    {
        ll x = __gcd(i, m);

        ans += power(c, n * n * x);

        ans %= mod;
    }
    ans = ans * power(m, mod - 2) % mod;
    cout << ans;
}