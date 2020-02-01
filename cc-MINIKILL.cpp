#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000001];
vector <int> g[1000001];
void dfs(int u,int p)
{
    ll t = 0,fl=0;
    for(auto i:g[u])
    {
        if(i!=p)
        {
            dfs(i,u);
            t += max(1LL,dp[i]);
            if(dp[i] >= 1)
                fl=1;
        }
    }
    if(fl==0)
        t--;
    dp[u] = t;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,u,v;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<max(1LL,dp[1]);
}