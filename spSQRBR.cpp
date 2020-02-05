#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[40];
ll dp[40][40];
int n;
ll rec(int i, int num)
{
    if(dp[i][num]!=-1)
        return dp[i][num];
    if(num < 0)
        return 0;
    if(num == 0 && i == 2*n+1)
        return 1;
    if(i == 2*n + 1)
        return 0;
    if(vis[i])
        return dp[i][num] = rec(i+1,num+1);
    return dp[i][num] = (rec(i+1,num+1)+rec(i+1,num-1));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int k,x;
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        for(int i=0;i<k;i++)
        {
            cin>>x;
            vis[x] = true;
        }
        cout<<rec(1,0)<<"\n";
    }
}