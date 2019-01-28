#include<bits/stdc++.h>
using namespace std;
vector <int> g[100001];
int vis[100001];
int n,m,t,a,b,par;
int p[100001],q[100001];
queue <int> qu;
void bfs(int u)
{
    vis[u] = par;
    qu.push(u);
    while(!qu.empty())
    {
        int v = qu.front();
        qu.pop();
        for(auto i:g[v])
        {
            if(!vis[i])
            {
                vis[i] = par;
                qu.push(i);
            }
        }

    }
}
int main ()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)   { vis[i]=0;cin>>a;p[a]=i;}
        for(int i=1;i<=n;i++)   { g[i].clear();cin>>b;q[b]=i;}
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        par=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
               { bfs(i);
                 par++;
               }
        }
        int flag=0;
        for (int i=1;i<=n;i++)
        {
            // cout<<p[i]<<" "<<q[i]<<" "<<vis[p[i]]<<" "<<vis[q[i]]<<"\n";
            if(p[i]!=q[i] && vis[p[i]]!=vis[q[i]])  {flag=1;break;}
        }
        if(flag==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}