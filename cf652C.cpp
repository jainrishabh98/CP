#include <bits/stdc++.h>
using namespace std;
vector<int> g[300005];
int vis[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int i = 0, j = 0;
    long long int ans = 0;
    while (i < n && j < n)
    {
        while (j < n)
        {
            if (vis[p[j]] == 0)
            {
                for (auto k : g[p[j]])
                {
                    vis[k] = j + 1;
                }
            }
            else
                break;
            j++;
        }

        if (j == n)
        {
            long long int l = j - i;
            ans += (l * (l + 1)) / 2;
            break;
        }
        else
        {
            int k;
            for (k = i; k < vis[p[j]]; k++)
            {
                ans += j-k;
                for (auto kk : g[p[k]])
                {
                    if (vis[kk] == k + 1)
                    {
                        vis[kk] = 0;
                    }
                }
            }
            i = k;
        }
    }
    cout << ans;
}