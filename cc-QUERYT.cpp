#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 40005;
int val[MAX_N];
int vis[MAX_N];
vector<int> g[MAX_N];
int tin[MAX_N];
int tout[MAX_N];
pair<int, int> segtree[8 * MAX_N];
pair<int, int> arr[2 * MAX_N];
int sz = 0;
int qlow, qhigh, p, diff;
void build(int low, int high, int pos)
{
    if (low == high)
    {
        segtree[pos].first = arr[low].first;
        segtree[pos].second = arr[low].second;
        return;
    }
    int mid = (low + high) / 2;
    build(low, mid, 2 * pos + 1);
    build(mid + 1, high, 2 * pos + 2);
    segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);
}
pair<int, int> query(int low, int high, int pos)
{
    if (qlow <= low && qhigh >= high) // total overlap
        return segtree[pos];
    if (qlow > high || qhigh < low) // no overlap
        return {10000000, 1};
    int mid = (low + high) / 2;
    return min(query(low, mid, 2 * pos + 1), query(mid + 1, high, 2 * pos + 2));
}
ll dp[MAX_N][202];
void dfs(int u)
{
    // mark vis of root
    arr[sz] = {vis[u], u};
    tin[u] = sz;
    tout[u] = sz;
    sz++;
    dp[u][val[u]]++;
    for (auto j : g[u])
    {
        if (!vis[j])
        {
            vis[j] = vis[u] + 1;
            for (int i = 1; i <= 200; i++)
                dp[j][i] = dp[u][i];
            dfs(j);
            arr[sz] = {vis[u], u};
            tout[u] = max(tout[u], sz);
            sz++;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[0] = 1;
    dfs(0);
    build(0, sz - 1, 0);
    int q;
    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        u--;
        v--;
        int lca;
        if (tin[u] <= tin[v])
        {
            qlow = tin[u];
            qhigh = tout[v];
        }
        else
        {
            qlow = tin[v];
            qhigh = tout[u];
        }
        // cout<<qlow<<" "<<qhigh<<"\n";
        lca = query(0, sz - 1, 0).second;
        int ans = 0;
        for (int i = 1; i <= 200; i++)
        {
            if (__gcd(i, val[lca]) > 1)
            {
                ans += dp[u][i];
                ans += dp[v][i];
                ans -= 2 * dp[lca][i];
            }
        }
        if (val[lca] != 1)
            ans++;
        cout << ans << "\n";
    }
}