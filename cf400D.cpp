#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
vector <ipair> g[100005];
int d[505][505];
int dist[100005];
bool vis[100005];
int mp[100005];
int c[505],s[505];
int INF = INT_MAX;
void shortestPath (int src)
{
    priority_queue <ipair, vector <ipair> , greater <ipair> > pq;
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for (auto i : g[u])
        {
            int v = i.first;
            int weight = i.second;
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
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            d[i][j] = INF;
        }
    }
    for(int i=0;i<k;i++) cin>>c[i];
    s[0] = 1;
    for(int i=1;i<k;i++) s[i] = s[i-1] + c[i-1];
    int jj = 1;
    for(int i=0;i<k;i++)
    {   int y = c[i];
        while(y--)
        {
            mp[jj] = i;
            jj++;
        }
    }
    int u,v,x;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>x;
        g[u].push_back(make_pair(v,x));
        g[v].push_back(make_pair(u,x));
    }
    
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[j] = INF;
            vis[j] = false;
        }
        shortestPath(s[i]);
        for(int j=1;j<=n;j++)
        {   
            
            if(j==s[i] && c[i]!=1) {continue;}
            d[i][mp[j]] = min(d[i][mp[j]],dist[j]);
        }
        
    }
    
    for(int i=0;i<k;i++)
    {
        if(d[i][i]!=0) 
        {
            cout<<"No";return 0;
        }
    }
    cout<<"Yes\n";
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(d[i][j]==INF)
                cout<<"-1 ";
            else
                cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
}