#include <bits/stdc++.h>
using namespace std;
long long int dp1[1001][1001] = {0};
long long int dp2[1001][1001] = {0};
long long int dp3[1001][1001] = {0};
long long int dp4[1001][1001] = {0};
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    for (int j = m; j >= 1; --j)
        for (int i = 1; i <= n; ++i)
            dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = a[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);

    long long int ans = 0, result = 0;
    for (int i = 2; i <=n - 1; i++)
    {
        for (int j = 2; j <= m - 1; j++)
        {
            // cout << dp1[i - 1][j] + dp4[i + 1][j] + dp3[i][j - 1] + dp2[i][j + 1] << " " << dp1[i][j - 1] + dp4[i][j + 1] + dp3[i + 1][j] + dp2[i - 1][j] << "\n";
            ans = max(dp1[i - 1][j] + dp4[i + 1][j] + dp3[i][j - 1] + dp2[i][j + 1], dp1[i][j - 1] + dp4[i][j + 1] + dp3[i + 1][j] + dp2[i - 1][j]);
            result = max(result, ans);
        }
    }
    cout << result << "\n";
    return 0;
}