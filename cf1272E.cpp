#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ipair;
ll dist[200005];
vector<ll> g[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (i - a[i] >= 1)
        {
            g[i - a[i]].push_back(i);
            if ((a[i] % 2 == 0 && a[i - a[i]] % 2 != 0) || (a[i] % 2 != 0 && a[i - a[i]] % 2 == 0))
            {
                dist[i] = 1;
                pq.push(i);
            }
        }
        if (i + a[i] <= n)
        {
            g[i + a[i]].push_back(i);
            if (dist[i] != 1)
            {
                if ((a[i] % 2 == 0 && a[i + a[i]] % 2 != 0) || (a[i] % 2 != 0 && a[i + a[i]] % 2 == 0))
                {
                    dist[i] = 1;
                    pq.push(i);
                }
            }
        }
    }
    while (!pq.empty())
    {
        int u = pq.front();
        // cout << u << " ";
        pq.pop();
        for (auto i : g[u])
        {
            if (!dist[i])
            {
                dist[i] = dist[u] + 1;
                pq.push(i);
            }
        }
    }
    // cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (!dist[i])
        {
            cout << -1 << " ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
}