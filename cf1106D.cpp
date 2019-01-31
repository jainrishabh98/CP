#include<bits/stdc++.h>
using namespace std;
typedef int ipair;
vector <vector<ipair>> g;
int vis[100005];
void addedge(int u,int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
void shortestPath ()
{
    priority_queue <ipair, vector <ipair> , greater <ipair> > pq;
    pq.push(1);
    vis[1]=1;
    while(!pq.empty())
    {
        int u = pq.top();
        cout<<u<<" ";
        pq.pop();
        for (auto i : g[u])
        {
            if(!vis[i])
            {
                vis[i]=1;
                pq.push(i);
            }
        }
    }
}
int main ()
{
    int n,m;
    cin>>n>>m;
    g.assign(n+1,vector<ipair>());
    int a,b;
    for (int i=0; i<m; i++)
    {
        cin>>a>>b;
        addedge(a,b);
    }
    shortestPath();
    return 0;
}