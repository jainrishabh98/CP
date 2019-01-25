#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <int> g[10001];
int vis[10001];
queue <int> q;
void bfs(int u)
{
    vis[u]=1;
    q.push(u);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto i:g[v])
        {
            if(!vis[i])
            {
                vis[i]=vis[v]+1;
                q.push(i);
            }
        }
        g[v].clear();
    }
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int x,y;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        bfs(1);
        cout<<vis[n]-1<<"\n";
    }

}