#include <bits/stdc++.h>
using namespace std;
vector <int> g[100005];
long long int v[100005],mp[100005],mn[100005];
void my_dfs(int u,int p)
{
    
    for (auto j:g[u])
    {
        if(j!=p)
        {  
            my_dfs(j,u);
            mp[u] = max(mp[u],mp[j]);
            mn[u] = max(mn[u],mn[j]);
        }
    }
    v[u] = v[u] - mp[u] + mn[u];
    if(v[u]>0) mp[u] += v[u];
    else mn[u] -= v[u];
}
int main ()
{
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    my_dfs(1,0);
    cout<<mp[1]+mn[1];
}