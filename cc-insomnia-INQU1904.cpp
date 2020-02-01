#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[100005];
vector<int> g[100005];
ll dp[100005][3];
ll ans = 0;
void dfs(int u, int p)
{
    ll b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0,pos1=-1,pos2=-1;
    for (auto i : g[u])
    {
        if (i != p)
        {
            dfs(i, u);
            if (dp[i][0] >= b1)
                b2 = b1, b1 = dp[i][0];
            else if (dp[i][0] > b2)
                b2 = dp[i][0];
            if (dp[i][1] >= b3)
                b4 = b3, b3 = dp[i][1],pos1 = i;
            else if (dp[i][1] > b4)
                b4 = dp[i][1];
            if (dp[i][2] >= b5)
                b6 = b5, b5 = dp[i][2],pos2 = i;
            else if (dp[i][2] > b6)
                b6 = dp[i][2];
            if(dp[i][1] > b5)
                b5 = dp[i][1],pos2 = i;
        }
    }
    ans = max(ans,b1);
    ans = max(ans,b3);
    ans = max(ans,b5);
    ans = max(ans,b1+b2);
    ans = max(ans,b3+b4+a[u]);
    ans = max(ans,b3+b4);
    if(pos2!=pos1)
        ans = max(ans,b5+b3+a[u]);
    else
        ans = max(ans,b5+b4+a[u]), ans = max(ans,b6 + b3 + a[u]);
    if (g[u].size()!=1)
    {
        dp[u][0] = max(b1, b3 + a[u]);
        dp[u][1] = max((ll)(0), b3 + a[u]);
        dp[u][2] = max(a[u] + b1, b1);
        dp[u][2] = max(dp[u][2], b5);
    }
    else
    {
        dp[u][0] = max((ll)0, a[u]);
        dp[u][1] = max((ll)0, a[u]);
        dp[u][2] = max((ll)0, a[u]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            g[i].clear();
            dp[i][0] = 0;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        ll x, y;
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ans = 0;
        dfs(1, 0);
        cout << ans << "\n";
    }
}
