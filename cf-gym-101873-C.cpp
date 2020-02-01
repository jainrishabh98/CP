#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> g[1001];
ll cost[1001], tmmm[1001], dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x, n, m, t, a, b;
    cin >> x >> n >> m >> t;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> tmmm[i] >> cost[i];
        g[i].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = 1000000000000000000;
        }
    }
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    pq.push({cost[1], {1, tmmm[1]}});
    dp[1][tmmm[1]] = cost[1];
    ll ans = -1;
    while (!pq.empty())
    {
        ll cc = pq.top().first;
        ll node = pq.top().second.first;
        ll tim = pq.top().second.second;
        pq.pop();
        if (node == 1 && tim == x)
        {
            ans = cc;
            break;
        }
        for (auto i : g[node])
        {
            if (i != node)
            {
                if (tim + t + tmmm[i] <= x)
                {
                    if (cc + cost[i] < dp[i][tim + t + tmmm[i]])
                    {
                        dp[i][tim + t + tmmm[i]] = cc + cost[i];
                        pq.push({cc + cost[i], {i, tim + t + tmmm[i]}});
                    }
                }
            }
            else
            {
                if (tim + tmmm[i] <= x)
                {
                    if (cc + cost[i] < dp[i][tim + tmmm[i]])
                    {
                        dp[i][tim + tmmm[i]] = cc + cost[i];
                        pq.push({cc + cost[i], {i, tim + tmmm[i]}});
                    }
                }
            }
        }
    }
    if (ans == -1)
    {
        cout << "It is a trap.";
    }
    else
        cout << ans;
}