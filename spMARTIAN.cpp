#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll y[501][501];
ll b[501][501];
ll dp[501][501][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> y[i][j];
                y[i][j] += y[i][j - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> b[i][j];
                b[i][j] += b[i - 1][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j][0] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + b[i][j];
                dp[i][j][1] = max(dp[i - 1][j][0], dp[i - 1][j][1]) + y[i][j];
            }
        }
        cout << max(dp[n][m][0], dp[n][m][1]) << "\n";
    }
}