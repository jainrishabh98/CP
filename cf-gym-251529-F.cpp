#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll pre[200005];
ll dp[200005][2];
ll f[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <=n; i++)
    {
        cin >> f[i];
        pre[i] = pre[i-1] + f[i];
    }
    if(k+k >= n)
    {
        cout<<pre[n];
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ll lp = pre[i] - pre[max((ll)0,i-k)] + dp[max((ll)0,i-k)][0];
        ll lp1 = pre[i] - pre[max((ll)0,i-k)];
        dp[i][1] = max(dp[i-1][1],lp);
        dp[i][0] = max(dp[i-1][0],lp1);
        // cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
    cout<<max(dp[n][0],dp[n][1]);
}