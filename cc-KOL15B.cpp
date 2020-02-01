#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1005][1005];
ll pre1[1005][1005];
ll pre2[1005][1005];
ll pre3[1005][1005];
ll pre4[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        for (int i = 0; i <= n+1; i++)
        {
            for (int j = 0; j <= m+1; j++)
            {
                if(!(j==0 || i==0 || j==m+1 || i==n+1))
                    cin >> a[i][j];
                pre1[i][j] = pre2[i][j] = pre3[i][j] = pre4[i][j] = INT_MAX;

            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pre1[i][j] = min(pre1[i][j - 1] + a[i][j], a[i][j]);
                pre4[i][m - j + 1] = min(pre4[i][m - j + 2] + a[i][m - j + 1], a[i][m - j + 1]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pre2[i][j] = min(pre2[i - 1][j] + a[i][j], a[i][j]);
                pre3[n - i + 1][j] = min(pre4[n - i + 2][j] + a[n - i + 1][j], a[n - i + 1][j]);
            }
        }
        ll ans = 1000000;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ans = min(ans, pre1[i][j] + pre2[i][j] + pre3[i][j] + pre4[i][j] - 3 * a[i][j]);
            }
        }
        cout << ans << "\n";
    }
}