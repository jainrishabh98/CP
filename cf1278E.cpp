#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int> g[500005];
int le[500005];
int ri[500005];
int rr;
void dfs(int u,int p)
{
    le[u] = rr - g[u].size();
    if(p==0)
        le[u]--;
    rr = le[u];
    int cnt = 1;
    for(auto i:g[u])
    {
        if(i!=p)
        {
            dfs(i,u);
            ri[i] = le[u] + cnt;
            cnt++;
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,x,y;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    rr = 2*n;
    ri[1] = rr;
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<le[i]<<" "<<ri[i]<<"\n";
    }
}