#include <bits/stdc++.h>
using namespace std;
vector<int> g[202];
bool v[202];
int cnt, mx;
void my_dfs(int u, int par)
{
    cnt++;
    v[u] = true;
    mx = max(mx, cnt);
    for (auto k : g[u])
    {
        if (k != par)
        {
            my_dfs(k, u);
        }
    }
    cnt--;
}
int main()
{
    int n;
    cin >> n;
    int a[n - 1], b[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g[j].clear();
            v[j] = false;
        }
        for (int j = 0; j < n - 1; j++)
        {
            if (j == i)
                continue;
            g[a[j]].push_back(b[j]);
            g[b[j]].push_back(a[j]);
        }
        int mx1 = 0, mx2 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (g[j].size() <= 1)
            {
                cnt = 0;
                mx = 0;
                my_dfs(j, 0);
                if (v[a[i]])
                {
                    mx1 = max(mx1, mx - 1);
                    v[a[i]] = false;
                }
                else
                {
                    mx2 = max(mx2, mx - 1);
                    v[b[i]] = false;
                }
            }
        }
        ans = max(ans, mx1 * mx2);
    }
    cout << ans;
}