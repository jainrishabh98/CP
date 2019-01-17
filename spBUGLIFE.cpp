#include <bits/stdc++.h>
using namespace std;
vector<bool> v;
vector<vector<int>> g;
int gen[2001];
void edge(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}
int flag=0;
void my_dfs(int u)
{
    v[u] = true;
    // cout<<u<<" ";
    for (auto j = g[u].begin(); j != g[u].end(); j++)
    {
        if (!v[*j])
        {   
            if(gen[u]==0) gen[*j]=1;
            else gen[*j]=0;
            my_dfs(*j);
        }
        else if(gen[u]==gen[*j]) flag=1;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int j=1;j<=t;j++)
    {
        int n, e;
        cin >> n >> e;
        v.assign(n, false);
        g.assign(n, vector<int>());
        memset(gen,0,sizeof(gen));
        int a, b;
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b;
            edge(a-1, b-1);
        }
        flag=0;
        for (int i = 0; i < n; i++)
        {
            if (!v[i])
            {   gen[i]=0;
                my_dfs(i);
            }
        }
        cout<<"Scenario #"<<j<<":\n";
        if(flag==0)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
    }
}