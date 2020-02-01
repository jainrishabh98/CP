#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x;
    cin >> x;
    ll ans = x;
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ll a = i;
            ll b = x / i;
            if (__gcd(a, b) == 1)
            {
                ans = min(ans, max(a, b));
            }
        }
    }
    cout << ans << " " << x / ans;
}