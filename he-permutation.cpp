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
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)    cin>>a[i];

}