#include<bits/stdc++.h>
using namespace std;
vector <int> g[100005];
int val[100005];
long long ans[100005];
long long m = 1e9 + 7;
void dfs(int u,int p)
{
    int temp = val[u];long long int f = 1;
    while(temp!=1)
    {
        if(temp%2==0)
        {
            f *= 2;
        }
        temp /= 2;
    }
    ans[u] = (ans[p]*f)%m;
    for(auto i:g[u])
    {
        if(i!=p)
        {
            dfs(i,u);
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    int a;
    for(int i=2;i<=n;i++)
    {
        cin>>a;
        g[a].push_back(i);
        g[i].push_back(a);
    }
    ans[0]=1;
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}