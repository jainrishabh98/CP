#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP1(i, n) for (ll i = 1; i <= n; i++)
ll dp[51][51][51][51];
int main()
{
    int n;
    cin >> n;
    ll d[n + 1][n + 1];
    char x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            d[i][j] = 0;
            if (x == '#')
                d[i][j] = 1;
        }
    }
    REP1(l1, n) // 1st side of rectangle
    {

        for (int i = 1; i + l1 - 1 <= n; i++)
        {
            REP1(l2, n) // 2nd side of rectangle
            {

                for (int j = 1; j + l2 - 1 <= n; j++)
                {
                    ll a = i + l1 - 1;
                    ll b = j + l2 - 1;
                    ll &p = dp[i][j][a][b];
                    if (l1 == 1 && l2 == 1 && !d[i][j])
                        p = 0;
                    else
                        p = max(l1, l2);
                    for (int k = i; k < a; k++)
                        p = min(p, dp[i][j][k][b] + dp[k + 1][j][a][b]);
                    for (int k = j; k < b; k++)
                        p = min(p, dp[i][j][a][k] + dp[i][k + 1][a][b]);
                }
            }
        }
    }
    cout << dp[1][1][n][n];
}