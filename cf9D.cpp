#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
unsigned long long int dp[38][38];
int main()
{
    int n, h;
    cin >> n >> h;
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                for (int k = 1; k <= j; k++)
                {
                    dp[i][j] += (dp[0][k - 1] * dp[0][j - k]);
                }
            }
            else if (j < i)
            {
                dp[i][j] = 0;
            }
            else
            {
                for (int k = 1; k <= j; k++)
                {
                    if (k >= i && j - k >= i - 1)
                    {
                        ull temp = (max((ull)1, dp[i - 1][k - 1]) * max((ull)1, dp[0][j - k]));
                        temp += ((max((ull)1, dp[0][k - 1])-max((ull)1,dp[i-1][k-1])) * max((ull)1, dp[i - 1][j - k]));
                        dp[i][j] += temp;
                    }
                    else if (k >= i)
                    {
                        dp[i][j] += (max((ull)1, dp[i - 1][k - 1]) * max((ull)1, dp[0][j - k]));
                    }
                    else if (j - k >= i - 1)
                    {
                        dp[i][j] += (max((ull)1, dp[0][k - 1]) * max((ull)1, dp[i - 1][j - k]));
                    }
                }
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    cout<<dp[h][n];
}