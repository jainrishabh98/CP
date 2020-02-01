#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m = 1e9 + 7;
ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % m;
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        ll a0 = 0, b0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '0')
                a0++;
            if (b[i] == '0')
                b0++;
        }
        ll a1 = n - a0, b1 = n - b0;
        ll mn = abs(a0 - b0);
        ll mx = n - abs(a0 - b1);
        ll f = 1, g = 1;
        for (ll i = 1; i <= mn; i++)
        {
            (f *= (n - i + 1)) %= m;
            (g *= i) %= m;
        }
        g = power(g, m - 2);
        f = (f * g) % m;
        ll tmp, t;
        ll ans = f;
        for (ll j = mn; j < mx - 1; j += 2)
        {
            tmp = ((n - j) * (n - j - 1)) % m;
            t = ((j + 1) * (j + 2)) % m;
            t = power(t, m - 2);
            t = (t * tmp) % m;
            f = (f * t) % m;
            ans = (ans + f)%m;
        }
        cout<<ans<<"\n";
    }
}