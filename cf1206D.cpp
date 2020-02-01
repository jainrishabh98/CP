#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> g[100005];
int shortest_cycle(int n)
{
    ll ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 0)
            continue;
        vector<ll> dist(n, (ll)(1e9));
        vector<int> par(n, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (auto child : g[x])
            {
                if (dist[child] == (ll)(1e9))
                {
                    dist[child] = 1 + dist[x];
                    par[child] = x;
                    q.push(child);
                }
                else if (par[x] != child and par[child] != x)
                    ans = min(ans, dist[x] + dist[child] + 1);
            }
        }
    }
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> v;
    for (ll i = 0; i <= 63; i++)
    {
        v.clear();
        for (int j = 0; j < n; j++)
        {
            if (a[j] & ((ll)(1) << i))
            {
                v.push_back(j);
            }
        }
        if (v.size() >= 3)
        {
            cout << 3;
            return 0;
        }
        else if (v.size() == 2)
        {
            g[v[0]].insert(v[1]);
            g[v[1]].insert(v[0]);
        }
    }
    cout << shortest_cycle(n);
}