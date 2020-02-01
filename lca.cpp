#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;
int vis[100005];
vector <int> g[MAX_N];
int tin[100005];
int tout[100005];
pair<int,int> segtree[8*MAX_N];
pair<int,int> arr[2*MAX_N];
int sz=0;
int qlow, qhigh, p, diff;
void build (int low, int high, int pos)
{
    if(low == high)
    {
        segtree[pos].first = arr[low].first;
        segtree[pos].second = arr[low].second;
        return ;
    }
    int mid = (low+high)/2;
    build (low, mid, 2*pos + 1);
    build (mid+1, high, 2*pos + 2);
    segtree[pos] = min(segtree[2*pos+1],segtree[2*pos+2]);
}
pair<int,int> query(int low, int high, int pos)
{
    if(qlow<= low && qhigh>= high) // total overlap
        return segtree[pos];
    if(qlow > high || qhigh < low) // no overlap
        return {100000000,1};
    int mid = (low+high)/2;
    return min(query(low,mid,2*pos + 1) , query(mid+1, high, 2*pos + 2));
}
void dfs(int u)
{
    // mark vis of root
    arr[sz] = {vis[u],u};
    tin[u] = sz;
    tout[u] = sz;
    sz++;
    for (auto j : g[u])
    {
        if (!vis[j])
        {
            vis[j] = vis[u] + 1;
            dfs(j);
            arr[sz] = {vis[u],u};
            tout[u] = max(tout[u],sz);
            sz++;
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        
        cin >> a;
        for(int j=0;j<a;j++)
        {
            cin>>b;
            g[i].push_back(b);
        }
        
    }
    vis[0] = 1;
    dfs(0);
    build(0,sz-1,0);
    int q,u,v;
    // for(int i=0;i<pp;i++)
        // cout<<arr[i]<<" ";
    // cout<<"\n";
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        if(tin[u]<= tin[v])
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
        cout<<query(0,sz-1,0).second<<"\n";
    }
}