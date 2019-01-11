#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int dp[100005]={0};
int d[100005]={0};
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i < 100005; i++)
    {
        for (int k = 2 * i; k < 100005; k += i)
        {
            v[k].push_back(i);
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        d[a[i]]=1;
    dp[1] = 1;int ans = 0;
    for (int i = 0; i < n; i++)
    {   
        mx = 0;
        for (auto k : v[a[i]])
        {
            mx = max(mx, d[k]);
        }
        dp[a[i]] = mx + 1;
        for (auto k : v[a[i]])
        {
            d[k] = dp[a[i]];
        }
        // cout << dp[a[i]] << " ";
        ans = max(ans, dp[a[i]]);
    }
    cout << ans << "\n";
    return 0;
}