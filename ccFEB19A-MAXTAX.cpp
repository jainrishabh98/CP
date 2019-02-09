#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e9 + 21;
ll cnt = 0;
vector<bool> v;
vector<vector<int>> g;
vector<vector<int>> h;
vector<int> b;
void my_dfs(int u)
{
    h[cnt].push_back(b[u]);
    v[u] = true;
    // cout<<u<<" ";
    for (auto j = g[u].begin(); j != g[u].end(); j++)
    {
        if (!v[*j])
        {
            my_dfs(*j);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, e, k;
        cin >> n >> e >> k;
        v.assign(n, false);
        g.assign(n, vector<int>());
        int a, c;
        b.assign(n, 0);
        cnt = 0;
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < e; i++)
        {
            cin >> a >> c;
            a--;
            c--;
            g[a].push_back(c);
        }
        for (int i = 0; i < n; i++)
        {
            if (!v[i])
            {
                h.push_back(vector<int>());
                my_dfs(i);
                cnt++;
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            sort(h[i].begin(), h[i].end());
        }
        ll ans = 0, an = 0;
        for (int i = 0; i < cnt; i++)
        {
            an = 0;
            ll l = h[i].size();
            for (int j = 0; j < min(l, k + 2); j++)
            {
                ll c = h[i][j];
                an = max(an, (ll)c * (l - j));
            }
            ans = max(ans, an);
            h[i].clear();
        }
        cout << ans % m << "\n";
        
    }
}