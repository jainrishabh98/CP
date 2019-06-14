#include <bits/stdc++.h>
using namespace std;
int n, m, d;
vector<int> g[100005];
int p[100005];
int dist_down[100005];
int dist_up[100005];
void dfs_down(int u, int pp)
{
    dist_down[u] = p[u]==1 ? 0:-1;
    for (auto v : g[u])
    {
        if (v != pp)
        {
            dfs_down(v, u);
            if(dist_down[v]>-1)
                dist_down[u] = max(dist_down[u], dist_down[v] + 1);
        }
    }
}
void dfs_up(int u, int pp)
{
    int max1 = -1, max2 = -1;
    for (auto v : g[u])
    {
        if (v != pp)
        {
            if (dist_down[v] > max1)
            {
                max2 = max1;
                max1 = dist_down[v];
            }
            else if (dist_down[v] > max2)
            {
                max2 = dist_down[v];
            }
        }
    }
    for (auto v : g[u])
    {
        if (v != pp)
        {  
           dist_up[v] = dist_down[v]==max1 ? max2 : max1;
            if(dist_up[v]!=-1)
                dist_up[v] += 2;
            if(p[v]==1)
                dist_up[v]=max(dist_up[v],0);
            if(dist_up[u] != -1) 
                dist_up[v] = max(dist_up[v],dist_up[u]+1);
            dfs_up(v,u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        p[x] = 1;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs_down(1,-1);
    dist_up[1] = p[1]==1 ? 0:-1;
    dfs_up(1,-1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dist_down[i]<=d && dist_up[i]<=d)
            ans++;
    }
    cout<<ans;
}