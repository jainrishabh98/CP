#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int dp[1005][1005];
int row[1005];
int col[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    char x;
    int a;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            a = x - '0';
            dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += row[i];
            dp[i][j] += col[j];
            if (a == 1)
            {
                dp[i][j]++;
                row[i]++;
                col[j]++;
            }
        }
    }
    int left = 0, right = 0, up = 0, down = 0, lc = 0, rc = 0, uc = 0, dc = 0;
    while (q--)
    {
        cin >> a;
        if (a == 1)
        {
            int l, r;
            cin >> l >> r;
            if (l < 0)
            {
                rc += abs(l);
                if (rc - lc > 0)
                {
                    right = max(right, (rc - lc));
                }
            }
            else
            {
                lc += l;
                if (lc - rc > 0)
                {
                    left = max(left, (lc - rc));
                }
            }
            if (r < 0)
            {
                dc += abs(r);
                if (dc - uc > 0)
                {
                    down = max(down, (dc - uc));
                }
            }
            else
            {
                uc += r;
                if (uc - dc > 0)
                {
                    up = max(up, (uc - dc));
                }
            }
        }
        else
        {
            int l1 = 1 + left, r1 = n - right, u1 = up + 1, d1 = n - down;
            // cout<<l1<<" "<<r1<<" "<<u1<<" "<<d1<<" ";
            if (l1 > r1 || u1 > d1 || l1>n || r1<0 || u1>n || d1 <0)
                cout << 0 << "\n";
            else
            {
                int cnt = dp[d1][r1] - dp[u1 - 1][r1] - dp[d1][l1 - 1] + dp[u1 - 1][l1 - 1];
                cout << cnt << "\n";
            }
        }
    }
}