#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]==1) continue;
        for (int k = 2*a[i]; k < 100005; k += a[i])
        {
            v[k].push_back(a[i]);
        }
    }
    int dp[100005] = {0};
    int d[100005] = {0};
    int mx=0;dp[1]=1;
    for (int i = 2; i < 100005; i++)
    {   mx=0;
        for(auto k:v[i])
        {
            mx = max(mx,dp[k]);
        }
        dp[i]=mx+1;
        for(auto k:v[i])
        {
            d[k] = max(d[k],dp[i]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {cout<<dp[a[i]]<<" "<<d[a[i]]<<"\n";ans = max(ans,dp[a[i]]);}
    cout<<ans<<"\n";
    return 0;

}