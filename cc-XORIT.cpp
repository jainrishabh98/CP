#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fun(ll n)
{
    ll p = n - 1;
    ll sum = p * (p + 1) / 2;
    ll cnt = 0;
    ll x = p;
    while (x != 0)
    {
        cnt++;
        x /= 2;
    }
    sum -= cnt;
    ll pp = pow(2, cnt - 1);
    ll pref = 0;
    while (pp != 0)
    {
        ll xx = p / pp;
        sum -= ((xx - pref) * pp);
        pp /= 2;
        pref = xx;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        ll a1 = 0, a2 = 0;
        if (l > 1)
        {
            a1 = fun(l);
        }
        a2 = fun(r+1);
        a2 -= a1;
        cout<<a2<<"\n";
    }
}