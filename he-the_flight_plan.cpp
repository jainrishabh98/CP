#include<bits/stdc++.h>
using namespace std;
set <int> g[1001];
int vis[1001];
queue <int> q;
int n,m,x,y,t,c;
int par[1001];
void my_bfs(int u)
{
    // cout<<u;
    vis[u]=true;
    par[u]=u;
    q.push(u);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto i:g[v])
        {
            if(!vis[i])
            {   
                par[i] = v;
                vis[i]=true;
                if(i==y)   return;
                q.push(i);
            }
        }
    }
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>t>>c;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }
    cin>>x>>y;
    my_bfs(x);
    vector <int> ans;
    int i=y;
    while(par[i]!=i)
    {
        ans.push_back(i);
        i = par[i];
    }
    ans.push_back(x);
    cout<<ans.size()<<"\n";
    for(int j=ans.size()-1;j>=0;j--)
    {
        cout<<ans[j]<<" ";
    }

}