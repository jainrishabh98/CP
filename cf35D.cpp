#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int n, x;
    cin >> n >> x;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        c[i] = c[i] * (n - i);
    }
    int dp[n + 1][x + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= x; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
                continue;
            }
            dp[i][w] = dp[i - 1][w];
            if (c[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - c[i - 1]] + 1);
            }
        }
    }
    cout << dp[n][x];
}