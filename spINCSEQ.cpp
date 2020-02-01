#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 5000000;
ll bit[10005][52];
void update(ll k, ll val, ll in)
{
    while (k < 10005)
    {
        (bit[k][in] += val) %= mod;
        k += (k & (-k));
    }
}
ll query(ll k, ll in)
{
    ll s = 0;
    while (k > 0)
    {
        (s += bit[k][in]) %= mod;
        k -= (k & (-k));
    }
    return s;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    set<ll> ss;
    map<ll, int> mp, mp2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ss.insert(a[i]);
    }
    if (k == 1)
    {
        cout << n;
        return 0;
    }
    ll cnt = 1;
    for (auto i : ss)
    {
        mp[i] = cnt;
        cnt++;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = mp[a[i]];
        update(a[i], 1, 1);
        for (int j = 1; j < k; j++)
        {
            ll s = query(a[i] - 1, j);
            update(a[i], s, j + 1);
        }
    }
    cout << query(cnt - 1, k);
}