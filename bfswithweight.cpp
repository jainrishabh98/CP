// BFS implementation of weighted graph in STL

#include<bits/stdc++.h>
using namespace std;
vector <bool> v;
vector <vector<pair<int, int>>> g;
void edge(int a, int b, int wt)
{
    g[a].push_back(make_pair(b,wt));
    //for undirected graph, write 
    // g[b].push_back(make_pair(a,wt));
}

void my_bfs(int u)
{
    queue <int> q;
    q.push(u);
    v[u] = true;

    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        cout<<f<<" ";
        for (auto i = g[f].begin(); i!=g[f].end(); i++)
        {
            if(!v[(i->first)])
            {
                q.push((i->first));
                v[(i->first)] = true;
            }
        }

    }
}
int main ()
{
        int n,e;
        cin>>n>>e;
        v.assign(n, false);
        g.assign(n, vector <pair<int,int>> ());

        int a,b,wt;
        for (int i=0; i<e; i++)
        {
            cin>>a>>b>>wt;
            edge(a,b, wt);
        }
        for (int i=0; i<n; i++)
        {
            if(!v[i])
            {
                my_bfs(i);
            }
        }
    return 0;
}