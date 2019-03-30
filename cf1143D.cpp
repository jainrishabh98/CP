#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    set<ll> s;
    ll t = abs(a - b);
    ll tt = abs(k - a - b);
    ll ttt = a + b;
    ll r = k - a + b;
    for (ll i = 0; i <= n; i++)
    {
        if (t + k * i <= n * k)
            s.insert(t + k * i);
        if (tt + k * i <= n * k)
            s.insert(tt + k * i);
        if (ttt + k * i <= n * k)
            s.insert(ttt + k * i);
        if (r + k * i <= n * k)
            s.insert(r + k * i);
    }
    unsigned long long int mn = n * k, mx = 0,temp;
    for (auto i : s)
    {
        if (i != 0)
        {
            temp = __gcd(i, n * k);
            temp = (n * k) / temp;
            temp *= i;
            mn = min(mn, temp / i);
            mx = max(mx, temp / i);
        }
    }
    cout << mn << " " << mx;
}