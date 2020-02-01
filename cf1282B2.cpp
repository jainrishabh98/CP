#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, p, k;
        cin >> n >> p >> k;
        ll a[n+1];
        ll dp[n+1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        a[0] = 0;
        sort(a+1, a + n + 1);
        dp[0] = 0;
        dp[1] = a[1];
        int ans = 0;
        if(dp[1] <= p)
            ans++;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + a[i];
            if (i - k >= 0)
            {
                dp[i] = min(dp[i],dp[i-k] + a[i]);
            }
            if(dp[i] <= p)
                ans = i;
        }
        cout<<ans<<"\n";
    }
}