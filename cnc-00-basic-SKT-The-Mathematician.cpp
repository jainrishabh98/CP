#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1000000007;
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ll q, t;
    ll n;
    cin >> q;
    while (q--)
    {
        cin >> n >> t;
        ll y = power(t + 1, m - 2) % m;
        ll f = 1, g = 1;
        for (ll i = 1; i <= t + 1; i++)
        {
            f = (f * ((n + i) % m)) % m;
            if (i <= t)
                g = (g * i) % m;
        }
        ll sum = ((f * y) % m - g + m) % m;
        cout << sum << "\n";
    }
    return 0;
}