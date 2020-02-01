#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> g[200005];
ll vis[200005];
ll cnt = 0;
void dfs(int u, int p)
{
    vis[u] = 1;
    for (auto i : g[u])
    {
        if (!vis[i] && i != p)
        {
            cnt++;
            dfs(i, p);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m >> a >> b;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
            vis[i] = 0;
        }
        int u, v;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cnt = 1;
        dfs(a, b);
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
        }
        ll cn = n - cnt - 1;
        cnt = 1;
        dfs(b, a);
        cnt = n - cnt - 1;
        cout << cn * cnt << "\n";
    }
}