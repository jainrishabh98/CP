#include <bits/stdc++.h>
using namespace std;
double dp[201][201][201];
int main()
{
    int n, l, k;
    cin >> n >> l >> k;
    double p[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        p[i] /= 100.0;
    }
    int cap[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> cap[i];
        cap[i]++;
    }
    dp[0][0][k]=1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int m = 0; m <= 200; m++)
            {
                dp[i][j + 1][min(m + cap[i], 200)] += dp[i - 1][j][m] * p[i];
                dp[i][j][m] += dp[i - 1][j][m] * (1 - p[i]);
            }
        }
    }
    double ans = 0;
    for (int j = l; j <= n; j++)
    {
        for (int m = j; m <= 200; m++)
        {
            ans += dp[n][j][m];
        }
    }
    cout<<fixed;
    cout << setprecision(11)<<ans;
}