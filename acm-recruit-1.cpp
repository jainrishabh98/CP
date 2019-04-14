#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
vector <int> g[100005];
ll dp[100005][2];
ll m = 1e9 + 7;
void my_dfs(int u,int par)
{
    for (auto j:g[u])
    {
        if(j!=par)
        {  
            my_dfs(j,u);
            ll temp = 1;
            ll temp2 = 1;
            for(auto k:g[j])
            {
                if(k!=u)
                {
                (temp *= dp[k][1])%=m;
                (temp2 *= dp[k][0])%=m;
                }
            }
            (temp += dp[j][1])%=m;
            (temp2 += dp[j][0])%=m;
            (dp[u][0] *= temp)%=m;
            (dp[u][1] *= temp2)%=m;
        }
    }
}
int main ()
{
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    my_dfs(1,0);
    cout<<(dp[1][0] + dp[1][1])%m;
    
}