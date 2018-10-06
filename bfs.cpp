// BFS implementation of unweighted graph in STL

#include<bits/stdc++.h>
using namespace std;
vector <bool> v;
vector <vector<int>> g;
void edge(int a, int b)
{
    g[a].push_back(b);
    //for undirected graph, write 
    // g[b].push_back(a);
}

void my_bfs(int u )
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
            if(!v[*i])
            {
                q.push(*i);
                v[*i] = true;
            }
        }

    }
}
int main ()
{
        int n,e;
        cin>>n>>e;
        v.assign(n, false);
        g.assign(n, vector <int> ());

        int a,b;
        for (int i=0; i<e; i++)
        {
            cin>>a>>b;
            edge(a,b);
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