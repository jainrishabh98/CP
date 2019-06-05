#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m = 1e9 + 7;
ll power(ll x, ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[10];
    ll dp[n + 1][10];
    ll sum = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum > n)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            dp[i][j]=0;
            if (i < a[j])
                continue;
            if (j == 9)
            {
                dp[i][j] = 1;
            }
            else if (j == 0 && a[j] < i)
            {
                ll f = 1, aa = 1, bb = 1;
                for (int kk = 1; kk <= a[j]; kk++)
                {
                    (aa *= (i - 1 - a[j] + kk)) %= m;
                    (bb *= kk) %= m;
                }
                ll tmp = power(bb, m - 2);
                for (int k = a[j]; k <= i - 1; k++)
                {
                    f = (aa * tmp) % m;
                    (dp[i][j] += (dp[i - k][j + 1] * f) % m) %= m;
                    aa = (aa * (i -1 - k)) % m;
                    (bb *= (k+1)) %= m; 
                    tmp = power(bb, m - 2);
                }
            }
            else if (j!=0)
            {
                ll f = 1, aa = 1, bb = 1;
                for (int kk = 1; kk <= a[j]; kk++)
                {
                    (aa *= (i - a[j] + kk)) %= m;
                    (bb *= kk) %= m;
                }
                ll tmp = power(bb, m - 2);
                for (int k = a[j]; k <= i; k++)
                {
                    f = (aa * tmp) % m;
                    (dp[i][j] += (dp[i - k][j + 1] * f) % m) %= m;
                    aa = (aa * (i - k)) % m;
                    (bb *= (k+1)) %= m; 
                    tmp = power(bb, m - 2);
                }
            }
        }
        // cout<<"\n";
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        (ans += dp[i][0])%=m;
    }
    cout << ans;
}