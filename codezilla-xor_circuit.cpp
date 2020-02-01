#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector <int> g[100005];
ll m = 1e9 + 7;
ll ans = 0;
ll power(ll x,ll y)
{
    if(y==0)
        return 1;
    ll p = power(x,y/2);
    p = (p*p)%m;
    if(y%2!=0)
        (p*=x)%=m;
    return p;
}
void dfs(int u,int p)
{
    for(auto i:g[u])
    {
        if(i!=p)
        {
            dfs(i,u);
        }
    }
    if(g[u].size()==1 && u!=1)
    {
        ans++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x,y;
        cin>>n;
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
        }
        for(int i=1;i<=n-2;i++)
        {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1,0);
        if(n==2)
            ans++;
        cout<<power(4,n-ans)<<"\n";
    }

}