#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> vis;
queue<int> q;
int n, x, fl, Q;
int d[1001];
void bfs(int u)
{   
    vis[u]=1;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (vis.find(v - d[i]) == vis.end() && v - d[i] >= 0)
            {
                vis[v - d[i]] = 1;
                q.push(v - d[i]);
                if (v - d[i] == 0)
                {
                    fl = 1;
                    return;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    
    while (Q--)
    {
        cin >> x;
        fl = 0;
        bfs(x);
        if (fl == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
        while (!q.empty())
            q.pop();
        vis.clear();
    }
}