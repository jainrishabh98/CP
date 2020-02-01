#include<bits/stdc++.h>
using namespace std;
vector <int> g[1000005];
int dirty[1000005];
long long int dfs(int u,int p)
{
    long long int sum =0;
    for(auto i:g[u])
    {
        if(i!=p)
        {
            sum += dfs(i,u);
        }
    }
    if(dirty[u]==1)
    {
        sum = max((long long)1,sum);
    }
    return sum;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<1000005;i++)
        {
            g[i].clear();
            dirty[i]=0;
        }
        int n,x;
        cin>>n>>x;
        int a,b;
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0;i<x;i++)
        {
            cin>>a;
            dirty[a] = 1;
        }
        long long int ans = dfs(1,0);
        cout<<ans-1<<"\n";
    }
}