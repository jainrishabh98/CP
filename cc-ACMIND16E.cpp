#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll power(ll n, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p & 1)
            ans = (ans * n) % mod;
        p = p >> 1;
        n = (n * n) % mod;
    }
    return ans;
}

int main()
{
    int t;
    ll n, c, ans;
    cin >> t;
    ll inv4 = power(4, mod - 2);
    while (t--)
    {
        cin >> n >> c;
        ll a = n % (mod - 1);
        a = (a * a) % (mod - 1);
        a = (5 * a) % (mod - 1);
        a = power(c, a);
        ll b = (n + 1) / 2;
        b %= (mod - 1);
        ll d;
        if (n & 1)
        {

            b = (((((b * b) % (mod - 1)) * 5) % (mod - 1)) - (5 * b) % (mod - 1) + 2 + mod - 1) % (mod - 1);
            b = (2 * power(c, b)) % mod;
            d = (n + 1) / 2;
            d %= (mod - 1);
            ll e = (n + 1) % (mod - 1);
            d = (d * e) % (mod - 1);
            d = (d * 5) % (mod - 1);
            d = (d - (5 * n) % (mod - 1) - 2 + 2 * mod - 2) % (mod - 1);
        }
        else
        {
            b = (b * b) % (mod - 1);
            b = (5 * b) % (mod - 1);
            b = (2 * power(c, b)) % mod;
            d = (n / 2);
            d %= (mod - 1);
            n %= (mod - 1);
            d = (d * n) % (mod - 1);
            d = (d * 5) % (mod - 1);
        }
        d = power(c, d);
        ll ans = (a + b + d) % mod;
        ans = (ans * inv4) % mod;
        cout << ans << "\n";
    }
    return 0;
}
