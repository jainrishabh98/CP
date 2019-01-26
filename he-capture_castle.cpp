#include<bits/stdc++.h>
using namespace std;
int n,m,t;
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
{
    cin>>t;
    while(t--)
    {
    cin>>m>>n;
    
    }
}