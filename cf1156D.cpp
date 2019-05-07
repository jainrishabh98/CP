#include <bits/stdc++.h>
using namespace std;
vector<int> g[2][200005];
int mp[2][200005];
long long int vis[2][200005];
int ch=-1;
long long int cnt;
vector <int> pb;
void dfs(int u)
{
    cnt++;
    // cout<<u<<" ";
    pb.push_back(u);
    vis[ch][u] = 1;
    for(auto j:g[ch][u])
    {
        // cout<<j<<" ";
        if(!vis[ch][j])
        {
            dfs(j);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int x, y, c;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y >> c;
        g[c][x].push_back(y);
        g[c][y].push_back(x);
        mp[c][x] = 1;
        mp[c][y] = 1;
    }
    long long int ans = 0;
    ch = 0;
    for(int i=1;i<=n;i++)
    {
        if(mp[0][i]==1 && vis[0][i]==0)
        {
            cnt = 0;
            pb.clear();
            dfs(i);
            ans += cnt*(cnt-1);
            for(auto k:pb)
            {
                // cout<<k<<" ";
                vis[0][k] = cnt;
            }
            // cout<<"\n";
        }
    }
    ch=1;
    for(int i=1;i<=n;i++)
    {
        if(mp[1][i]==1 && vis[1][i]==0)
        {
            cnt = 0;
            pb.clear();
            dfs(i);
            ans += cnt*(cnt-1);
            for(auto k:pb)
            {
                // cout<<k<<" ";
                vis[1][k] = cnt;
            }
            // cout<<"\n";
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[0][i]==1 && mp[1][i]==1)
        {
            ans += (vis[0][i]-1)*(vis[1][i]-1);
        }
    }
    cout<<ans;
}