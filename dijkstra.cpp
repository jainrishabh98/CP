#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
vector <vector<ipair>> g;
vector <int> dist;
long long int INF = INT_MAX;
void addedge(int u,int v,int wt)
{
    g[u].push_back(make_pair(wt,v));
    g[v].push_back(make_pair(wt,u));
}
void shortestPath (int src)
{
    priority_queue <ipair, vector <ipair> , greater <ipair> > pq;
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto i : g[u])
        {
            int weight = i.first;
            int v = i.second;
            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}
int main ()
{
    int n,m;
    cin>>n>>m;
    g.assign(n,vector<ipair>());
    dist.assign(n,INF);
    int a,b,w;
    for (int i=0; i<m; i++)
    {
        cin>>a>>b>>w;
        addedge(a,b,w);
    }
    int src;
    cin>>src;
    shortestPath(src);
    cout<<"Vertex Distance from Source\n";
    for (int i=0;i<n;i++)
        cout<<i<<" "<<dist[i]<<"\n";
    
    return 0;
}