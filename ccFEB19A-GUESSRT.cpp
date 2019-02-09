#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
ll n, m, k, p, ans, inv, a, b, c;
ll fp(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = fp(x, y / 2) % mod;
    p = (p * p) % mod;
    return (y % 2 == 0) ? p : (x * p) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        
        cin >> n >> k >> m;
        p = (m + 1) / 2;
        c = fp(n - 1, p);
        b = fp(n, p);
        a = (b - c + mod) % mod;
        inv = fp(b, mod - 2);
        ans = (a * inv) % mod;
        if (m % 2 == 0)
        {
            b = (b * (n + k)) % mod;
            inv = fp(b, mod - 2);
            ans = (ans + (c * inv) % mod) % mod;
        }
        cout << ans << "\n";
    }
}