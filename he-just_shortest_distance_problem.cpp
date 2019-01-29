#include<bits/stdc++.h>
using namespace std;
vector <int> g[1001];
int dist[1001];
queue <int> q;
void bfs(int u)
{
    q.push(u);
    while(!q.empty())
    {
    int v = q.front();
    q.pop();
    for(auto i:g[v])
    {
        if(dist[i] > dist[v] + 1)
            {
                dist[i] = dist[v] + 1;
                q.push(i);
            }
    }
    }
}
int main ()
{   ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    for(int i=2;i<=1000;i++)
    {
        dist[i] = 1e9;
    }
    cin>>n>>m;
    int a,x,y;
    while(m--)
    {
        cin>>a;
        if(a==1)
        {
            cin>>x;
            if(dist[x]==1e9)
                cout<<"-1\n";
            else
                cout<<dist[x]<<"\n";
            
        }
        else
        {
            cin>>x>>y;
            g[x].push_back(y);
            if(dist[y] > dist[x] + 1)
            {
                dist[y] = dist[x] + 1;
                bfs(y);
            }
            
        }
    }
}