// DFS implementation of unweighted graph in STL

#include<bits/stdc++.h>
using namespace std;
vector <bool> v;
vector <vector <int>> g;
void edge (int a, int b)
{
    g[a].push_back(b);
    // for undirected graph write
    //g[b].push_back(a);
}
void my_dfs(int u)
{
    v[u] = true;
    cout<<u<<" ";
    for (auto j= g[u].begin(); j!= g[u].end();j++)
    {
        if(!v[*j])
        {  
            my_dfs(*j);
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
        cout<<"\nAdjacency List Representation of Graph\n"
        for (int i=0; i<n; i++)
        {
            for(auto j= g[i].begin(); j!= g[i].end();j++)
            {
                cout<<(*j)<<" ";
            }
            cout<<"\n";
        }
        for (int i=0; i<n; i++)
        {
            if(!v[i])
            {
                my_dfs(i);
            }
        }
}