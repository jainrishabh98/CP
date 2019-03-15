#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;
vector<ipair> g[100005];
map<int, int> t[100005];
vector<int> dist;
bool vis[100005];
int INF = INT_MAX;
int n;
void shortestPath(int src)
{
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    dist[src] = 0;
    if (t[src].find(dist[src]) != t[src].end())
    {
        dist[src] += t[src][dist[src]];
    }
    pq.push(make_pair(dist[src], src));
    while (!pq.empty())
    {
        int u = pq.top().second;
        if (u == n)
            break;
        pq.pop();
        if(vis[u]==true) continue;
        vis[u] = true;
        for (auto i : g[u])
        {
            int v = i.first;
            int weight = i.second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                if (v != n)
                {
                    if (t[v].find(dist[v]) != t[v].end())
                    {
                        dist[v] += t[v][dist[v]];
                    }
                }
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, a, b, wt;
    cin >> n >> m;
    dist.assign(n + 1, INF);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> b;
            t[i][b] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (t[i].size() >= 2)
        {
            auto itr = t[i].end();
            itr--;
            auto ihr = itr;
            itr--;
            while (itr != t[i].begin())
            {
                if (ihr->first - itr->first == 1)
                    itr->second += ihr->second;
                ihr = itr;
                itr--;
            }
            if (ihr->first - itr->first == 1)
                itr->second += ihr->second;
        }
    }
    shortestPath(1);
    if (dist[n] == INF)
        cout << "-1";
    else
        cout << dist[n];
}