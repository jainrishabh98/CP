#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll sum[200005];
ll kk[200005];
vector <ll> g[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << 0;
        return 0;
    }
    ll mod = 1e9 + 7;
    ll a[m],b[m];
    set<ll> ss;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        ss.insert(a[i]);
        ss.insert(b[i]);
    }
    ll cnt = 1;
    map<ll, ll> mp;
    int fl=0;
    for (auto k : ss)
    {
        if(k==0) fl=1;
        mp[k] = cnt;
        cnt++;
    }
    if (mp.find(n) == mp.end() || fl==0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = mp[a[i]];
        b[i] = mp[b[i]];
        g[b[i]].push_back(a[i]);
    }
    sum[0] = 0;
    sum[1] = 1;
    for (ll i=2; i <= mp[n]; i++)
    {
        for(auto j:g[i])
        {
        (kk[i] += (sum[i-1] - sum[j - 1] + mod ) % mod) %= mod;
        }
        sum[i] = (sum[i-1] + kk[i])%mod;
    }
    cout << kk[mp[n]];
}