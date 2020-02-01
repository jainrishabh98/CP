#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100005][11];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll a[n + 1];
    int d = 11;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < d; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[j][i] = a[j];
            if (j - i >= 1)
                dp[j][i] += dp[j - i][i];
        }
    }
    int q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r >> d;
        l = l + ((r - l) % d);
        if (l > r)
            cout << a[r] << "\n";
        else
            cout << dp[r][d] - dp[l][d] + a[l] << "\n";
    }
}