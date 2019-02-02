#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector <int> g[2][100005];
int tree[2][100005];
int tin[2][100005];
int tout[2][100005];
int vis[100005];
int timer;
int n;
ll query(int k,int c)
{
    ll s = 0;
    while(k>=1)
    {
        s += tree[c][k];
        k -= (k&(-k));
    }
    return s;
}
void update(int k,ll x,int c)
{
    while(k<=n)
    {
        tree[c][k] += x;
        k += (k&(-k));
    }
}
void dfs(int u,int c)
{
    tin[c][u] = ++timer;
    for(auto i:g[c][u])
    {
        if(i!=u)
        {
            dfs(i,c);
        }
    }
    tout[c][u] = timer;
}
int main ()
{
    int n,q,a,b;
    cin>>n>>q;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        g[0][a].push_back(b);
        g[0][b].push_back(a);
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        g[1][a].push_back(b);
        g[1][b].push_back(a);
    }
    int t,p;
    dfs(1,0);
    dfs(1,1);
    while(q--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>a>>b>>p;
            if(query(n,0) > query(n,1))
            {
                
            }
            else
            {
                
            }
        }
        else
        {
            cin>>a>>p;
            if(query(n,0) > query(n,1))
            {
                update(tin[1][a],p,1);
            }
            else
            {
                update(tin[0][a],p,0);
            }
        }
    }
}