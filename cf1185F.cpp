#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, x, y, c;
    cin >> n >> m;
    ll req[n];
    map<ll, pair<ll, ll>> mp, mp2;
    map<ll, ll> ump;
    for (int i = 0; i < n; i++)
    {
        ll p = 0;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            y = pow(2, y - 1);
            p ^= y;
        }
        req[i] = p;
    }
    for (int j = 0; j < m; j++)
    {
        cin >> c;
        ll p = 0;
        ll jj = j + 1;
        cin >> x;
        for (int k = 0; k < x; k++)
        {
            cin >> y;
            y = pow(2, y - 1);
            p ^= y;
        }
        if (mp.find(p) == mp.end())
            mp[p] = {c, jj};
        else
        {
            if (mp[p].first > c)
            {
                ll cc, jjj;
                cc = mp[p].first;
                mp[p].first = c;
                jjj = mp[p].second;
                mp[p].second = jj;
                jj = jjj;
                c = cc;
            }
            if (mp2.find(p) == mp2.end())
                mp2[p] = {c, jj};
            else if (mp2[p].first > c)
            {
                mp2[p].first = c;
                mp2[p].second = jj;
            }
        }
    }
    ll ex = pow(2, 9);
    for (ll i = 0; i < ex; i++)
    {
        ll cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if ((req[j] & i) == req[j])
                cnt++;
        }
        if (ump.find(i) == ump.end())
            ump[i] = cnt;
        else
            ump[i] = max(ump[i], cnt);
    }
    vector<ll> v;
    for (auto i : mp)
        v.push_back(i.first);
    for (auto i : mp2)
        v.push_back(i.first);
    ll mx = -1, cost = 1e17, j1 = -2, j2 = -2;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            ll xx = v[i] | v[j];
            if (v[i] != v[j])
            {
                if (ump[xx] > mx || (ump[xx] == mx && (cost > mp[v[i]].first + mp[v[j]].first)))
                {
                    mx = ump[xx];
                    cost = mp[v[i]].first + mp[v[j]].first;
                    j1 = mp[v[i]].second;
                    j2 = mp[v[j]].second;
                }
            }
            else
            {
                if (ump[xx] > mx || (ump[xx] == mx && (cost > mp[v[i]].first + mp2[v[j]].first)))
                {
                    mx = ump[xx];
                    cost = mp[v[i]].first + mp2[v[j]].first;
                    j1 = mp[v[i]].second;
                    j2 = mp2[v[j]].second;
                }
            }
        }
    }
    cout << j1 << " " << j2;
}