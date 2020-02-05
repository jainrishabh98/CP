#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 100005;
int vis[MAX_N];
vector <int> g[MAX_N];
int tin[MAX_N];
int tout[MAX_N];
int sz=1;
ll a[MAX_N];
void dfs(int u)
{
    // mark vis of root
    tin[u] = sz;
    tout[u] = sz;
    sz++;
    for (auto j : g[u])
    {
        if (!vis[j])
        {
            vis[j] = vis[u] + 1;
            dfs(j);
            tout[u] = max(tout[u],sz);
            sz++;
        }
    }
}
ll bit[2*MAX_N];
void update(ll k, ll val)
{
    while (k < 2*MAX_N)
    {
        bit[k] += val;
        k += (k & (-k));
    }
}
ll query(ll k)
{
    ll s = 0;
    while (k > 0)
    {
        s += bit[k];
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
    ll n,u,v;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i] = a[i]*a[i];
    }
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[1] = 1;
    dfs(1);
    int q;
    cin>>q;
    for(int i=1;i<=n;i++)
    {
        update(tin[i],a[i]);
    }
    while(q--)
    {
        cin>>v;
        if(v==1)
        {
            cin>>u>>v;
            update(tin[u],-a[u]);
            a[u] = v*v;
            update(tin[u],a[u]);
        }
        else
        {
            cin>>u;
            // cout<<u<<" "<<tin[u]<<" "<<tout[u]<<"\n";
            ll ans = query(tout[u]);
            if(tin[u] > 0)
            {
                ans -= query(tin[u]-1);
            }
            cout<<ans<<"\n";
        }
    }
}