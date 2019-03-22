#include <bits/stdc++.h>
using namespace std;
int dist[5005][5005];
int cnt[5005];
int mn[5005];
set<int> g[5005];
int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        g[x].insert(y);
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i].empty())
            continue;
        int k = i;
        while (1)
        {
            if (binary_search(g[i].begin(), g[i].end(), k))
            {
                mn[i] = k;
                break;
            }
            k++;
            if (k > n)
                k = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
            {
                dist[i][j] = j - i;
            }
            else
            {
                dist[i][j] = n - (i - j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {

        int k = i;
        int mbb = 0;
        while (1)
        {
            if (mn[k] != 0)
                mbb = max(mbb, dist[i][k] + n * (cnt[k] - 1) + dist[k][mn[k]]);
            k++;
            if (k > n)
                k = 1;
            if (k == i)
                break;
        }
        cout << mbb << " ";
    }
}