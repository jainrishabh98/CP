#include<bits/stdc++.h>
using namespace std;
vector <int> g[100005];
map <int,int> gg[3];
int vis[100005];
int main ()
{
    long long int n,m,a,b;
    cin>>n>>m;
    pair <int,int> p[m+1];
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        p[i].first=a;
        p[i].second=b;
    }
    for(auto i:g[1])
    {
        vis[i] = 1;
    }
    int st=-1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            gg[0][i] = 1;
        }
        else
        {
            st = i;
        }
    }
    if(st==-1)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        if(gg[0].find(i)!=gg[0].end())
            vis[i]=1;
    }
    for(auto i:g[st])
    {
        if(vis[i]==0)
            gg[1][i]=1;
        vis[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            gg[2][i]=1;
    }
    if(gg[2].empty() || gg[1].empty() || gg[0].empty())
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        a = p[i].first;
        b = p[i].second;
        for(int j=0;j<3;j++)
        {
            if(gg[j].find(a)!=gg[j].end() && gg[j].find(b)!=gg[j].end())
            {
                cout<<-1;
                return 0;
            }
        }
    }
    a = gg[0].size();
    b = gg[1].size();
    long long int c = gg[2].size();
    if(a*b + b*c + a*c != m)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<3;i++)
    {
        for(auto j:gg[i])
        {
            vis[j.first] = i+1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<vis[i]<<" ";
    }
}