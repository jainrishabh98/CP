#include <bits/stdc++.h>
using namespace std;
int mp[2005];
int main()
{
    int n, m,k,x,y;
    cin >> n >> m >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (x <= k)
        {
            mp[x] = max(mp[x], y);
        }
    }
    vector<int> pref(k + 1);
    pref[0] = 0;
	for (int i = 1; i <= k; ++i) {
		pref[i] = pref[i-1] + a[i-1];
	}
	vector<long long int> dp(k + 1, 1e10);
	dp[0] = 0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i] = min(dp[i],dp[i-j] + pref[i] - pref[i-(j-mp[j])]);
        }
    }
	cout << dp[k] ;
}