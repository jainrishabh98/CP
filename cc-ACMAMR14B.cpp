#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll m, n;
        cin >> m >> n;
        ll a[m + 2][n + 2];
        ll pre[m + 2][n + 2];
        ll pro[m + 2][n + 2];
        for (int i = 0; i <= m + 1; i++)
        {
            for (int j = 0; j <= n + 1; j++)
            {
                if (!(i == 0 || j == 0 || i == m + 1 || j == n + 1))
                    cin >> a[i][j];
                pre[i][j] = 0;
                pro[i][j] = 0;
            }
        }
        ll ans = -10000000000000;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                pre[i][j] = a[i][j] + pre[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= 1; j--)
            {
                pro[i][j] = a[i][j] + pro[i - 1][j + 1];
            }
        }
        for (int i = 2; i <= min(n, m); i++)
        {
            for (int j = 1; j <= m - i + 1; j++)
            {
                for (int k = 1; k <= n - i + 1; k++)
                {
                    // int x1 = a[j][k];
                    // int x2 = a[j + i-1][k];
                    // int x3 = a[j][k + i-1];
                    // int x4 = a[j + i-1][k + i-1];
                    // ll yy = pre[j + i - 1][k + i - 1] - pre[j - 1][k - 1] + pro[j + i - 1][k] - pro[j - 1][k + i];
                    // cout<<j<<" "<<k<<" "<<yy<<"\n";
                    if (i % 2 == 0)
                    {
                        ans = max(ans, pre[j + i - 1][k + i - 1] - pre[j - 1][k - 1] + pro[j + i - 1][k] - pro[j - 1][k + i]);
                    }
                    else
                    {
                        ans = max(ans, pre[j + i - 1][k + i - 1] - pre[j - 1][k - 1] + pro[j + i - 1][k] - pro[j - 1][k + i] - a[j + i / 2][k + i / 2]);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}