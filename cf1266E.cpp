#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, q;
    cin >> n;
    ll quan[n + 1] = {0};
    ll a[n + 1];
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cin >> q;
    map<pair<ll, ll>, ll> mp;
    ll s, t, u;
    for (ll i = 0; i < q; i++)
    {
        cin >> s >> t >> u;
        if (mp.find({s, t}) == mp.end())
        {
            if (u != 0)
            {
                mp[{s, t}] = u;
                quan[u]++;
                if (quan[u] <= a[u])
                    sum--;
            }
        }
        else
        {
            ll p = mp[{s, t}];
            mp.erase({s, t});
            quan[p]--;
            if (quan[p] < a[p])
                sum++;
            if (u != 0)
            {
                mp[{s, t}] = u;
                quan[u]++;
                if (quan[u] <= a[u])
                    sum--;
            }
        }
        cout << sum << "\n";
    }
}