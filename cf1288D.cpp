#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, pair<ll, ll>>> v;
map<ll, ll> mp;
ll po[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            v.push_back({x, {i, pow(2, j)}});
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll p = pow(2, m) - 1;
    int i1 = -1, i2 = -1;
    for (int i = 0; i < v.size(); i++)
    {
        po[v[i].second.first] ^= v[i].second.second;
        x = p ^ po[v[i].second.first];
        if (mp.find(x) != mp.end() || x == 0)
        {
            i1 = v[i].second.first;
            if (x == 0)
                i2 = i1;
            else
                i2 = mp[x];
            break;
        }
        mp[po[v[i].second.first]] = v[i].second.first;
    }
    cout << i1 + 1 << " " << i2 + 1;
}