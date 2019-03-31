#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> g[500005];
int vis[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    char c[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    ll ans = 0;
    int prev = 0;
    ll c1=0,c2=0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (vis[u] != prev)
        {
            prev = vis[u];
            ans += min(c1, c2);
            // cout<<ans<<"\n";
            c1 = 0;
            c2 = 0;
        }
        if(c[u-1]=='(')
            c1++;
        else 
            c2++;
        for (auto j : g[u])
        {
            if (!vis[j])
            {
                vis[j] = vis[u] + 1;
                q.push(j);
            }
        }
    }
    ans += min(c1,c2);
    cout<<ans;
}