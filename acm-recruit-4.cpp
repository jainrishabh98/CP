#include <bits/stdc++.h>
using namespace std;
int v[100005];
vector<vector<int>> g;
int tin[100005];
int tout[100005];
int par[100005];
int vali[100005];
vector <pair<int,int>> segtree;
vector <pair<int,int>> arr;
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
void my_dfs(int u,int parr)
{
    
    if(vali[u] >= vali[par[parr]])
    {
        par[u] = u;
    }
    else
    {
        par[u] = par[parr];
    }
    arr.push_back({v[u],u});
    tin[u] = sz;
    tout[u] = sz;
    sz++;
    for (auto j :g[u])
    {
        if (!v[j])
        {
            v[j] = v[u] + 1;
            my_dfs(j,u);
            arr.push_back({v[u],u});
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
    g.assign(n, vector<int>());
    for(int i=0;i<n;i++)
    {
        cin>>vali[i];
    }
    int a, b;
    for (int i = 0; i < n-1; i++)
    {
        
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        
    }
    par[0] = 0;
    v[0] = 1;
    my_dfs(0,0);
    int pp = sz;
    int temp = (int)(ceil(log2(pp)));
    int max_size = 2*(int)pow(2,temp) -1;
    segtree.assign(max_size,{0,0});
    build(0,pp-1,0);
    int q,u,v;
    // for(int i=0;i<pp;i++)
        // cout<<arr[i]<<" ";
    // cout<<"\n";
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        u--;v--;
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
        int p = query(0,pp-1,0).second;
        // cout<<p<<" ";
        int best = par[p];
        cout<<best+1<<"\n";

    }
}