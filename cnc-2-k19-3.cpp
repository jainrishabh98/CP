#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int a[1005][1005];
int v[1005][1005];
int cnt;
void my_dfs(int x, int y)
{
    v[x][y] = 1;
    if (a[x][y] == 1)
        cnt++;
    if (v[x + 1][y] == 0 && a[x + 1][y] != 0)
    {
        my_dfs(x + 1, y);
    }
    if (v[x - 1][y] == 0 && a[x - 1][y] != 0)
    {
        my_dfs(x - 1, y);
    }
    if (v[x][y + 1] == 0 && a[x][y + 1] != 0)
    {
        my_dfs(x, y + 1);
    }
    if (v[x][y - 1] == 0 && a[x][y - 1] != 0)
    {
        my_dfs(x, y - 1);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                a[i][j] = 0;
            else
                cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i][j]==0 && a[i][j] != 0)
            {
                cnt = 0;
                my_dfs(i, j);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
}
