#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector <int> g[2002];
ll m = 1e9 + 7;
bool vis[2002];
bool vvis[2002];
ll d,v;
ll a[2002];
ll f[2002];
void dfs(int u)
{
    vis[u] = true;
    f[u] = 1;
    for(auto i:g[u])
    {
        if(!vis[i] && a[i]>=v && a[i] <= v + d)
        {        
            if(a[i]==v && vvis[i]==true)
                continue;
            dfs(i);
            (f[u] *= (f[i] + 1))%=m;
        }
    }
}
int main ()
{
    ll n,x,y;
    cin>>d>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll s = 0;
    for(int i=1;i<=n;i++)
    {   
        v = a[i];
        memset(vis,false,sizeof(vis));
        memset(f,0,sizeof(f));
        dfs(i);
        vvis[i] = true;
        // cout<<f[i]<<" ";
        (s += f[i])%=m;
    }
    cout<<s;
}