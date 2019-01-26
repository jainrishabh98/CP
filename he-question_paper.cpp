#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt;
int vis[4000006];
queue <int> q;
void bfs(int u)
{
    vis[u]=1;
    q.push(u);
    while(!q.empty())
    {   
        cnt++;
        int v = q.front();
        q.pop();
        // cout<<v<<" ";
        if(vis[v]==n+1) continue;
        if(!vis[v+a])
            {
                vis[v+a]=vis[v]+1;
                q.push(v+a);
            }
        if(!vis[v-b])
            {
                vis[v-b]=vis[v]+1;
                q.push(v-b);
            }
    }
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n>>a>>b;
    memset(vis,0,sizeof(vis));
    cnt=0;
    bfs(n*b); //shifting origin to n*b i.e 0 -> n*b
    cout<<cnt<<"\n";
    }
}