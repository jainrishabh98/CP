#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[5005];
int vis[5005];
map<pair<int, int>, int> mp;
vector<int> v;
int val;
int fl = 0;
void dfs(int u, int p, int y)
{
    vis[u] = 1;
    v.push_back(u);
    // cout << u << " ";
    if (u == y)
    {
        int nn = v.size();
        int prev = v[nn-1];
        nn--;
        while (nn!=0)
        {
            int pp = v[nn-1];
            nn--;
            mp[{min(pp, prev), max(pp, prev)}] = min(mp[{min(pp, prev), max(pp, prev)}], val);
            prev = pp;
        }
    }
    else
    {

        for (auto j : g[u])
        {
            if (!vis[j])
            {
                dfs(j, u, y);
            }
        }
        v.pop_back();
    }
}
void dfs2(int u, int p, int y)
{
    vis[u] = 1;
    v.push_back(u);
    if (u == y)
    {
        int f1 = 0, f2 = 0;
        int nn = v.size();
        int prev = v[nn-1];
        nn--;
        while (nn!=0)
        {
            int pp = v[nn-1];
            nn--;
            int yy = mp[{min(pp, prev), max(pp, prev)}];
            if (yy < val)
                f1 = 1;
            else if (yy == val)
                f2 = 1;
            prev = pp;
        }
        if (f1 == 1)
            fl = 1;
        else if (f2 == 0)
            fl = 1;
    }
    else
    {

        for (auto j : g[u])
        {
            if (!vis[j])
            {
                dfs2(j, u, y);
            }
        }
        v.pop_back();
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        mp[{min(x, y), max(x, y)}] = 1000000;
    }
    // cout << 'h';
    int m;
    cin >> m;
    int a[m], b[m], gg[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> gg[i];
        val = gg[i];
        memset(vis, 0, sizeof(vis));
        dfs(a[i], 0, b[i]);
    }
    // cout << 'h';
    fl = 0;
    for (int i = 0; i < m; i++)
    {
        val = gg[i];
        memset(vis,0,sizeof(vis));
        dfs2(a[i], 0, b[i]);
    }
    // cout << 'h';
    if (fl == 1)
    {
        cout << -1;
        return 0;
    }
    for (auto i : mp)
    {
        cout << i.second << " ";
    }
}