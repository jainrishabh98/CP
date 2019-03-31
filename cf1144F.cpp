#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> g[200005];
bool vis[200005];
int val[200005];
int flag;
void my_dfs(int u, int p)
{
    vis[u] = true;
    val[u] = p;
    for (auto j : g[u])
    {
        if (!vis[j])
        {
            my_dfs(j, p ^ 1);
        }
        else if (val[j] == p)
        {
            flag = 1;
        }
    }
}
int main()
{
    int n, m, u, v;
    cin >> n >> m;
    int s[m],c[m];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        s[i] = u;
        c[i] = v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    flag = 0;
    my_dfs(1, 0);
    if (flag == 1)
    {
        cout << "NO";
        return 0;
    }
    cout<<"YES\n";
    for(int i=0;i<m;i++)
    {
        cout<<val[s[i]];
    }
}